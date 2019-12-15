#ifndef _PLANE_H_
#define _PLANE_H_

#include"Imovable.h"

class Plane1:public IMovable
{
	float mTime;
	static map<string, Strategy*> m_MapMoveStrategy;
	Strategy* m_pMoveStrategy;

	static CxImage** mImg;//存储每一桢
	static int mFrame;//帧数
	int mCount;//当前输出第几桢
	map<string, OutputStrategy*> m_MapOutputStrategy;
	Strategy* m_pOutputStrategy;

	string mState;

	float mLastAttack;
public:
	BOOL mAttack;
	BOOL mFind;
	Plane1(int f);
	Plane1(int life, int power, float x, float y, float xv, float yv);
	~Plane1();
	void Init();
	void SetMoveStrategy(const string ID);
	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
	void Bleed(int power);
	BOOL IsAttackOneTime();

	BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);

	static void End();
};
#endif