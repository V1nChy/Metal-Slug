#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"Animation.h"
#include<map>
#include<string>
using namespace std;

class Enemy
{
protected:
	float mXpos, mYpos;
	int mHp;
	map<string, Animation*> m_MapAct;
	Animation* m_pAct;
public:
	Enemy(int x,int y,int hp);
	~Enemy();
	BOOL SetAct(const string ID);
	virtual void Init();
	virtual void Enter();
	virtual void Run(HDC hdc);
	virtual void End();
};

class Soldiers1Run :public Animation
{
public:
	Soldiers1Run(int f, float t);
	void Init(const char* DirectName);
	void Render1(HDC hdc, float x, float y);
};

class Soldiers1:public Enemy
{
public:
	Soldiers1(int x, int y, int hp);
	void Init();
	void Run(HDC hdc);
	void End();
};

#endif