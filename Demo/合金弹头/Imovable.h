#ifndef _IMOVABLE_H_
#define _IMOVABLE_H_

#include"BasicData.h"
#include"Strategy.h"
#include"ximage.h"

class IMovable
{
protected:
	int mHP;		                   //����
	cPOINTF mPos;	                  //����
	sDirect mDirect;                     //����
	int mPower;
	float xSpeed, ySpeed;	
	float mWidth, mHeight;
public:
	sEXIST mExist;	                  //���ڣ����������ã�

	IMovable();
	IMovable(int hp,int power,float x, float y, float xv, float yv);
	virtual ~IMovable();

	virtual void Update(float deltaTime, float backgroundMove);
	virtual void Draw(HDC hdc);
	virtual void SetMoveStrategy(const string ID);
	virtual void SetOutputStrategy(const string ID);
	virtual void Bleed(int power);
	virtual BOOL IsAttackOneTime();
	virtual RECT GetRect();
	int GetHP();
	int GetPower();
	cPOINTF GetPos();
	BOOL GetExist();
	BOOL  CollisionDetect(RECT r);            //�������ε���ײ
};

/*--------------------------------------------------------------------------------*/
class MovableMgr
{
protected:
	float mTime;
	list<IMovable *> mMovableList;
public:
	MovableMgr();
	virtual ~MovableMgr();
	virtual void Enter();
	virtual void Create(IMovable* enemy);
	virtual void Draw(HDC hdc);
	virtual void Update(float deltaTime);

	void ClearAll();
	list<IMovable *> * GetMovableList(){ return &mMovableList; }
	int GetMovableCount() { return mMovableList.size(); }
};

#endif