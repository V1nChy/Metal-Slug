#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include"ximage.h"
#include"Strategy.h"

class Animation
{
protected:
	int mFrame;//֡��
	CxImage **mImg;//�洢ÿһ��

	int mCount;//��ǰ������ڼ���
	float mTime;//�涨ÿ����ʱ��
	float mDeltaTime;//��ǰ����ʱ��
public:
	Animation(int f, float t);//f֡����t�����ʱ��
	~Animation();
	
	virtual void Init(const char* DirectName);
	virtual void Enter();//���ݳ�ʼ��
	virtual void Render1(HDC hdc, float x, float y);//��ʾ
	virtual void Render2(HDC hdc, float x, float y);
	virtual BOOL LoadImage(const TCHAR* filename, int n);
	int LoadDirectory(const char* DirectName);
	int GetWidth();
	int GetHeight();
	virtual BOOL GetOneTime();
};


#endif