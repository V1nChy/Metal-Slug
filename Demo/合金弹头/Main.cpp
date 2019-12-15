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
	pGF->LoadScene(new LOGOScene, "LOGO����");
	pGF->LoadScene(new MenuScene, "MENU����");
	pGF->LoadScene(new HelpScene, "HELP����");
	pGF->LoadScene(new SelectScene, "SELECT����");
	pGF->LoadScene(new GameScene, "GAME����");
	pGF->SetScene("LOGO����");
	pGF->Run();
	pGF->End();
	return 1;
}