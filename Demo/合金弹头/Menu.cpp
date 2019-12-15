#include"Menu.h"

void MenuScene::Init()
{
	pGF = GameFrame::GetObject();
	mTtime = 0;
	pGF->GetGO()->LoadCximg(L"Img\\游戏开始UP.png", "游戏开始UP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\游戏开始DOWN.png", "游戏开始DOWN.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\游戏帮助UP.png", "游戏帮助UP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\游戏帮助DOWN.png", "游戏帮助DOWN.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\LOGO.png", "LOGO.png", CXIMAGE_FORMAT_PNG);

	LoadUI(new Button(200, 505, 340, 555, "游戏开始DOWN.png", "游戏开始UP.png"), "按钮1", "SELECT场景");
	LoadUI(new Button(460, 505, 600, 555, "游戏帮助DOWN.png", "游戏帮助UP.png"), "按钮2", "HELP场景");
}
void MenuScene::Enter()
{
	mTtime = 0;
	map<string, UI*>::iterator i;
	for (i = m_UI.begin(); i != m_UI.end(); i++)
	{
		i->second->active = FALSE;
	}
}
void MenuScene::Run(float deltaTime)
{
	if (mTtime ==0 )
		sound.play(GAME_HJDT);
	if (mTtime < 0.5 && mTtime + deltaTime> 0.5)
		sound.play(GAME_MAIN);
	mTtime += deltaTime;
	if (mTtime > 64)
	{
		mTtime = 0.1;
	}
	pGF->GetGO()->DrawCximage(400, 300, "LOGO2.png");
}
void MenuScene::Quit()
{
	sound.Stop(GAME_MAIN);
	sound.Stop(GAME_HJDT);
}