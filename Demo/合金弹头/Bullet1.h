#ifndef _BULLET_H_
#define _BULLET_H_

#include "IMovable.h"
#include"ximage.h"

class Bullet1 :public IMovable
{
	static CxImage** mImg;//存储每一桢
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;

	static int mFrame;//帧数
	int mCount;//当前输出第几桢

	string mState;
public:
	Bullet1(int f);//f帧数
	Bullet1(int hp,int power, float x, float y, float xv, float yv, sDirect d);
	~Bullet1();

	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);

	void Bleed(int power);
	void Render1(HDC hdc, float x, float y);//显示
	void Render2(HDC hdc, float x, float y);
	void Render3(HDC hdc, float x, float y);//显示
	void Render4(HDC hdc, float x, float y);

	BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);

	static void End();
};

#endif
