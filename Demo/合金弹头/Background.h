#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include"GameFrame.h"
#include"Basicdata.h"

class Background
{
	GameFrame* pGF;
	float my;
	static float mx;
	int bw, bh;
	HDC BackgroundDC1;
	BOOL mIsEnd;
	float mTime;

	float mMove;
	CxImage** mImg;
public:
	Background(HDC hdc,TCHAR* filename);
	~Background();
	void Enter();

	BOOL MapMove(float x);

	void Update(float deltaTime);
	void Run1(HDC hdc);
	void Run2(HDC hdc);
	void Run3(HDC hdc);
	void Run4(HDC hdc);
	BOOL GetIsEnd();
	BOOL IsFinish(float x);
	static float GetPosX();
};

#endif