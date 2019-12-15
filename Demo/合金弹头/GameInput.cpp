#include"GameInput.h"
#include"Gameframe.h"
GameInput::GameInput() :
mUP(FALSE),
mDOWN(FALSE),
mLEFT(FALSE),
mRIGHT(FALSE),
mJ(FALSE),
mK(FALSE),
mL(FALSE),
mESC(FALSE),
mSPACE(FALSE),
mF5(FALSE),
mXmove(0),
mYmove(0),
mSpeed(0),
mJump(FALSE),
mA(10),
mDeltaTime(0)
{
	mJdeltaTime = 0;
	mLdeltaTime = 0;
	LastDirect = "ÓÒ";
}
GameInput::~GameInput()
{}
void GameInput::Enter()
{
	LastDirect.clear();
	LastDirect = "ÓÒ";
	State.clear();
}
void GameInput::Run(float t)
{
	mSPACE = GetAsyncKeyState(VK_SPACE) & 0X8000;
	if (GameFrame::GetObject()->GetIsRun())
		return;
	mDeltaTime = t;
	mJdeltaTime += t;
	mLdeltaTime += t;
	State.clear();
	//ProcessMsg();
	ProcessMove();
	mESC = GetAsyncKeyState(VK_ESCAPE) & 0X8000;
	mF5 = GetAsyncKeyState(VK_F5) & 0X8000;

	mUP = GetAsyncKeyState(W) & 0X8000;
	mDOWN = GetAsyncKeyState(S) & 0X8000;
	mLEFT = GetAsyncKeyState(A) & 0X8000;
	mRIGHT = GetAsyncKeyState(D) & 0X8000;

	mK = GetAsyncKeyState(K) & 0X8000;

	if ((GetAsyncKeyState(J) & 0X8000) && mJdeltaTime > 0.2)
	{
		mJdeltaTime = 0;
		mJ = TRUE;
	}
	else
		mJ = FALSE;

	if ((GetAsyncKeyState(L) & 0X8000) && mLdeltaTime > 0.7)
	{
		mLdeltaTime = 0;
		mL = TRUE;
	}
	else
		mL = FALSE;

}
void GameInput::ProcessMsg()
{
	if (mLEFT)
		State = "×óÅÜ";
	else if (mRIGHT)
		State = "LowerÓÒ±¼ÅÜ";
}
void GameInput::ProcessMove()
{
	mXmove = mYmove = 0;
	int x, y;
	x = y = 0;
	if (mLEFT)
		x--;
	if (mRIGHT)
		x++;
	mXmove = x*mDeltaTime * 150;
	if (mXmove > 0)
	{
		State += "ÓÒ";
		LastDirect = "ÓÒ";
	}
	else if (mXmove < 0)
	{
		State += "×ó";
		LastDirect = "×ó";
	}


	if (mK && !mJump)
	{
		mJump = TRUE;
		mSpeed = -400;
	}
	if (mJump)
	{
		mSpeed += mDeltaTime * mA*60;
		mYmove = mSpeed*mDeltaTime;
		if (mSpeed > 400)
			mJump = FALSE;

		if (State.empty())
			State += LastDirect;
		State += "Ìø";
		return;
	}

	if (mDOWN)
	{
		if (State.empty())
			State += LastDirect;
		State += "¶×";
	}

	if (State.empty())
	{
		State += LastDirect;
		State += "Õ¾";
	}
}