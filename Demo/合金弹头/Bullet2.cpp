#include"Bullet2.h"


CxImage** Bullet2::mImg = NULL;
int Bullet2::mFrame = 0;
Bullet2::Bullet2(int f)
{
	mFrame = f;
	if (!mImg)
	{
		mImg = new CxImage*[f];
		LoadDirectory("Bullet2");
	}
}
Bullet2::Bullet2(int hp, int power, float x, float y, float xv, float yv, sDirect d) :
IMovable(hp, power, x, y, xv, yv),
p_mS(0),
mCount(0)
{
	OutputStrategy* p1 = new OutputStrategy(7, 13, 0.027);
	m_MapOutputStrategy["∑¢…‰"] = p1;

	OutputStrategy* p2 = new OutputStrategy(0, 2, 0.3);
	m_MapOutputStrategy["∑…––"] = p2;

	OutputStrategy* p3 = new OutputStrategy(2, 7, 0.027);
	m_MapOutputStrategy["±¨’®"] = p3;

	mDirect = d;
	mState = "∑¢…‰";
	p_mS = m_MapOutputStrategy[mState];
	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;
}
Bullet2::~Bullet2()
{
	map<string, OutputStrategy*>::iterator i;
	for (i = m_MapOutputStrategy.begin(); i != m_MapOutputStrategy.end(); i++)
		delete i->second;
}
void Bullet2::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	p_mS = i->second;
}
void Bullet2::Update(float deltaTime, float backgroundMove)
{
	mCount = p_mS->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mState == "∑¢…‰" && p_mS->GetIfOnePeriod())
	{
		mState = "∑…––";
		SetOutputStrategy(mState);
	}

	if (mExist.Die)
	{
		mExist.AnimationEnd = p_mS->GetIfOnePeriod();
		return;
	}

	mPos.x += xSpeed * deltaTime * mDirect.x - backgroundMove;
	mPos.y += ySpeed * deltaTime * mDirect.y;
}
void Bullet2::Draw(HDC hdc)
{
	mImg[mCount]->Draw(hdc, mPos.x - mImg[mCount]->GetWidth() / 2, mPos.y - mImg[mCount]->GetHeight() / 2);
}
void Bullet2::Bleed(int power)
{
	mExist.Die = TRUE;
	mState = "±¨’®";
	SetOutputStrategy(mState);
}

BOOL Bullet2::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Bullet2::LoadDirectory(const char* DirectName)
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

void Bullet2::End()
{
	for (int j = 0; j < mFrame; j++)
		delete mImg[j];
}