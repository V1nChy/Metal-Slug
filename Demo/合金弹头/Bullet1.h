#ifndef _BULLET_H_
#define _BULLET_H_

#include "IMovable.h"
#include"ximage.h"

class Bullet1 :public IMovable
{
	static CxImage** mImg;//�洢ÿһ��
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;

	static int mFrame;//֡��
	int mCount;//��ǰ����ڼ���

	string mState;
public:
	Bullet1(int f);//f֡��
	Bullet1(int hp,int power, float x, float y, float xv, float yv, sDirect d);
	~Bullet1();

	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);

	void Bleed(int power);
	void Render1(HDC hdc, float x, float y);//��ʾ
	void Render2(HDC hdc, float x, float y);
	void Render3(HDC hdc, float x, float y);//��ʾ
	void Render4(HDC hdc, float x, float y);

	BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);

	static void End();
};

#endif
