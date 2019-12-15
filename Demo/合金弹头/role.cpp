#include"Role.h"
#include"BulletMgr.h"
#include"GameFrame.h"

ActLeftStand::ActLeftStand(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd):
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (8).png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Role\\ROLE (9).png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Role\\ROLE (10).png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Role\\ROLE (182).png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);
}
void ActLeftStand::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActLeftStand::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth()/2, y - mImg[UpperBegin + UpperCount]->GetHeight()+5);

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActLeftStand::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2, y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActRightStand::ActRightStand(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (8).png", CXIMAGE_FORMAT_PNG);
	mImg[0]->Mirror();
	mImg[1] = new CxImage(L"Role\\ROLE (9).png", CXIMAGE_FORMAT_PNG);
	mImg[1]->Mirror();
	mImg[2] = new CxImage(L"Role\\ROLE (10).png", CXIMAGE_FORMAT_PNG);
	mImg[2]->Mirror();
	mImg[3] = new CxImage(L"Role\\ROLE (182).png", CXIMAGE_FORMAT_PNG);
	mImg[3]->Mirror();
	mImg[4] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[4]->Mirror();
	mImg[5] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);
	mImg[5]->Mirror();
}
void ActRightStand::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActRightStand::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight()+5);

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActRightStand::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2 , y);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2, y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActLeftRun::ActLeftRun(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (26).png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Role\\ROLE (27).png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Role\\ROLE (28).png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Role\\ROLE (29).png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Role\\ROLE (30).png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Role\\ROLE (31).png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Role\\ROLE (32).png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Role\\ROLE (33).png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Role\\ROLE (183).png", CXIMAGE_FORMAT_PNG);
	mImg[9] = new CxImage(L"Role\\ROLE (184).png", CXIMAGE_FORMAT_PNG);
	mImg[10] = new CxImage(L"Role\\ROLE (185).png", CXIMAGE_FORMAT_PNG);
	mImg[11] = new CxImage(L"Role\\ROLE (186).png", CXIMAGE_FORMAT_PNG);
	mImg[12] = new CxImage(L"Role\\ROLE (187).png", CXIMAGE_FORMAT_PNG);
	mImg[13] = new CxImage(L"Role\\ROLE (188).png", CXIMAGE_FORMAT_PNG);
	mImg[14] = new CxImage(L"Role\\ROLE (189).png", CXIMAGE_FORMAT_PNG);
	mImg[15] = new CxImage(L"Role\\ROLE (190).png", CXIMAGE_FORMAT_PNG);
	mImg[16] = new CxImage(L"Role\\ROLE (191).png", CXIMAGE_FORMAT_PNG);
	mImg[17] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[18] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);

}
void ActLeftRun::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActLeftRun::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y-5);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActLeftRun::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2, y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActRightRun::ActRightRun(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (26).png", CXIMAGE_FORMAT_PNG);
	mImg[0]->Mirror();
	mImg[1] = new CxImage(L"Role\\ROLE (27).png", CXIMAGE_FORMAT_PNG);
	mImg[1]->Mirror();
	mImg[2] = new CxImage(L"Role\\ROLE (28).png", CXIMAGE_FORMAT_PNG);
	mImg[2]->Mirror();
	mImg[3] = new CxImage(L"Role\\ROLE (29).png", CXIMAGE_FORMAT_PNG);
	mImg[3]->Mirror();
	mImg[4] = new CxImage(L"Role\\ROLE (30).png", CXIMAGE_FORMAT_PNG);
	mImg[4]->Mirror();
	mImg[5] = new CxImage(L"Role\\ROLE (31).png", CXIMAGE_FORMAT_PNG);
	mImg[5]->Mirror();
	mImg[6] = new CxImage(L"Role\\ROLE (32).png", CXIMAGE_FORMAT_PNG);
	mImg[6]->Mirror();
	mImg[7] = new CxImage(L"Role\\ROLE (33).png", CXIMAGE_FORMAT_PNG);
	mImg[7]->Mirror();
	mImg[8] = new CxImage(L"Role\\ROLE (183).png", CXIMAGE_FORMAT_PNG);
	mImg[8]->Mirror();
	mImg[9] = new CxImage(L"Role\\ROLE (184).png", CXIMAGE_FORMAT_PNG);
	mImg[9]->Mirror();
	mImg[10] = new CxImage(L"Role\\ROLE (185).png", CXIMAGE_FORMAT_PNG);
	mImg[10]->Mirror();
	mImg[11] = new CxImage(L"Role\\ROLE (186).png", CXIMAGE_FORMAT_PNG);
	mImg[11]->Mirror();
	mImg[12] = new CxImage(L"Role\\ROLE (187).png", CXIMAGE_FORMAT_PNG);
	mImg[12]->Mirror();
	mImg[13] = new CxImage(L"Role\\ROLE (188).png", CXIMAGE_FORMAT_PNG);
	mImg[13]->Mirror();
	mImg[14] = new CxImage(L"Role\\ROLE (189).png", CXIMAGE_FORMAT_PNG);
	mImg[14]->Mirror();
	mImg[15] = new CxImage(L"Role\\ROLE (190).png", CXIMAGE_FORMAT_PNG);
	mImg[15]->Mirror();
	mImg[16] = new CxImage(L"Role\\ROLE (191).png", CXIMAGE_FORMAT_PNG);
	mImg[16]->Mirror();
	mImg[17] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[17]->Mirror();
	mImg[18] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);
	mImg[18]->Mirror();
}
void ActRightRun::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActRightRun::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y-5);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActRightRun::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2, y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActLeftJump::ActLeftJump(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (39).png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Role\\ROLE (40).png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Role\\ROLE (41).png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Role\\ROLE (42).png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Role\\ROLE (43).png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Role\\ROLE (198).png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Role\\ROLE (1).png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Role\\ROLE (2).png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Role\\ROLE (3).png", CXIMAGE_FORMAT_PNG);
	mImg[9] = new CxImage(L"Role\\ROLE (4).png", CXIMAGE_FORMAT_PNG);
	mImg[10] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[11] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);


}
void ActLeftJump::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActLeftJump::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y-10);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActLeftJump::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2 , y-5);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2 , y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActRightJump::ActRightJump(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd, int hBegin, int hEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
HoldBegin(hBegin),
HoldEnd(hEnd),
UpperCount(0),
LowerCount(0),
HoldCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (39).png", CXIMAGE_FORMAT_PNG);
	mImg[0]->Mirror();
	mImg[1] = new CxImage(L"Role\\ROLE (40).png", CXIMAGE_FORMAT_PNG);
	mImg[1]->Mirror();
	mImg[2] = new CxImage(L"Role\\ROLE (41).png", CXIMAGE_FORMAT_PNG);
	mImg[2]->Mirror();
	mImg[3] = new CxImage(L"Role\\ROLE (42).png", CXIMAGE_FORMAT_PNG);
	mImg[3]->Mirror();
	mImg[4] = new CxImage(L"Role\\ROLE (43).png", CXIMAGE_FORMAT_PNG);
	mImg[4]->Mirror();
	mImg[5] = new CxImage(L"Role\\ROLE (198).png", CXIMAGE_FORMAT_PNG);
	mImg[5]->Mirror();
	mImg[6] = new CxImage(L"Role\\ROLE (1).png", CXIMAGE_FORMAT_PNG);
	mImg[6]->Mirror();
	mImg[7] = new CxImage(L"Role\\ROLE (2).png", CXIMAGE_FORMAT_PNG);
	mImg[7]->Mirror();
	mImg[8] = new CxImage(L"Role\\ROLE (3).png", CXIMAGE_FORMAT_PNG);
	mImg[8]->Mirror();
	mImg[9] = new CxImage(L"Role\\ROLE (4).png", CXIMAGE_FORMAT_PNG);
	mImg[9]->Mirror();
	mImg[10] = new CxImage(L"Role\\ROLE (125).png", CXIMAGE_FORMAT_PNG);
	mImg[10]->Mirror();
	mImg[11] = new CxImage(L"Role\\ROLE (126).png", CXIMAGE_FORMAT_PNG);
	mImg[11]->Mirror();
}
void ActRightJump::Enter()
{
	UpperCount = LowerCount = HoldCount = 0;
}
void ActRightJump::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y-10);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActRightJump::Render2(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2 , y-5);
	mImg[HoldBegin + HoldCount]->Draw(hdc, x - mImg[HoldBegin + HoldCount]->GetWidth() / 2 , y - mImg[HoldBegin + HoldCount]->GetHeight());

	if (mDeltaTime >= mTime)
	{
		HoldCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (HoldBegin + HoldCount == HoldEnd)
		HoldCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}

ActLeftSquat::ActLeftSquat(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
UpperCount(0),
LowerCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (54).png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Role\\ROLE (55).png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Role\\ROLE (56).png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Role\\ROLE (57).png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Role\\ROLE (192).png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Role\\ROLE (193).png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Role\\ROLE (194).png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Role\\ROLE (195).png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Role\\ROLE (196).png", CXIMAGE_FORMAT_PNG);

}
void ActLeftSquat::Enter()
{
	UpperCount = LowerCount = 0;
}
void ActLeftSquat::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2, y);
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight()+25);

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActLeftSquat::Render2(HDC hdc, float x, float y)
{
	Render1(hdc,x,y);
}

ActRightSquat::ActRightSquat(BOOL c, int f, float t, int uBegin, int uEnd, int lBegin, int lEnd) :
Animation(f, t),
mCirculation(c),
UpperBegin(uBegin),
UpperEnd(uEnd),
LowerBegin(lBegin),
LowerEnd(lEnd),
UpperCount(0),
LowerCount(0)
{
	mImg[0] = new CxImage(L"Role\\ROLE (54).png", CXIMAGE_FORMAT_PNG);
	mImg[0]->Mirror();
	mImg[1] = new CxImage(L"Role\\ROLE (55).png", CXIMAGE_FORMAT_PNG);
	mImg[1]->Mirror();
	mImg[2] = new CxImage(L"Role\\ROLE (56).png", CXIMAGE_FORMAT_PNG);
	mImg[2]->Mirror();
	mImg[3] = new CxImage(L"Role\\ROLE (57).png", CXIMAGE_FORMAT_PNG);
	mImg[3]->Mirror();
	mImg[4] = new CxImage(L"Role\\ROLE (192).png", CXIMAGE_FORMAT_PNG);
	mImg[4]->Mirror();
	mImg[5] = new CxImage(L"Role\\ROLE (193).png", CXIMAGE_FORMAT_PNG);
	mImg[5]->Mirror();
	mImg[6] = new CxImage(L"Role\\ROLE (194).png", CXIMAGE_FORMAT_PNG);
	mImg[6]->Mirror();
	mImg[7] = new CxImage(L"Role\\ROLE (195).png", CXIMAGE_FORMAT_PNG);
	mImg[7]->Mirror();
	mImg[8] = new CxImage(L"Role\\ROLE (196).png", CXIMAGE_FORMAT_PNG);
	mImg[8]->Mirror();
}
void ActRightSquat::Enter()
{
	UpperCount = LowerCount = 0;
}
void ActRightSquat::Render1(HDC hdc, float x, float y)
{
	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();

	mImg[LowerBegin + LowerCount]->Draw(hdc, x - mImg[LowerBegin + LowerCount]->GetWidth() / 2 , y );
	mImg[UpperBegin + UpperCount]->Draw(hdc, x - mImg[UpperBegin + UpperCount]->GetWidth() / 2, y - mImg[UpperBegin + UpperCount]->GetHeight()+25);

	if (mDeltaTime >= mTime)
	{
		UpperCount++;
		LowerCount++;
		mDeltaTime -= mTime;
	}
	if (UpperBegin + UpperCount == UpperEnd)
		UpperCount = 0;
	if (LowerBegin + LowerCount == LowerEnd)
		LowerCount = 0;
}
void ActRightSquat::Render2(HDC hdc, float x, float y)
{
	Render1(hdc, x, y);
}

ActDie::ActDie(int f,float t):
Animation(f, t)
{
	mOneTime = FALSE;

	mImg[0] = new CxImage(L"Role\\ROLE (171).png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Role\\ROLE (172).png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Role\\ROLE (173).png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Role\\ROLE (174).png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Role\\ROLE (175).png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Role\\ROLE (176).png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Role\\ROLE (177).png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Role\\ROLE (178).png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Role\\ROLE (179).png", CXIMAGE_FORMAT_PNG);
	mImg[9] = new CxImage(L"Role\\ROLE (180).png", CXIMAGE_FORMAT_PNG);
	mImg[10] = new CxImage(L"Role\\ROLE (181).png", CXIMAGE_FORMAT_PNG);

}
void ActDie::Enter()
{
	mOneTime = FALSE;
}
void ActDie::Render1(HDC hdc, float x, float y)
{

	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight()/2-10);


	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();
	if (mDeltaTime >= mTime)
	{
		mCount++;
		mDeltaTime -= mTime;
	}
	if (mCount == mFrame)
	{
		mCount = 0;
		mOneTime = TRUE;
	}
}
void ActDie::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight()/2-10);
	mImg[mCount]->Mirror();

	mDeltaTime += GameFrame::GetObject()->GetDeltaTime();
	if (mDeltaTime >= mTime)
	{
		mCount++;
		mDeltaTime -= mTime;
	}
	if (mCount == mFrame)
	{
		mCount = 0;
		mOneTime = TRUE;
	}
}
BOOL ActDie::GetOneTime()
{
	return mOneTime;
}

Role* Role::role=0;
Role::Role(int type, int hp, int power, float x, float y, float xv, float yv) :
IMovable(hp, power,  x,  y, xv, yv),
RoleType(type)
{
	role = this;
	Init();
}
Role::~Role()
{
	map<string, Animation*>::iterator i;
	for (i = m_ActMap.begin(); i != m_ActMap.end(); i++)
		delete i->second;

}

void Role::Init()
{
	ActLeftStand* LeftStand = new ActLeftStand(TRUE, 6, 0.15, 0, 3, 3, 4,4,6);
	m_ActMap["×óÕ¾"] = LeftStand;

	ActRightStand* RightStand = new ActRightStand(TRUE, 6, 0.15, 0, 3, 3, 4,4,6);
	m_ActMap["ÓÒÕ¾"] = RightStand;

	ActLeftRun* LeftRun = new ActLeftRun(FALSE, 19, 0.15, 0, 8, 8, 17,17,19);
	m_ActMap["×ó"] = LeftRun;

	ActRightRun* RightRun = new ActRightRun(FALSE, 19, 0.15, 0, 8, 8, 17,17,19);
	m_ActMap["ÓÒ"] = RightRun;

	ActLeftJump* LeftJump = new ActLeftJump(FALSE, 12, 0.15, 0, 5, 5, 10,10,12);
	m_ActMap["×óÌø"] = LeftJump;

	ActRightJump* RightJump = new ActRightJump(FALSE, 12, 0.15, 0, 5, 5, 10,10,12);
	m_ActMap["ÓÒÌø"] = RightJump;

	ActLeftSquat* LeftSquat = new ActLeftSquat(FALSE, 9, 0.15, 0, 4, 4, 9);
	m_ActMap["×ó¶×"] = LeftSquat;

	ActRightSquat* RightSquat = new ActRightSquat(FALSE, 9, 0.15, 0, 4, 4, 9);
	m_ActMap["ÓÒ¶×"] = RightSquat;

	ActDie* Die = new ActDie(11, 0.15);
	m_ActMap["ËÀÍö"] = Die;

	m_pGameInput = GameFrame::GetObject()->GetGI();
	mState = "ÓÒÕ¾";

	SetAct(mState);
}
void Role::Enter()
{
	mPos.x = 100;
	mPos.y = 500;

	mDirect.x = 1;
	mDirect.y = 0;

	mExist.AnimationEnd = FALSE;
	mExist.Die = FALSE;

	mHP = 1;

	mState = "ÓÒÕ¾";
	SetAct(mState);

	m_pGameInput->Enter();
}
void Role::Run(HDC hdc)
{

	if (mHP == 0 && !mExist.Die)
	{
		mExist.Die = TRUE;
		mState = "ËÀÍö";
		mPos.y = 500;
		SetAct(mState);
		Scene::sound.play(ROLEDIE);
	}
	if (mExist.Die && !mExist.AnimationEnd)
	{
		if (mDirect.x==-1)
			m_pAct->Render1(hdc, mPos.x, mPos.y);
		else
			m_pAct->Render2(hdc, mPos.x, mPos.y);
		mExist.AnimationEnd = m_pAct->GetOneTime();
		return;
	}

	if (!m_pGameInput->State.empty() && mState != m_pGameInput->State)
	{
		mState.clear();
		mState = m_pGameInput->State;
		SetAct(mState);
	}
	if (m_pGameInput->mUP)
		m_pAct->Render2(hdc, mPos.x, mPos.y);
	else
		m_pAct->Render1(hdc, mPos.x, mPos.y);


	if (m_pGameInput->mJ)
	{
		Scene::sound.play(GUN0);
		if (m_pGameInput->mUP && mDirect.x == 1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x - 5, mPos.y - 100, 0, 600, sDirect{ 0, -1 }));
		else if (m_pGameInput->mUP && mDirect.x == -1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x + 5, mPos.y - 100, 0, 600, sDirect{ 0, -1 }));
		else if (m_pGameInput->mDOWN && mDirect.x == 1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x + 70, mPos.y + 5, 600, 0, mDirect));
		else if (m_pGameInput->mDOWN && mDirect.x == -1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x - 70, mPos.y + 5, 600, 0, mDirect));
		else if (mDirect.x==1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x + 60, mPos.y - 15, 600, 0, mDirect));
		else if (mDirect.x == -1)
			RoleBulletMgr::GetBulletMgr()->Create(new Bullet1(1, 1, mPos.x - 60, mPos.y - 15, 600, 0, mDirect));
	}

	if (m_pGameInput->mL)
	{
		if (mDirect.x == 1)
			RoleBulletMgr::GetBulletMgr()->Create(new Boom(1, 1, mPos.x + 20, mPos.y - 15, 300, -400, mDirect));
		else if (mDirect.x == -1)
			RoleBulletMgr::GetBulletMgr()->Create(new Boom(1, 1, mPos.x - 20, mPos.y - 15, 300, -400, mDirect));
	}
}

void Role::Quit()
{}

void Role::Draw(HDC hdc)
{
	m_pAct->Render1(hdc, mPos.x, mPos.y);
}

BOOL Role::Move(BOOL go)
{
	if (!GetHP())//ËÀÁË¾Í²»ÒÆ¶¯
	{
		return TRUE;
	}

	if (m_pGameInput->mXmove > 0)
		mDirect.x = 1;
	if (m_pGameInput->mXmove < 0)
		mDirect.x = -1;
	mPos.x += m_pGameInput->mXmove;
	mPos.y += m_pGameInput->mYmove;
	if (mPos.y > 500)
		mPos.y = 500;
	if (mPos.x > 800)
		mPos.x = 800;
	else if (mPos.x<0)
		mPos.x = 0;
	if (mPos.x > 350 && !go)
	{
		mPos.x = 350;
		return FALSE;
	}
	return TRUE;
}
void Role::Move2(float x)
{
	if (!GetHP())//ËÀÁË¾Í²»ÒÆ¶¯
	{
		return;
	}

	if (m_pGameInput->mXmove > 0)
		mDirect.x = 1;
	if (m_pGameInput->mXmove < 0)
		mDirect.x = -1;
	mPos.x += m_pGameInput->mXmove+x;
	mPos.y += m_pGameInput->mYmove;
	if (mPos.y > 500)
		mPos.y = 500;
	if (mPos.x > 800)
		mPos.x = 800;
	else if (mPos.x<0)
		mPos.x = 0;
}
BOOL Role::SetAct(const string ID)
{
	map<string, Animation*>::iterator i = m_ActMap.find(ID);
	if (i == m_ActMap.end())
		return FALSE;
	m_pAct = i->second;
	m_pAct->Enter();
	return FALSE;
}

RECT Role::GetRect()
{
	RECT r;

	if (GameFrame::GetObject()->GetGI()->mDOWN)
	{
		r.bottom = mPos.y + 30;
		r.right = mPos.x + 30;
		r.top = mPos.y - 25 ;
		r.left = mPos.x - 30;
	}
	else
	{
		r.bottom = mPos.y + 30;
		r.right = mPos.x + 25;
		r.top = mPos.y - 50;
		r.left = mPos.x - 25;
	}

	return r;
}

Role* Role::GetRoleP()
{
	if (!role)
		role = new Role(Scene::SelectRole, 1, 1, 100, 500, 100, 100);
	return role;
}