#include"Scene.h"

int Scene::SelectRole = 0;
CSoundManage Scene::sound;
void Scene::Loadmusic()
{
	sound.ReadFile(GAME_MAIN, "sound1\\MAIN.mp3", DOSOUND);
	sound.ReadFile(GAME_HJDT, "sound1\\HJDT.wav", DOSOUND);
	sound.ReadFile(GAME_SORT, "sound1\\SORT.mp3", DOSOUND);
	sound.ReadFile(GAME_BACKGROUND, "sound1\\BACKGROUND.mp3", DOSOUND);
	sound.ReadFile(GAME_OK, "sound1\\OK.wav", DOSOUND);
	sound.ReadFile(GAME_BUTTON, "sound1\\BUTTON.wav", DOSOUND);

	sound.ReadFile(GUN0, "sound1\\GUN0.mp3", DOSOUND);
	sound.ReadFile(GUN1, "sound1\\GUN1.mp3", DOSOUND);
	sound.ReadFile(GUN2, "sound1\\GUN2.mp3", DOSOUND);
	sound.ReadFile(GUN3, "sound1\\GUN3.mp3", DOSOUND);
	sound.ReadFile(GUN4, "sound1\\GUN4.mp3", DOSOUND);

	sound.ReadFile(BOOM1, "sound1\\BOOM1.mp3", DOSOUND);

	sound.ReadFile(SOLDIERDIE1, "sound1\\SoldierDie1.wav", DOSOUND);
	sound.ReadFile(SOLDIERDIE2, "sound1\\SoldierDie2.wav", DOSOUND);
	sound.ReadFile(ROLEDIE, "sound1\\RoleDie.wav", DOSOUND);
	
}
Scene::Scene():
m_KeyUI(0)
{}
Scene::~Scene()
{
	map<string, UI*>::iterator i;
	for (i = m_UI.begin(); i != m_UI.end(); i++)
	{
		i->second->End();
		delete i->second;
	}
}

BOOL Scene::LoadUI(UI* pUI, const string ID, const string SceneID)
{
	if (m_UI[ID])
		return FALSE;
	pUI->BelongScene = this;
	pUI->SceneID = SceneID;
	pUI->Init();
	m_UI[ID] = pUI;
}
BOOL Scene::ReleaseUI(const string ID)
{
	map<string, UI*>::iterator i = m_UI.find(ID);
	if (i == m_UI.end())
		return FALSE;
	i->second->End();
	m_UI.erase(i);
	delete i->second;
}
BOOL Scene::SetUI(const string ID)
{
	if (ID.empty())
		m_KeyUI = 0;
	else
	{
		map<string, UI*>::iterator i = m_UI.find(ID);
		if (i == m_UI.end())
			return FALSE;
			m_KeyUI = i->second;
	}
	return TRUE;
}

void Scene::Init(){}
void Scene::Enter(){}
void Scene::Run(float deltaTime){}
void Scene::Quit(){}
void Scene::End(){}