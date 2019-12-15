#include"Soldier2.h"
#include"Role.h"
#include"Scene.h"
#include"BulletMgr.h"
#include"EnemyMgr.h"

map<string, Strategy*> Soldier2::m_MapMoveStrategy;
CxImage** Soldier2::mImg = 0;
int Soldier2::mFrame = 0;
Soldier2::Soldier2(int f)
{
	mFrame = f;
	mImg = new CxImage*[f];
	Init();
}
Soldier2::Soldier2(int life, int power, float x, float y, float xv, float yv) :
IMovable(life, power, x, y, xv, yv),
mTime(0),
mCount(0)
{
	mExist.Die = FALSE;
	mExist.AnimationEnd = FALSE;

	OutputStrategy* p1 = new OutputStrategy(0, 2, 0.3);
	m_MapOutputStrategy["Õ¾Á¢"] = p1;
	OutputStrategy* p2 = new OutputStrategy(2, 7, 0.2);
	m_MapOutputStrategy["ÅÜ"] = p2;
	OutputStrategy* p3 = new OutputStrategy(7, 14, 0.3);
	m_MapOutputStrategy["Õ¾Á¢Éä»÷"] = p3;
	OutputStrategy* p4 = new OutputStrategy(14, 18, 0.2);
	m_MapOutputStrategy["¶×Éä»÷"] = p4;
	OutputStrategy* p5 = new OutputStrategy(18, 29, 0.1);
	m_MapOutputStrategy["ËÀÍö"] = p5;

	mState = "Õ¾Á¢";
	m_pOutputStrategy = m_MapOutputStrategy[mState];
	m_pMoveStrategy = m_MapMoveStrategy[mState];

	mDirect.x = -1;
	mAttack = FALSE;
	mFind = FALSE;
	mSignShoot = FALSE;

	mLastAttack=0;
}
Soldier2::~Soldier2()
{
	map<string, OutputStrategy*>::iterator j;
	for (j = m_MapOutputStrategy.begin(); j != m_MapOutputStrategy.end(); j++)
		delete j->second;
}
void Soldier2::Init()
{
	LoadDirectory("Enemy2");

	if (m_MapMoveStrategy.empty())
	{
		SoldierStrategy1* p1 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["Õ¾Á¢"] = p1;

		SoldierStrategy1* p2 = new SoldierStrategy1(100, 0);
		m_MapMoveStrategy["ÅÜ"] = p2;

		SoldierStrategy1* p3 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["Õ¾Á¢Éä»÷"] = p3;

		SoldierStrategy1* p4 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["¶×Éä»÷"] = p4;

		SoldierStrategy1* p5 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["ËÀÍö"] = p5;
	}
}
void Soldier2::SetMoveStrategy(const string ID)
{
	map<string, Strategy*>::iterator i = m_MapMoveStrategy.find(ID);
	if (i == m_MapMoveStrategy.end())
		return;
	m_pMoveStrategy = i->second;

	SetOutputStrategy(ID);

}
void Soldier2::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	m_pOutputStrategy = i->second;
	m_pOutputStrategy->Enter();
}
void Soldier2::Update(float deltaTime, float backgroundMove)
{
	mCount = m_pOutputStrategy->Update(deltaTime);
	m_pMoveStrategy->Update(mPos.x, mPos.y, mDirect, deltaTime, backgroundMove);

	if (mExist.Die)//ËÀÍöÓÅÏÈ¼¶×î¸ß
	{
		mExist.AnimationEnd = m_pOutputStrategy->GetIfOnePeriod();
		if (mExist.AnimationEnd)
			EnemyMgr::mSoldier2Num--;
		return;
	}
	if (mState == "Õ¾Á¢Éä»÷" && m_pOutputStrategy->GetIfOnePeriod())
	{
		mSignShoot = FALSE;
		mState = "ÅÜ";
		SetMoveStrategy(mState);
		mFind = FALSE;
		mDirect.x = -mDirect.x;
	}
	if (mState == "¶×Éä»÷" && m_pOutputStrategy->GetIfOnePeriod())
	{
		mSignShoot = FALSE;
		mState = "ÅÜ";
		SetMoveStrategy(mState);
		mFind = FALSE;
		mDirect.x = -mDirect.x;
	}


	if (!mSignShoot && mState == "Õ¾Á¢Éä»÷" && mCount == 11)
	{
		mSignShoot = TRUE;
		Scene::sound.play(GUN2);
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet2(1, 1, mPos.x - 60, mPos.y - 25, 400, 0, mDirect));
	}
	if (!mSignShoot && mState == "¶×Éä»÷" && mCount == 14)
	{
		mSignShoot = TRUE;
		Scene::sound.play(GUN2);
		EnemyBulletMgr::GetBulletMgr()->Create(new Bullet2(1, 1, mPos.x - 60, mPos.y - 5, 400, 0, mDirect));
	}

	cPOINTF p = Role::GetRoleP()->GetPos();
	if (mPos.GetDistance(p) < 650 && !mFind  && mTime - mLastAttack > 2)
	{
		mLastAttack = mTime;
		if (rand()%2)
			mState = "Õ¾Á¢Éä»÷";
		else
			mState = "¶×Éä»÷";
		SetMoveStrategy(mState);
		mFind = TRUE;

		if (mPos.x > p.x)
			mDirect.x = -1;
		else
			mDirect.x = 1;
	}
	if (mFind)
	{
		if (mPos.GetDistance(p) > 630)
		{
			mState = "ÅÜ";
			SetMoveStrategy(mState);
			mFind = FALSE;
		}
	}
	else
	{
		if (mTime < 1 && mTime + deltaTime > 1)
		{
			mState = "ÅÜ";
			SetMoveStrategy(mState);
		}
	}

	mTime += deltaTime;

	if (mHeight != 0)
	{
		float height;
		height = mImg[mCount]->GetHeight();
		mPos.y -= (height - mHeight) / 2;
	}
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mPos.x>800)
		mDirect.x = -1;
	if (mPos.x < 0)
		mDirect.x = 1;

	if (mPos.x < -200)
	{
		mExist.AnimationEnd = TRUE;
		mExist.Die = TRUE;
		EnemyMgr::mSoldier2Num--;
	}

}
void Soldier2::Draw(HDC hdc)
{
	if (mDirect.x == -1)
		Render1(hdc, mPos.x, mPos.y);
	else
		Render2(hdc, mPos.x, mPos.y);

}
void Soldier2::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
}
void Soldier2::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
void Soldier2::Bleed(int power)
{
	if (mHP == 0)
		return;
	mHP -= power;
	if (mHP < 0)
		mHP = 0;
	if (mHP == 0)
	{
		mExist.Die = TRUE;
		SetMoveStrategy("ËÀÍö");
		Scene::sound.play(SOLDIERDIE2);
	}

}
RECT Soldier2::GetRect()
{
	RECT r;
	r.bottom = mPos.y + mHeight / 2;
	r.left = mPos.x - mWidth / 4;
	r.right = mPos.x + mWidth / 2;
	r.top = mPos.y - mHeight / 2;
	return r;
}
BOOL Soldier2::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Soldier2::LoadDirectory(const char* DirectName)
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

void Soldier2::End()
{
	map<string, Strategy*>::iterator i;
	for (i = m_MapMoveStrategy.begin(); i != m_MapMoveStrategy.end(); i++)
		delete i->second;

	for (int k = 0; k < mFrame; k++)
		delete mImg[k];
}
/*--------------------------------------------------------------*/