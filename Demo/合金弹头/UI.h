#ifndef _UI_H
#define _UI_H

#include<windows.h>
#include<string>
using namespace std;
class Scene;

class UI
{
public:
	Scene* BelongScene;
	string SceneID;

	int x1, x2, y1, y2;
	BOOL active;
	UI(int X1,int Y1,int X2,int Y2,BOOL Active=FALSE);
	void SetUI(int X1,int Y1,int X2,int Y2);
	void SetActive(BOOL Active);

	virtual void CursorInMove();
	virtual void CursorOutMove();
	virtual void ButtonDown(const string ID);
	virtual void SetSoundSign();
	//输出
	virtual void Render();
	//初始化
	virtual void Init();
	//结束
	virtual void End();
};

#endif