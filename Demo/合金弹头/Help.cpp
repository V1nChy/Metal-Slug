#include"Help.h"

void HelpScene::Init()
{
	pGF = GameFrame::GetObject();
	pGF->GetGO()->LoadCximg(L"Img\\HELP.png", "HELP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\返回UP.png", "返回UP.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\返回DOWN.png", "返回DOWN.png", CXIMAGE_FORMAT_PNG);
	LoadUI(new Button(560, 500, 700, 550, "返回DOWN.png", "返回UP.png"), "按钮1", "MENU场景");

}
void HelpScene::Enter()
{
	map<string, UI*>::iterator i;
	for (i = m_UI.begin(); i != m_UI.end(); i++)
	{
		i->second->active = FALSE;
	}
}
void HelpScene::Run(float deltaTime)
{
	pGF->GetGO()->DrawCximage(400,300,"HELP.png");
}
void HelpScene::Quit()
{
}