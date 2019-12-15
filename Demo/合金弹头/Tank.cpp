#include"Tank.h"
#include"Scene.h"
#include"Role.h"
#include"BulletMgr.h"
#include"EnemyMgr.h"

CxImage** Tank::mImg = 0;
int Tank::mFrame = 0;
Tank::Tank(int f)
{
	mFrame = f;
	mImg = new CxImage*[f];


	mImg[0] = new CxImage(L"Tank\\1.png", CXIMAGE_FORMAT_PNG);
	mImg[1] = new CxImage(L"Tank\\2.png", CXIMAGE_FORMAT_PNG);
	mImg[2] = new CxImage(L"Tank\\3.png", CXIMAGE_FORMAT_PNG);
	mImg[3] = new CxImage(L"Tank\\4.png", CXIMAGE_FORMAT_PNG);
	mImg[4] = new CxImage(L"Tank\\5.png", CXIMAGE_FORMAT_PNG);
	mImg[5] = new CxImage(L"Tank\\6.png", CXIMAGE_FORMAT_PNG);
	mImg[6] = new CxImage(L"Tank\\7.png", CXIMAGE_FORMAT_PNG);
	mImg[7] = new CxImage(L"Tank\\8.png", CXIMAGE_FORMAT_PNG);
	mImg[8] = new CxImage(L"Tank\\9.png", CXIMAGE_FORMAT_PNG);
	mImg[9] = new CxImage(L"Tank\\10.png", CXIMAGE_FORMAT_PNG);
	mImg[10] = new CxImage(L"Tank\\11.png", CXIMAGE_FORMAT_PNG);
	mImg[11] = new CxImage(L"Tank\\12.png", CXIMAGE_FORMAT_PNG);
	mImg[12] = new CxImage(L"Tank\\13.png", CXIMAGE_FORMAT_PNG);
	mImg[13] = new CxImage(L"Tank\\14.png", CXIMAGE_FORMAT_PNG);
	mImg[14] = new CxImage(L"Tank\\15.png", CXIMAGE_FORMAT_PNG);
	mImg[15] = new CxImage(L"Tank\\16.png", CXIMAGE_FORMAT_PNG);
	mImg[16] = new CxImage(L"Tank\\17.png", CXIMAGE_FORMAT_PNG);
	mImg[17] = new CxImage(L"Tank\\18.png", CXIMAGE_FORMAT_PNG);
	mImg[18] = new CxImage(L"Tank\\19.png", CXIMAGE_FORMAT_PNG);
	mImg[19] = new CxImage(L"Tank\\20.png", CXIMAGE_FORMAT_PNG);
	mImg[20] = new CxImage(L"Tank\\21.png", CXIMAGE_FORMAT_PNG);
	mImg[21] = new CxImage(L"Tank\\22.png", CXIMAGE_FORMAT_PNG);
	mImg[22] = new CxImage(L"Tank\\23.png", CXIMAGE_FORMAT_PNG);
	mImg[23] = new CxImage(L"Tank\\24.png", CXIMAGE_FORMAT_PNG);
	mImg[24] = new CxImage(L"Tank\\25.png", CXIMAGE_FORMAT_PNG);
	mImg[25] = new CxImage(L"Tank\\26.png", CXIMAGE_FORMAT_PNG);
	mImg[26] = new CxImage(L"Tank\\27.png", CXIMAGE_FORMAT_PNG);
	mImg[27] = new CxImage(L"Tank\\28.png", CXIMAGE_FORMAT_PNG);
	mImg[28] = new CxImage(L"Tank\\29.png", CXIMAGE_FORMAT_PNG);
	mImg[29] = new CxImage(L"Tank\\30.png", CXIMAGE_FORMAT_PNG);
	mImg[30] = new CxImage(L"Tank\\31.png", CXIMAGE_FORMAT_PNG);
	mImg[31] = new CxImage(L"Tank\\32.png", CXIMAGE_FORMAT_PNG);
}
Tank::Tank(int life, int power, float x, float y, float xv, float yv) :
IMovable(life, power, x, y, xv, yv),
mTime(0),
mCount(0)
{
	mExist.Die = FALSE;
	mExist.AnimationEnd = FALSE;

	OutputStrategy* p1 = new OutputStrategy(0, 2, 0.3);
	m_MapOutputStrategy["开动"] = p1;
	OutputStrategy* p2 = new OutputStrategy(2, 11, 0.2);
	m_MapOutputStrategy["准备"] = p2;
	OutputStrategy* p3 = new OutputStrategy(11, 22, 0.1);
	m_MapOutputStrategy["蓄力"] = p3;
	OutputStrategy* p4 = new OutputStrategy(22, 32, 0.1);
	m_MapOutputStrategy["炸毁"] = p4;

	mState = "开动";
	m_pOutputStrategy = m_MapOutputStrategy[mState];

	mDirect.x = -1;
	mAttack = FALSE;
	mFind = FALSE;
	mSignShoot = FALSE;
	mLastAttack = -1;
}
Tank::~Tank()
{
	map<string, OutputStrategy*>::iterator j;
	for (j = m_MapOutputStrategy.begin(); j != m_MapOutputStrategy.end(); j++)
		delete j->second;
}
void Tank::SetOutputStrategy(const string ID)
{
	map<string, OutputStrategy*>::iterator i = m_MapOutputStrategy.find(ID);
	if (i == m_MapOutputStrategy.end())
		return;
	m_pOutputStrategy = i->second;
	m_pOutputStrategy->Enter();
}
void Tank::Update(float deltaTime, float backgroundMove)
{
	mCount = m_pOutputStrategy->Update(deltaTime);
	mWidth = mImg[mCount]->GetWidth();
	mHeight = mImg[mCount]->GetHeight();
	if (mState=="开动")
		mPos.x += mDirect.x * xSpeed * deltaTime - backgroundMove;
	else
		mPos.x -= backgroundMove;
	if (mExist.Die)//死亡优先级最高
	{
		mExist.AnimationEnd = m_pOutputStrategy->GetIfOnePeriod();
		if (mExist.AnimationEnd)
			EnemyMgr::mTankNum--;
		return;
	}

	cPOINTF p = Role::GetRoleP()->GetPos();
	if (mFind)
	{
		if (mState == "准备" && m_pOutputStrategy->GetIfOnePeriod())
		{
			mState = "蓄力";
			SetOutputStrategy(mState);
		}
		if (mState == "蓄力" && m_pOutputStrategy->GetIfOnePeriod())
		{
			mState = "开动";
			SetOutputStrategy(mState);
			mFind = FALSE;
			Scene::sound.play(GUN3);
			if (mDirect.x==1)
				EnemyBulletMgr::GetBulletMgr()->Create(new Bullet4(1, 1, mPos.x + 60, mPos.y - 35, 400, 0, mDirect));
			else
				EnemyBulletMgr::GetBulletMgr()->Create(new Bullet4(1, 1, mPos.x - 60, mPos.y - 35, 400, 0, mDirect));
		}
	}
	else if (mPos.GetDistance(p) < 600 && mFind == FALSE && mTime - mLastAttack > 3)
	{
		mLastAttack = mTime;
		mState = "准备";
		SetMoveStrategy(mState);
		mFind = TRUE;
	}
	mTime += deltaTime;

	if (mPos.x > p.x)
		mDirect.x = -1;
	else
		mDirect.x = 1;

	if (mPos.x>800)
		mDirect.x = -1;
	if (mPos.x < 0)
		mDirect.x = 1;

	if (mPos.x < -200)
	{
		mExist.AnimationEnd = TRUE;
		mExist.Die = TRUE;
		EnemyMgr::mTankNum--;
	}

}
void Tank::Draw(HDC hdc)
{
	if (mDirect.x == 1)
		Render1(hdc, mPos.x, mPos.y);
	else
		Render2(hdc, mPos.x, mPos.y);

}
void Tank::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
}
void Tank::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
void Tank::Bleed(int power)
{
	if (mHP == 0)
		return;
	mHP -= power;
	if (mHP < 0)
		mHP = 0;
	if (mHP == 0)
	{
		Scene::sound.play(BOOM1);

		mExist.Die = TRUE;
		mState = "炸毁";
		SetOutputStrategy(mState);
	}
	mAttack = TRUE;

}
RECT Tank::GetRect()
{
	RECT r;
	r.bottom = mPos.y + mHeight / 2;
	r.left = mPos.x - mWidth / 2;
	r.right = mPos.x + mWidth / 2;
	r.top = mPos.y - mHeight / 2;
	return r;
}

void Tank::End()
{
	for (int k = 0; k < mFrame; k++)
		delete mImg[k];
}
/*--------------------------------------------------------------*/