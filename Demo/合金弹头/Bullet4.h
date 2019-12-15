#ifndef _BULLET4_H_
#define _BULLET4_H_

#include "IMovable.h"
#include"ximage.h"

class Bullet4 :public IMovable
{
	static CxImage** mImg;//�洢ÿһ��
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;

	static int mFrame;//֡��
	int mCount;//��ǰ����ڼ���
	string mState;
public:
	Bullet4(int f);//f֡�� d����
	Bullet4(int hp, int power, float x, float y, float xv, float yv, sDirect d);
	~Bullet4();

	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);

	RECT GetRect();
	void Bleed(int power);

	static void End();
};
#endif