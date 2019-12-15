#include"GameFrame.h"
#include"LOGO.h"
#include"Menu.h"
#include"Help.h"
#include"Select.h"
#include"Game.h"
#include<tchar.h>
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdSow)
{
	GameFrame* pGF = GameFrame::GetObject();
	pGF->LoadScene(new LOGOScene, "LOGO场景");
	pGF->LoadScene(new MenuScene, "MENU场景");
	pGF->LoadScene(new HelpScene, "HELP场景");
	pGF->LoadScene(new SelectScene, "SELECT场景");
	pGF->LoadScene(new GameScene, "GAME场景");
	pGF->SetScene("LOGO场景");
	pGF->Run();
	pGF->End();
	return 1;
}