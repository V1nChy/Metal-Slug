#ifndef _BULLET3_H_
#define _BULLET3_H_


#include "IMovable.h"
#include"ximage.h"

class Bullet3 :public IMovable
{
	static CxImage** mImg;//存储每一桢
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;

	static int mFrame;//帧数
	int mCount;//当前输出第几桢
public:
	Bullet3(int f);//f帧数 d方向
	Bullet3(int hp, int power, float x, float y, float xv, float yv, sDirect d);
	~Bullet3();

	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);

	void Bleed(int power);

	BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);

	static void End();
};

#endif