#include"Bullet3.h"
#include"Scene.h"

CxImage** Bullet3::mImg = NULL;
int Bullet3::mFrame = 0;
Bullet3::Bullet3(int f)
{
	mFrame = f;
	if (!mImg)
	{
		mImg = new CxImage*[f];
		LoadDirectory("Bullet3");
	}
}
Bullet3::Bullet3(int hp, int power, float x, float y, float xv, float yv, sDirect d) :
IMovable(hp, power, x, y, xv, yv),
p_mS(0),
mCount(0)
{
	mDirect = d;
	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;

	OutputStrategy* p1 = new OutputStrategy(0, 4, 0.2);
	m_MapOutputStrategy["·ÉÐÐ"] = p1;

	OutputStrategy* p2 = new OutputStrategy(4, 19, 0.05);
	m_MapOutputStrategy["±¬Õ¨"] = p2;

	p_mS = m_MapOutputStrategy["·ÉÐÐ"];
}
Bullet3::~Bullet3()
{
	map<string, OutputStrategy*>::iterator i;
	for (i = m_MapOutputStrategy.begin(); i != m_MapOutputStrategy.end(); i++)
		delete i->second;
}
void Bullet3::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	p_mS = i->second;
}
void Bullet3::Update(float deltaTime, float backgroundMove)
{
	mCount = p_mS->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	if (mHeight != 0)
	{
		float height;
		height = mImg[mCount]->GetHeight();
		mPos.y -= (height - mHeight) / 2;
	}
	mHeight = mImg[mCount]->GetHeight();

	if (mExist.Die)
	{
		mExist.AnimationEnd = p_mS->GetIfOnePeriod();
		return;
	}

	mPos.x += xSpeed * deltaTime * mDirect.x - backgroundMove;
	mPos.y += ySpeed * deltaTime * mDirect.y;
	if (mPos.y > 500)
	{
		mPos.y = 500;
		mExist.Die = TRUE;
		SetOutputStrategy("±¬Õ¨");
		Scene::sound.play(BOOM1);
	}
}
void Bullet3::Draw(HDC hdc)
{
	mImg[mCount]->Draw(hdc, mPos.x - mImg[mCount]->GetWidth() / 2, mPos.y - mImg[mCount]->GetHeight()/2);
}
void Bullet3::Bleed(int power)
{
	if (mHP == 0)
		return;

	mHP -= power;
	if (mHP <= 0)
	{
		mHP = 0;
		mExist.Die = TRUE;
		SetOutputStrategy("±¬Õ¨");

		Scene::sound.play(BOOM1);
	}
}

BOOL Bullet3::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Bullet3::LoadDirectory(const char* DirectName)
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

void Bullet3::End()
{
	for (int j = 0; j < mFrame; j++)
		delete mImg[j];
}