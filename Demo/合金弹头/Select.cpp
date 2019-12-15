#include"Select.h"

Button1::Button1(int X1, int Y1, int X2, int Y2, const string In, const string Out) :
Button(X1, Y1, X2, Y2, In, Out)
{
}
void Button1::ButtonDown(const string ID)
{
	Scene::sound.play(GAME_OK);
	if (ID == "按钮1")
		Scene::SelectRole = 1;
	else if (ID == "按钮2")
		Scene::SelectRole = 2;

	SelectScene::mEnd = TRUE;
}
void Button1::Render()
{
	if (active)
	{
		GameFrame::GetObject()->GetGO()->DrawCximage((x2 + x1) / 2, (y2 + y1) / 2, m_InImg);
		GameFrame::GetObject()->GetGO()->DrawCximage((x2 + x1) / 2, (y2 + y1) / 2, "弹头");
	}
}

int SelectScene::mEnd=FALSE;
void SelectScene::Init()
{
	pGF = GameFrame::GetObject();
	mTime = 0;
	mEndTime = 2;
	pGF->GetGO()->LoadCximg(L"Img\\SELECT.png", "SELECT.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\SHADOW.png", "SHADOW.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\弹头.png", "弹头", CXIMAGE_FORMAT_PNG);
	LoadUI(new Button1(80, 160, 360, 510, "SHADOW.png", ""), "按钮1", "GAME场景");
	LoadUI(new Button1(450, 160, 730, 510, "SHADOW.png", ""), "按钮2", "GAME场景");
}
void SelectScene::Enter()
{
	mTime = 0;
	mEndTime = 2;
	map<string, UI*>::iterator i;
	for (i = m_UI.begin(); i != m_UI.end(); i++)
	{
		i->second->active = FALSE;
	}
}
void SelectScene::Run(float deltaTime)
{
	if (mTime == 0)
		sound.play(GAME_SORT);
	mTime += deltaTime;
	if (mTime > 24)
		mTime = 0;

	pGF->GetGO()->DrawCximage(400, 300, "SELECT.png");

	if (mEnd)
	{
		mEndTime -= deltaTime;
	}
	if (mEndTime < 0)
	{
		pGF->SetScene("GAME场景");
	}
}
void SelectScene::Quit()
{
	sound.Stop(GAME_SORT);
}