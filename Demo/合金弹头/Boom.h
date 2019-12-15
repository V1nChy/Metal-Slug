#ifndef _BOOM_H_
#define _BOOM_H_

#include "IMovable.h"
#include"ximage.h"

class Boom :public IMovable
{
	static CxImage** mImg;
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;
	string mState;

	static int mFrame;
	int mCount;
public:
	Boom(int f);
	Boom(int hp, int power, float x, float y, float xv, float yv, sDirect d);
	~Boom();

	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);
	void Bleed(int power);
	void Render1(HDC hdc, float x, float y);//œ‘ æ
	void Render2(HDC hdc, float x, float y);

	BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);

	static void End();
};

#endif