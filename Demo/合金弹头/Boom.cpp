#include"Boom.h"
#include"Scene.h"

CxImage** Boom::mImg = NULL;
int Boom::mFrame = 0;
Boom::Boom(int f)
{
	mFrame = f;
	if (!mImg)
	{
		mImg = new CxImage*[f];
		LoadDirectory("Boom");
	}
}
Boom::Boom(int hp, int power, float x, float y, float xv, float yv, sDirect d) :
IMovable(hp, power, x, y, xv, yv),
p_mS(0),
mCount(0)
{
	OutputStrategy* p1 = new OutputStrategy(0, 16, 0.04);
	m_MapOutputStrategy["»”’®µØ"] = p1;

	OutputStrategy* p2 = new OutputStrategy(16, 19, 0.04);
	m_MapOutputStrategy["±¨’®1"] = p2;

	OutputStrategy* p3 = new OutputStrategy(19, 31, 0.027);
	m_MapOutputStrategy["±¨’®2"] = p3;

	mDirect = d;
	mState = "»”’®µØ";
	p_mS = m_MapOutputStrategy[mState];

	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;
}
Boom::~Boom()
{
	map<string, OutputStrategy*>::iterator i;
	for (i = m_MapOutputStrategy.begin(); i != m_MapOutputStrategy.end(); i++)
		delete i->second;
}
void Boom::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	p_mS = i->second;
}
void Boom::Update(float deltaTime, float backgroundMove)
{
	mCount = p_mS->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mState == "±¨’®1" && p_mS->GetIfOnePeriod())
	{
		mState = "±¨’®2";
		SetOutputStrategy(mState);
		mExist.Die = TRUE;
		return;
	}

	if (mExist.Die || mHP == 0)
	{
		mExist.AnimationEnd = p_mS->GetIfOnePeriod();
		return;
	}

	ySpeed += 15 * deltaTime * 60;
	mPos.x += xSpeed * deltaTime * mDirect.x - backgroundMove;
	mPos.y += ySpeed * deltaTime;
	if (mPos.y > 530)
	{
		mHP = 0;
		mState = "±¨’®1";
		Scene::sound.play(BOOM1);
		mPos.y = 530;
		SetOutputStrategy(mState);
	}
}
void Boom::Draw(HDC hdc)
{
	if (mDirect.x == 1)
		Render1(hdc, mPos.x, mPos.y);
	else if (mDirect.x == -1)
		Render2(hdc, mPos.x, mPos.y);
}
void Boom::Bleed(int power)
{
	if (mHP == 0)
		return;
	mHP -= power;
	if (mHP <= 0)
	{
		mHP = 0;
		Scene::sound.play(BOOM1);

		mState = "±¨’®1";
		SetOutputStrategy(mState);
	}

}

void Boom::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight());
}
void Boom::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight());
	mImg[mCount]->Mirror();
}


BOOL Boom::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Boom::LoadDirectory(const char* DirectName)
{
	TCHAR tname[260];
	char dir[260];
	strcpy_s(dir, 260, DirectName);
	strcat_s(dir, 260, "\\*");

	int r = 0;

	_finddata_t fd;
	intptr_t fr = _findfirst(dir, &fd);

	if (-1 != fr)
	{
		int go = 0;
		while (!go)
		{
			if ((fd.attrib & _A_SUBDIR))
			{
				if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0)
				{
					strcpy_s(dir, 260, DirectName);
					strcat_s(dir, 260, "\\");
					strcat_s(dir, 260, fd.name);
					r += LoadDirectory(dir);
				}
			}
			else
			{
				strcpy_s(dir, 260, DirectName);
				strcat_s(dir, 260, "\\");
				strcat_s(dir, 260, fd.name);
				mbstowcs(tname, dir, strlen(dir) + 1);
				LoadImage(tname, r);
				r += 1;
			}
			go = _findnext(fr, &fd);
		}
	}

	return r;
}

void Boom::End()
{
	for (int j = 0; j < mFrame; j++)
		delete mImg[j];
}
