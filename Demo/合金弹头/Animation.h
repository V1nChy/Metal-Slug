#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include"ximage.h"
#include"Strategy.h"

class Animation
{
protected:
	int mFrame;//帧数
	CxImage **mImg;//存储每一桢

	int mCount;//当前输出到第几桢
	float mTime;//规定每桢间隔时间
	float mDeltaTime;//当前桢间隔时间
public:
	Animation(int f, float t);//f帧数，t桢间间隔时间
	~Animation();
	
	virtual void Init(const char* DirectName);
	virtual void Enter();//数据初始化
	virtual void Render1(HDC hdc, float x, float y);//显示
	virtual void Render2(HDC hdc, float x, float y);
	virtual BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);
	int GetWidth();
	int GetHeight();
	virtual BOOL GetOneTime();
};


#endif