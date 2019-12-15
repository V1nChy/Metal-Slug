#ifndef _TANK_H_
#define _TANK_H_

#include"Imovable.h"

class Tank :public IMovable
{
	float mTime;

	static CxImage** mImg;//�洢ÿһ��
	static int mFrame;//֡��
	int mCount;//��ǰ����ڼ���
	map<string, OutputStrategy*> m_MapOutputStrategy;
	Strategy* m_pOutputStrategy;

	string mState;
	float mLastAttack;
public:
	BOOL mAttack;
	BOOL mFind;
	BOOL mSignShoot;
	Tank(int f);
	Tank(int life, int power, float x, float y, float xv, float yv);
	~Tank();
	void SetOutputStrategy(const string ID);
	void Update(float deltaTime, float backgroundMove);
	void Draw(HDC hdc);
	void Render1(HDC hdc, float x, float y);
	void Render2(HDC hdc, float x, float y);
	void Bleed(int power);

	RECT GetRect();

	static void End();
};
#endif