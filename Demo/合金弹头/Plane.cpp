#include"Plane.h"
#include"Role.h"
#include"Scene.h"
#include"BulletMgr.h"
#include"EnemyMgr.h"

map<string, Strategy*> Plane1::m_MapMoveStrategy;
CxImage** Plane1::mImg = 0;
int Plane1::mFrame = 0;
Plane1::Plane1(int f)
{
	mFrame = f;
	mImg = new CxImage*[f];
	Init();
}
Plane1::Plane1(int life, int power, float x, float y, float xv, float yv) :
IMovable(life, power, x, y, xv, yv),
mTime(0),
mCount(0)
{
	mExist.Die = FALSE;
	mExist.AnimationEnd = FALSE;

	OutputStrategy* p1 = new OutputStrategy(0, 14, 0.05);
	m_MapOutputStrategy["飞行"] = p1;
	OutputStrategy* p2 = new OutputStrategy(14, 34, 0.05);
	m_MapOutputStrategy["炸毁"] = p2;

	mState = "飞行";
	m_pOutputStrategy = m_MapOutputStrategy[mState];
	m_pMoveStrategy = m_MapMoveStrategy[mState];
	mDirect.x = -1;
	mAttack = FALSE;
	mFind = FALSE;

	mLastAttack = -1;
}
Plane1::~Plane1()
{
	map<string, OutputStrategy*>::iterator j;
	for (j = m_MapOutputStrategy.begin(); j != m_MapOutputStrategy.end(); j++)
		delete j->second;
}
void Plane1::Init()
{
	LoadDirectory("Plane");

	if (m_MapMoveStrategy.empty())
	{
		SoldierStrategy1* p1 = new SoldierStrategy1(150, 0);
		m_MapMoveStrategy["飞行"] = p1;

		SoldierStrategy1* p2 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["炸毁"] = p2;
	}
}
void Plane1::SetMoveStrategy(const string ID)
{
	map<string, Strategy*>::iterator i = m_MapMoveStrategy.find(ID);
	if (i == m_MapMoveStrategy.end())
		return;
	m_pMoveStrategy = i->second;

	SetOutputStrategy(ID);

}
void Plane1::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	m_pOutputStrategy->Quit();
	m_pOutputStrategy = i->second;
}
void Plane1::Update(float deltaTime, float backgroundMove)
{
	mTime += deltaTime;
	m_pMoveStrategy->Update(mPos.x, mPos.y, mDirect, deltaTime, backgroundMove);
	mCount = m_pOutputStrategy->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mState == "飞行" && mCount == 7 && mTime - mLastAttack > 2)
	{
		mLastAttack = mTime;
		Scene::sound.play(GUN4);
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet3(1, 1, mPos.x-10, mPos.y + 60, 0, 200, sDirect{0,1}));
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet3(1, 1, mPos.x, mPos.y + 80, 0, 220, sDirect{ 0, 1 }));
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet3(1, 1, mPos.x - 10, mPos.y + 100, 0, 200, sDirect{ 0, 1 }));
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet3(1, 1, mPos.x, mPos.y + 120, 0, 220, sDirect{ 0, 1 }));
		
	}
	if (mExist.Die)//死亡优先级最高
	{
		mExist.AnimationEnd = m_pOutputStrategy->GetIfOnePeriod();
		if (mExist.AnimationEnd)
			EnemyMgr::mPlaneNum--;
		return;
	}

	if (mPos.x>800)
		mDirect.x = -1;
	if (mPos.x < 0)
		mDirect.x = 1;

}
void Plane1::Draw(HDC hdc)
{
	if (mDirect.x == -1)
		Render1(hdc, mPos.x, mPos.y);
	else
		Render2(hdc, mPos.x, mPos.y);

}
void Plane1::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
}
void Plane1::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
void Plane1::Bleed(int power)
{
	if (mHP == 0)
		return;
	mHP -= power;
	if (mHP < 0)
		mHP = 0;
	if (mHP == 0)
	{
		mExist.Die = TRUE;
		Scene::sound.play(BOOM1);

		mState = "炸毁";
		SetMoveStrategy(mState);
	}
	mAttack = TRUE;

}
BOOL Plane1::IsAttackOneTime()
{
	if (mAttack == TRUE && m_pOutputStrategy->GetIfOnePeriod())
		return TRUE;
	return FALSE;
}
BOOL Plane1::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Plane1::LoadDirectory(const char* DirectName)
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

void Plane1::End()
{
	map<string, Strategy*>::iterator i;
	for (i = m_MapMoveStrategy.begin(); i != m_MapMoveStrategy.end(); i++)
		delete i->second;

	for (int k = 0; k < mFrame; k++)
		delete mImg[k];
}
/*--------------------------------------------------------------*/