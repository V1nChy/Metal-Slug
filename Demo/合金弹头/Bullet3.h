#ifndef _BULLET3_H_
#define _BULLET3_H_


#include "IMovable.h"
#include"ximage.h"

class Bullet3 :public IMovable
{
	static CxImage** mImg;//�洢ÿһ��
	map<string, OutputStrategy*> m_MapOutputStrategy;
	OutputStrategy* p_mS;

	static int mFrame;//֡��
	int mCount;//��ǰ����ڼ���
public:
	Bullet3(int f);//f֡�� d����
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