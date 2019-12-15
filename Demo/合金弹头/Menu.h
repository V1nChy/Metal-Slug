#ifndef _MENU_H_
#define _MENU_H_
#include"GameFrame.h"
#include"Scene.h"
#include "Button.h"

class MenuScene :public Scene
{
	GameFrame* pGF;
	float mTtime;
public:

	void Init();
	void Enter();
	void Run(float deltaTime);
	void Quit();
};
#endif