#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include"BasicData.h"

/*-----------------------���Ի���---------------------------------*/
class Strategy
{
public:
	Strategy();
	~Strategy();

	virtual void Enter();
	virtual int Update();
	virtual int Update(float deltaTime);
	virtual void Update(float &x, float &y,sDirect &d, float deltaTime, float backgroundMove);
	virtual void Quit();
	virtual BOOL GetIfOnePeriod();
};
/*----------------------------------------------------------------------*/


/*-----------------------�������---------------------------*/

class OutputStrategy :public Strategy
{
	BOOL mPeriod;
	float mTime, mDeltaTime;
	int mBegin, mEnd, mCount;
public:
	OutputStrategy(int b, int e, float time);
	void Enter();
	int Update(float deltaTime);
	void Quit();
	BOOL GetIfOnePeriod();
};
/*----------------------------------------------------------------------*/

/*---------------------ʿ��1���ƶ�����----------------------------------*/
class SoldierStrategy1 :public Strategy
{
	float xv, yv;
public:
	SoldierStrategy1(float x, float y);
	void Update(float &x, float &y, sDirect &d , float deltaTime, float backgroundMove);
};

#endif