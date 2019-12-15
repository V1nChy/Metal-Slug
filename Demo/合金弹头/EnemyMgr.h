#ifndef _ENEMY_MGR_H_
#define _ENEMY_MGR_H_

#include "IMovable.h"
#include"Soldier1.h"
#include"Soldier2.h"
#include"Plane.h"
#include"Tank.h"
#include"Role.h"

class EnemyMgr :public MovableMgr
{
	float mDeltaTime;
	static EnemyMgr* m_pEnemyMgr;
public:
	static int mPlaneNum;
	static int mTankNum;
	static int mSoldier1Num;
	static int mSoldier2Num;
	EnemyMgr();
	void Enter();

	void Update(float deltaTime,float backgroundDis);
	void  CollisionDetect(Role* role);
	static EnemyMgr* GetEnemyMgr();
};

#endif