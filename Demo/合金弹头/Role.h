#ifndef _ROLE_H_
#define _ROLE_H_

#include"Animation.h"
#include"GameInput.h"
#include"BasicData.h"
#include"IMovable.h"

class ActLeftStand :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd, HoldBegin, HoldEnd;
	int UpperCount, LowerCount, HoldCount;
public:
	ActLeftStand(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};
class ActRightStand :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd,HoldBegin,HoldEnd;
	int UpperCount, LowerCount,HoldCount;
public:
	ActRightStand(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd,int hBegin,int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};

class ActLeftRun :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd, HoldBegin, HoldEnd;
	int UpperCount, LowerCount, HoldCount;
public:
	ActLeftRun(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};
class ActRightRun :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd, HoldBegin, HoldEnd;
	int UpperCount, LowerCount, HoldCount;
public:
	ActRightRun(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};

class ActLeftJump :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd, HoldBegin, HoldEnd;
	int UpperCount, LowerCount, HoldCount;
public:
	ActLeftJump(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};
class ActRightJump :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd, HoldBegin, HoldEnd;
	int UpperCount, LowerCount, HoldCount;
public:
	ActRightJump(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};

class ActLeftSquat :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd;
	int UpperCount, LowerCount;
public:
	ActLeftSquat(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};
class ActRightSquat :public Animation
{
	BOOL mCirculation;
	int UpperBegin, LowerBegin, UpperEnd, LowerEnd;
	int UpperCount, LowerCount;
public:
	ActRightSquat(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
};

class ActDie:public Animation
{
	BOOL mOneTime;
public:
	ActDie(int f,float t);
	void Enter();
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
	BOOL GetOneTime();
};

class Role:public IMovable
{
	static Role* role;

	int RoleType;
	string mState;

	map<string, Animation*> m_ActMap;
	Animation* m_pAct;
	GameInput* m_pGameInput;
public:
	Role(int type, int hp, int power, float x, float y, float xv, float yv);
	~Role();

	void Init();
	void Enter();
	void Run(HDC hdc);
	void Quit();
	void Draw(HDC hdc);
	BOOL Move(BOOL go);
	void Move2(float x);
	BOOL SetAct(const string ID);
	RECT GetRect();
	static Role* GetRoleP();
};
#endif