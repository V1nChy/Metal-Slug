#include"Soldier1.h"
#include"Role.h"
#include"Scene.h"
#include"EnemyMgr.h"

map<string, Strategy*> Soldier1::m_MapMoveStrategy;
CxImage** Soldier1::mImg=0;
int Soldier1::mFrame = 0;
Soldier1::Soldier1(int f)
{
	mFrame = f;
	mImg = new CxImage*[f];
	Init();
}
Soldier1::Soldier1(int life, int power,float x, float y, float xv, float yv):
IMovable(life,power, x, y, xv, yv),
mTime(0),
mCount(0)
{
	mExist.Die = FALSE;
	mExist.AnimationEnd = FALSE;

	OutputStrategy* p1 = new OutputStrategy(0, 2, 0.3);
	m_MapOutputStrategy["站立"] = p1;
	OutputStrategy* p2 = new OutputStrategy(2, 12, 0.2);
	m_MapOutputStrategy["跳舞"] = p2;
	OutputStrategy* p3 = new OutputStrategy(12, 15, 0.2);
	m_MapOutputStrategy["吓"] = p3;
	OutputStrategy* p4 = new OutputStrategy(15, 20, 0.15);
	m_MapOutputStrategy["跑"] = p4;
	OutputStrategy* p5 = new OutputStrategy(20, 27, 0.15);
	m_MapOutputStrategy["挥刀"] = p5;
	OutputStrategy* p6 = new OutputStrategy(27, 37, 0.1);
	m_MapOutputStrategy["死亡"] = p6;

	mState = "站立";
	m_pOutputStrategy = m_MapOutputStrategy[mState];
	m_pMoveStrategy = m_MapMoveStrategy[mState];

	mDirect.x = -1;
	mAttack = FALSE;
	mFind = FALSE;
}
Soldier1::~Soldier1()
{
	map<string, OutputStrategy*>::iterator j;
	for (j = m_MapOutputStrategy.begin(); j != m_MapOutputStrategy.end(); j++)
		delete j->second;
}
void Soldier1::Init()
{
	LoadDirectory("Enemy");

	if (m_MapMoveStrategy.empty())
	{
		SoldierStrategy1* p1 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["站立"] = p1;

		SoldierStrategy1* p2 = new SoldierStrategy1(50, 0);
		m_MapMoveStrategy["跳舞"] = p2;

		SoldierStrategy1* p3 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["吓"] = p3;

		SoldierStrategy1* p4 = new SoldierStrategy1(150, 0);
		m_MapMoveStrategy["跑"] = p4;

		SoldierStrategy1* p5 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["挥刀"] = p5;

		SoldierStrategy1* p6 = new SoldierStrategy1(0, 0);
		m_MapMoveStrategy["死亡"] = p6;
	}
}
void Soldier1::SetMoveStrategy(const string ID)
{
	map<string, Strategy*>::iterator i = m_MapMoveStrategy.find(ID);
	if (i == m_MapMoveStrategy.end())
		return;
	m_pMoveStrategy = i->second;

	SetOutputStrategy(ID);

}
void Soldier1::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	m_pOutputStrategy = i->second;
	m_pOutputStrategy->Enter();
}
void Soldier1::Update(float deltaTime, float backgroundMove)
{
	m_pMoveStrategy->Update(mPos.x, mPos.y, mDirect, deltaTime, backgroundMove);
	mCount = m_pOutputStrategy->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mExist.Die)//死亡优先级最高
	{
		mExist.AnimationEnd = m_pOutputStrategy->GetIfOnePeriod();
		if (mExist.AnimationEnd)
			EnemyMgr::mSoldier1Num--;
		return;
	}

	RECT r = Role::GetRoleP()->GetRect();
	cPOINTF p = Role::GetRoleP()->GetPos();

	//攻击（挥刀动作第二优先级）
	if (mState == "挥刀" && m_pOutputStrategy->GetIfOnePeriod())
	{
		mAttack = FALSE;
		mTime = 0;
		mState = "跑";
		SetMoveStrategy(mState);
		if (mPos.x > p.x)
			mDirect.x = -1;
		else
			mDirect.x = 1;
	}
	if (CollisionDetect(r) && !mAttack)
	{
		mAttack = TRUE;
		mState = "挥刀";
		SetMoveStrategy(mState);
		mTime = 0;
		if (mPos.x > p.x)
			mDirect.x = -1;
		else
			mDirect.x = 1;
	}
	if (!mAttack)
	{
		//发现目标第三优先级
		if (mPos.GetDistance(p) < 400 && !mFind)
		{
			mState = "吓";
			SetMoveStrategy(mState);
			mTime = 0;
			mFind = TRUE;
		}
		if (mFind)
		{
			if (mState == "吓" && m_pOutputStrategy->GetIfOnePeriod())
			{
				mState = "跑";
				SetMoveStrategy(mState);
			}
			if (mPos.x > p.x)
				mDirect.x = -1;
			else
				mDirect.x = 1;
		}
		else//         最低优先级
		{
			if (mTime < 2 && mTime + deltaTime > 2)
			{
				SetMoveStrategy("跳舞");
			}
			if (mTime < 5 && mTime + deltaTime > 5)
			{
				mDirect.x = -mDirect.x;
			}
			if (mTime > 8)
			{
				mTime = 0;
				SetMoveStrategy("站立");
			}
		}
	}

	mTime += deltaTime;
	if (mPos.x>800)
		mDirect.x = -1;
	if (mPos.x < 0)
		mDirect.x = 1;

	if (mPos.x < -100)
	{
		mExist.AnimationEnd = TRUE;
		mExist.Die = TRUE;
		EnemyMgr::mSoldier2Num--;
	}

}
void Soldier1::Draw(HDC hdc)
{
	if (mDirect.x==-1)
		Render1(hdc, mPos.x, mPos.y);
	else
		Render2(hdc, mPos.x, mPos.y);

}
void Soldier1::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
}
void Soldier1::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
void Soldier1::Bleed(int power)
{
	if (mHP == 0)
		return;
	mHP -= power;
	if (mHP <= 0)
	{
		mHP = 0;
		mExist.Die = TRUE;
		mState = "死亡";
		SetMoveStrategy(mState);
		Scene::sound.play(SOLDIERDIE1);
	}

	mAttack = TRUE;
}
BOOL Soldier1::IsAttackOneTime()
{
	if (mState == "挥刀" && mCount==26)
		return TRUE;
	return FALSE;
}

BOOL Soldier1::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG);
	return TRUE;
}
int Soldier1::LoadDirectory(const char* DirectName)
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

void Soldier1::End()
{
	map<string, Strategy*>::iterator i;
	for (i = m_MapMoveStrategy.begin(); i != m_MapMoveStrategy.end(); i++)
		delete i->second;

	for (int k = 0; k < mFrame; k++)
		delete mImg[k];
}
/*--------------------------------------------------------------*/