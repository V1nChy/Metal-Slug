#include "logo.h"

void LOGOScene::Init()
{
	pGF = GameFrame::GetObject();
	pGF->GetGO()->LoadCximg(L"Img\\LOGO2.png", "LOGO2.png", CXIMAGE_FORMAT_PNG);

	pGF->GetGO()->SetTitleText(L"合金弹头");
	mTime = 0;
	mWidth = 560;
	mHeight = 420;
}
void LOGOScene::Run(float deltaTime)
{
	mWidth+=4;
	mHeight+=4;
	pGF->GetGO()->SetResampl("LOGO.png", mWidth, mHeight);
	pGF->GetGO()->SetLight("LOGO.png",6,0);
	pGF->GetGO()->DrawCximage(400, 300, "LOGO.png");

	mTime += deltaTime;
	if (mTime > 2)
		pGF->SetScene("MENU场景");
}
void LOGOScene::End()
{
}
