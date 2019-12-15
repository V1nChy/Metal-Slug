#include "IMovable.h"

IMovable::IMovable(int hp, int power,float x, float y, float xv, float yv) :
mWidth(0),
mHeight(0),
mPower(power)
{
	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;

	mHP = hp;

	mPos.x = x;
	mPos.y = y;
	mPos.angle = 0;
	
	mDirect.x = 0;
	mDirect.y = 0;

	xSpeed = xv;
	ySpeed = yv;
}

IMovable::IMovable(void){}

IMovable::~IMovable(void){}

void IMovable::Update(float deltaTime, float backgroundMove){}

void IMovable::Draw(HDC hdc){}

void IMovable::SetMoveStrategy(const string ID){}

void IMovable::SetOutputStrategy(const string ID){}

int IMovable::GetHP()
{
	return mHP;
}

int IMovable::GetPower()
{
	return mPower;
}

RECT IMovable::GetRect()
{
	RECT r;
	r.bottom = mPos.y + mHeight / 2;
	r.left = mPos.x - mWidth / 2;
	r.right = mPos.x + mWidth / 2;
	r.top = mPos.y - mHeight / 2;
	return r;
}

BOOL IMovable::GetExist()
{
	if (mExist.AnimationEnd && mExist.Die)
		return TRUE;
	return FALSE;
}

cPOINTF IMovable::GetPos()
{
	return mPos;
}

BOOL IMovable::CollisionDetect(RECT r)
{
	RECT dst;
	return IntersectRect(&dst, &GetRect(), &r);
}

void IMovable::Bleed(int power)
{
	if (mHP == 0)
		return;

	mHP -= power;
	if (mHP < 0)
		mHP = 0;
}

BOOL IMovable::IsAttackOneTime()
{
	return FALSE;
}


/*--------------------------------------------------------------------------------*/
MovableMgr::MovableMgr(void)
{
	mTime = 0;
}

MovableMgr::~MovableMgr(void)
{

}

void MovableMgr::Enter()
{
	mTime = 0;
}

void MovableMgr::Create(IMovable* enemy)
{
	mMovableList.push_back(enemy);
}

void MovableMgr::Draw(HDC hdc)
{
	list<IMovable *>::iterator i;
	for (i = mMovableList.begin(); i != mMovableList.end(); i++)
		(*i)->Draw(hdc);
}

void MovableMgr::ClearAll()
{
	list<IMovable *>::iterator itr = mMovableList.begin(), end = mMovableList.end();
	while (itr != end)
	{
		delete (*itr++);
	}
	mMovableList.clear();
}

void MovableMgr::Update(float deltaTime){}

