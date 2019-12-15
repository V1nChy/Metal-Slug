#include"Bullet4.h"

#include"Bullet2.h"


CxImage** Bullet4::mImg = NULL;
int Bullet4::mFrame = 0;
Bullet4::Bullet4(int f)
{
	mFrame = f;
	if (!mImg)
	{
		mImg = new CxImage*[f];

		mImg[0] = new CxImage(L"Bullet4\\1.png", CXIMAGE_FORMAT_PNG);
		mImg[1] = new CxImage(L"Bullet4\\2.png", CXIMAGE_FORMAT_PNG);
		mImg[2] = new CxImage(L"Bullet4\\3.png", CXIMAGE_FORMAT_PNG);
		mImg[3] = new CxImage(L"Bullet4\\4.png", CXIMAGE_FORMAT_PNG);
		mImg[4] = new CxImage(L"Bullet4\\5.png", CXIMAGE_FORMAT_PNG);
		mImg[5] = new CxImage(L"Bullet4\\6.png", CXIMAGE_FORMAT_PNG);
		mImg[6] = new CxImage(L"Bullet4\\7.png", CXIMAGE_FORMAT_PNG);
		mImg[7] = new CxImage(L"Bullet4\\8.png", CXIMAGE_FORMAT_PNG);
		mImg[8] = new CxImage(L"Bullet4\\9.png", CXIMAGE_FORMAT_PNG);
		mImg[9] = new CxImage(L"Bullet4\\10.png", CXIMAGE_FORMAT_PNG);
	}
}
Bullet4::Bullet4(int hp, int power, float x, float y, float xv, float yv, sDirect d) :
IMovable(hp, power, x, y, xv, yv),
p_mS(0),
mCount(0)
{
	OutputStrategy* p1 = new OutputStrategy(0, 4, 0.05);
	m_MapOutputStrategy["∑¢…‰"] = p1;

	OutputStrategy* p2 = new OutputStrategy(4, 5, 0.1);
	m_MapOutputStrategy["∑…––"] = p2;

	OutputStrategy* p3 = new OutputStrategy(5, 10, 0.027);
	m_MapOutputStrategy["±¨’®"] = p3;

	mDirect = d;
	mState = "∑¢…‰";
	p_mS = m_MapOutputStrategy[mState];
	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;
}
Bullet4::~Bullet4()
{
	map<string, OutputStrategy*>::iterator i;
	for (i = m_MapOutputStrategy.begin(); i != m_MapOutputStrategy.end(); i++)
		delete i->second;
}
void Bullet4::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	p_mS = i->second;
}
void Bullet4::Update(float deltaTime, float backgroundMove)
{
	mCount = p_mS->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();

	if (mState=="∑¢…‰" && p_mS->GetIfOnePeriod())
	{
		mState = "∑…––";
		SetOutputStrategy(mState);
	}
	if (mExist.Die)
	{
		mExist.AnimationEnd = p_mS->GetIfOnePeriod();
		return;
	}

	mPos.x += xSpeed * deltaTime * mDirect.x - backgroundMove;
	mPos.y += ySpeed * deltaTime * mDirect.y;
}
void Bullet4::Draw(HDC hdc)
{
	if (mDirect.x == 1)
		Render1(hdc, mPos.x, mPos.y);
	else
		Render2(hdc, mPos.x, mPos.y);
}
void Bullet4::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
}
void Bullet4::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
RECT Bullet4::GetRect()
{
	RECT r;
	r.bottom = mPos.y + mHeight / 2;
	r.left = mPos.x - mWidth / 2;
	r.right = mPos.x ;
	r.top = mPos.y - mHeight / 2;
	return r;
}
void Bullet4::Bleed(int power)
{
	mExist.Die = TRUE;
	mState = "±¨’®";
	SetOutputStrategy(mState);
}

void Bullet4::End()
{
	for (int j = 0; j < mFrame; j++)
		delete mImg[j];
}