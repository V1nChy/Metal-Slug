#ifndef _GAME_H_
#define _GAME_H_

#include"GameFrame.h"
#include"Scene.h"
#include"Role.h"
#include"Background.h"
#include"EnemyMgr.h"
#include"BulletMgr.h"

class GameScene :public Scene
{
	GameFrame* pGF;
	HDC m_hDC;

	Role* role;
	EnemyMgr* mEnemyMgr;
	RoleBulletMgr* mRoleBulletMgr;
	EnemyBulletMgr* mEnemyBulletMgr;
	Background* mBackG;

	float mTime;
public:
	~GameScene();
	void Init();
	void Enter();
	void Run(float deltaTime);
	void Quit();
	void End();
};

#endif