#include"EnemyMgr.h"
#include"time.h"
#include"Background.h"

int EnemyMgr::mPlaneNum = 0;
int EnemyMgr::mTankNum = 0;
int EnemyMgr::mSoldier1Num = 0;
int EnemyMgr::mSoldier2Num = 0;

EnemyMgr* EnemyMgr::m_pEnemyMgr = 0;
EnemyMgr::EnemyMgr()
{
	mDeltaTime = 0;
	m_pEnemyMgr = this;
	new Soldier1(38);
	new Soldier2(29);
	new Plane1(34);
	new Tank(32);
}
void EnemyMgr::Enter()
{
	mTime = 0;
	mPlaneNum=0;
	mTankNum=0;
	mSoldier1Num=0;
	mSoldier2Num=0;
}
void EnemyMgr::Update(float deltaTime,float backgroundDis)
{
	srand(time(NULL));
	mTime += deltaTime;
	mDeltaTime += deltaTime;
	list<IMovable *>::iterator i;
	for (i = mMovableList.begin(); i != mMovableList.end(); i++)
		(*i)->Update(deltaTime, backgroundDis);

	if (Background::GetPosX() > 500 && mTankNum < TANKMAX)
	{
		mTankNum++;
		Create(new Tank(100, 1, 800, 480, 20, 0));
	}
	if (Background::GetPosX() > 1500 && mTankNum < TANKMAX+1)
	{
		mTankNum++;
		Create(new Tank(100, 1, 800, 480, 20, 0));
	}
	if (Background::GetPosX() > 3170 && mPlaneNum < PLANEMAX)
	{
		mPlaneNum++;
		Create(new Plane1(50, 1, 800, 130, 0, 0));
	}
	if (Background::GetPosX() > 3570 && mPlaneNum < PLANEMAX+1)
	{
		mPlaneNum++;
		Create(new Plane1(50, 1, 800, 130, 0, 0));
	}
	if (mSoldier1Num < SOLDIER1MAX)
	{
		mSoldier1Num++;
		Create(new Soldier1(1, 1, 800 + rand() % 30, 490, 0, 0));
	}
	if (mSoldier2Num < SOLDIER2MAX)
	{
		mSoldier2Num++;
		Create(new Soldier2(1, 1, 800 + rand() % 30, 490, 0, 0));
	}

}
void  EnemyMgr::CollisionDetect(Role* role)
{
	RECT rRole = role->GetRect();
	list<IMovable *>::iterator itr1 = mMovableList.begin(), end1 = mMovableList.end(), temp1;
	while (itr1 != end1)
	{
		RECT r;
		temp1 = itr1++;
		if ((*temp1)->GetExist())
		{
			delete (*temp1);
			mMovableList.erase(temp1);
		}
		else if ((*temp1)->mExist.Die == FALSE && IntersectRect(&r, &rRole, &(*temp1)->GetRect()))
		{

			if ((*temp1)->IsAttackOneTime())
			{
				role->Bleed((*temp1)->GetPower());
			}
		}
		
	}
}
EnemyMgr* EnemyMgr::GetEnemyMgr()
{
	if (!m_pEnemyMgr)
		m_pEnemyMgr = new EnemyMgr;
	return m_pEnemyMgr;
}