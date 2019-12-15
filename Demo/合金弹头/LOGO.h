#ifndef _LOGO_H_
#define _LOGO_H_

#include "Scene.h"
#include "GameFrame.h"

class LOGOScene : public Scene
{
	GameFrame* pGF;
	float mTime;
	int mWidth, mHeight;
public:
	void Init();
	void End();
	void Run(float deltaTime);
};
#endif