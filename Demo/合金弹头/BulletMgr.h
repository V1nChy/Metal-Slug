#ifndef _BULLET_MGR_
#define _BULLET_MGR_

#include"IMovable.h"
#include"Boom.h"
#include"Bullet1.h"
#include"Bullet2.h"
#include"Bullet3.h"
#include"Bullet4.h"

class RoleBulletMgr :public MovableMgr
{
	static RoleBulletMgr* m_pBulletMgr;
public:
	RoleBulletMgr();
	void Update(float deltaTime, float backgroundDis);
	void CollisionDetect(list<IMovable *> *el);
	static RoleBulletMgr* GetBulletMgr();
};



class EnemyBulletMgr :public MovableMgr
{
	static EnemyBulletMgr* m_pBulletMgr;
public:
	EnemyBulletMgr();
	void Update(float deltaTime, float backgroundDis);
	void CollisionDetect(IMovable* p);
	static EnemyBulletMgr* GetBulletMgr();
};


#endif