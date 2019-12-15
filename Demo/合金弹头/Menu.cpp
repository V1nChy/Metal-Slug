#include"Menu.h"

void MenuScene::Init()
{
	pGF = GameFrame::GetObject();
	mTtime = 0;
	pGF->GetGO()->LoadCximg(L"Img\\��Ϸ��ʼUP.png", "��Ϸ��ʼUP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\��Ϸ��ʼDOWN.png", "��Ϸ��ʼDOWN.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\��Ϸ����UP.png", "��Ϸ����UP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\��Ϸ����DOWN.png", "��Ϸ����DOWN.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\LOGO.png", "LOGO.png", CXIMAGE_FORMAT_PNG);

	LoadUI(new Button(200, 505, 340, 555, "��Ϸ��ʼDOWN.png", "��Ϸ��ʼUP.png"), "��ť1", "SELECT����");
	LoadUI(new Button(460, 505, 600, 555, "��Ϸ����DOWN.png", "��Ϸ����UP.png"), "��ť2", "HELP����");
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