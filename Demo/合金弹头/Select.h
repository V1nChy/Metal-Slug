#ifndef _SELECT_H_
#define _SELECT_H_

#include"GameFrame.h"
#include"Scene.h"
#include"Button.h"

class Button1 :public Button
{
public:
	Button1(int X1, int Y1, int X2, int Y2, const string In, const string Out);
	void ButtonDown(const string ID);
	void Render();
};
class SelectScene :public Scene
{
	GameFrame* pGF;
	float mTime;
	float mEndTime;
public:
	static BOOL mEnd;
	void Init();
	void Enter();
	void Run(float deltaTime);
	void Quit();
};

#endif