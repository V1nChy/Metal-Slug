#include"Background.h"
#include"Role.h"

float Background::mx = 0;
Background::Background(HDC hdc, TCHAR* filename):
mIsEnd(FALSE),
mTime(180)
{
	mImg = new CxImage*[10];

	my = 0;
	mMove = 0;
	CxImage* img = new CxImage(filename,CXIMAGE_FORMAT_PNG);
	bw = img->GetWidth();
	bh = img->GetHeight();

	BackgroundDC1 = CreateCompatibleDC(hdc);
	HBITMAP bm = img->MakeBitmap(BackgroundDC1);
	SelectObject(BackgroundDC1, bm);
	DeleteObject(bm);
	//delete img;

	pGF = GameFrame::GetObject();
	mImg[0] = new CxImage(L"Img\\0.png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Img\\1.png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Img\\2.png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Img\\3.png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Img\\4.png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Img\\5.png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Img\\6.png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Img\\7.png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Img\\8.png", CXIMAGE_FORMAT_PNG);
	mImg[9] = new CxImage(L"Img\\9.png", CXIMAGE_FORMAT_PNG);


	pGF->GetGO()->LoadCximg(L"Img\\interface1.png", "interface1.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\interface2.png", "interface2.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\interface3.png", "interface3.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\对话框.png", "对话框.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\任务完成.png", "任务完成.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\任务失败.png", "任务失败.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\F5重置.png", "F5重置.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\ESC退出.png", "ESC退出.png", CXIMAGE_FORMAT_PNG);
	pGF->GetGO()->LoadCximg(L"Img\\Background2.png", "Background2.png", CXIMAGE_FORMAT_PNG);

}
Background::~Background()
{
	for (int i = 0; i < 10; i++)
		delete mImg[i];
	DeleteDC(BackgroundDC1);
}
void Background::Enter()
{
	mx = 0;
	my = 0;
	mMove = 0;
	mTime = 180;
	mIsEnd = FALSE;
}
BOOL Background::MapMove(float x)
{
	mx += x;
	if (mx > bw - ClientW)
	{
		mx = bw - ClientW;
		mIsEnd = TRUE;
		return FALSE;
	}
	return TRUE;
}
void Background::Update(float deltaTime)
{
	if (mTime == 0)
		return;
	mTime -= deltaTime;
	if (mTime < 0)
		mTime = 0;

}
void Background::Run1(HDC hdc)
{
	BitBlt(hdc, 0, 0, 800, 600, BackgroundDC1, mx, my, SRCCOPY);
	pGF->GetGO()->DrawCximage(150,580,"interface1.png");
	pGF->GetGO()->DrawCximage(650, 580, "interface2.png");
	pGF->GetGO()->DrawCximage(250, 50, "interface3.png");

	int time = (int)mTime;
	mImg[time/100]->Draw(hdc,380, 20);
	mImg[time / 10 %10]->Draw(hdc, 420, 20);
	mImg[time % 10]->Draw(hdc, 460, 20);

}
void Background::Run2(HDC hdc)
{
	Run1(hdc);
	pGF->GetGO()->DrawCximage(400, 300, "对话框.png");
	pGF->GetGO()->DrawCximage(400, 200, "任务失败.png");
	pGF->GetGO()->DrawCximage(300, 370, "F5重置.png");
	pGF->GetGO()->DrawCximage(500, 370, "ESC退出.png");

	if (pGF->GetGI()->mF5)
		pGF->SetScene("GAME场景");

}
void Background::Run3(HDC hdc)
{
	Run1(hdc);
	Role::GetRoleP()->Draw(hdc);
	pGF->GetGO()->DrawCximage(500-mMove, 300, "Background2.png");
	mMove += 8;
}
void Background::Run4(HDC hdc)
{
	Run1(hdc);
	pGF->GetGO()->DrawCximage(400, 300, "对话框.png");
	pGF->GetGO()->DrawCximage(400, 200, "任务完成.png");
	pGF->GetGO()->DrawCximage(300, 370, "F5重置.png");
	pGF->GetGO()->DrawCximage(500, 370, "ESC退出.png");

	if (pGF->GetGI()->mF5)
		pGF->SetScene("GAME场景");
}
BOOL Background::GetIsEnd()
{
	return mIsEnd;
}
BOOL Background::IsFinish(float x)
{
	if (mx + x > bw - 10 || mTime == 0)
		return TRUE;
	return FALSE;
}
float Background::GetPosX()
{
	return mx;
}
