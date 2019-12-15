#include"Strategy.h"

/*--------------------------策略基类-------------------------------------*/
Strategy::Strategy()
{
}
Strategy::~Strategy()
{}
int Strategy::Update()
{
	return 0;
}
int Strategy::Update(float deltaTime)
{
	return 0;
}
void Strategy::Update(float &x, float &y, sDirect &d, float deltaTime, float backgroundMove)
{}
void Strategy::Enter()
{}
void Strategy::Quit()
{}
BOOL Strategy::GetIfOnePeriod()
{
	return 0;
}
/*----------------------------------------------------------------------*/


/*-----------------------输出策略---------------------------*/
OutputStrategy::OutputStrategy(int b, int e, float time) :
Strategy(),
mBegin(b),
mEnd(e),
mCount(0),
mTime(time),
mDeltaTime(0),
mPeriod(FALSE)
{}
void OutputStrategy::Enter()
{
	mPeriod = FALSE;
	mCount = 0;
	mDeltaTime = 0;
}
int OutputStrategy::Update(float deltaTime)
{
	mPeriod = FALSE;
	mDeltaTime += deltaTime;
	if (mDeltaTime > mTime)
	{
		mDeltaTime -= mTime;
		mCount++;
		if (mBegin + mCount == mEnd)
		{
			mPeriod = TRUE;
			mCount = 0;
		}
	}
	return mBegin + mCount;
}
void OutputStrategy::Quit()
{
}
BOOL OutputStrategy::GetIfOnePeriod()
{
	return mPeriod;
}
/*----------------------------------------------------------------------*/



/*---------------------士兵1的移动策略----------------------------------*/
SoldierStrategy1::SoldierStrategy1(float x, float y) :
Strategy(),
xv(x),
yv(y)
{
}
void SoldierStrategy1::Update(float &x, float &y,sDirect &d, float deltaTime,float backgroundMove)
{
	x += d.x * xv * deltaTime - backgroundMove;
	y += d.y * yv * deltaTime;
}

/*----------------------------------------------------------------------*/