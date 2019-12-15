#ifndef _SCENE_H_
#define _SCENE_H_
#include <string>
#include <map>
#include"sound\\SoundManage.h"
#include"Basicdata.h"
#include "UI.h"
class Scene
{
public:
	map<string, UI*> m_UI;
	UI* m_KeyUI;

	static int SelectRole;
	static CSoundManage sound;
	static void Loadmusic();
	Scene();
	virtual ~Scene();

	BOOL LoadUI(UI* pUI,const string ID,const string SceneID);
	BOOL ReleaseUI(const string ID);
	BOOL SetUI(const string ID);

	virtual void Init();
	virtual void Enter();
	virtual void Run(float deltaTime);
	virtual void Quit();
	virtual void End();
};
#endif