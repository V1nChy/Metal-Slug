#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#define ClientW 800
#define ClientH 600

#include<windows.h>
#include"GameOutput.h"
#include"GameInput.h"
#include"Scene.h"
#include<map>
#include<tchar.h>
#include<string>
using namespace std;

class GameFrame
{
private:
	//������
	static GameFrame* m_pGameFrame;
	static LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);

	WNDCLASS m_WndClass;
	HWND m_hWnd;

	//�����������
	GameOutput* m_pGameOutput;
	GameInput* m_pGameInput;
	map<string, Scene*> m_Scene;
	Scene* m_pScene;
	POINT m_Mouse;

	// ��ʱ�䡢֡�ʵ���صı���
	LARGE_INTEGER mFrequency;
	LARGE_INTEGER mStartCount;
	float mFPS;		// ֡��
	static float deltaTime; //��֡���ʱ��
	BOOL mbIsRun;

	GameFrame();

public:
	//������
	~GameFrame();
	static GameFrame* GetObject();
	void Run();
	void End();
	BOOL Frame();

	//�������
	BOOL LoadScene(Scene* pScene, const string ID);
	BOOL ReleaseScene(const string ID);
	BOOL SetScene(const string ID);
	Scene* GetScene(const string ID);

	GameOutput* GetGO();
	GameInput* GetGI();
	BOOL GetIsRun();
	static float GetDeltaTime();
};
#endif