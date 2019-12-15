#ifndef _HELP_H_
#define _HELP_H_
#include"GameFrame.h"
#include"Scene.h"
#include "Button.h"

class HelpScene :public Scene
{
	GameFrame* pGF;
public:

	void Init();
	void Enter();
	void Run(float deltaTime);
	void Quit();
};
#endif