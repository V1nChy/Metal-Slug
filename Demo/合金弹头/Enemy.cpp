#include"Enemy.h"
#include"GameFrame.h"


Enemy::Enemy(int x, int y, int hp):
mXpos(x),
mYpos(y),
mHp(hp)
{}
Enemy::~Enemy()
{
	map<string, Animation*>::iterator i;
	for (i = m_MapAct.begin(); i != m_MapAct.end(); i++)
		delete(i->second);
}
BOOL Enemy::SetAct(const string ID)
{
	map<string, Animation*>::iterator i = m_MapAct.find(ID);
	if (i == m_MapAct.end())
		return FALSE;
	m_pAct = i->second;
	return FALSE;
}
void Enemy::Init()
{}
void Enemy::Enter()
{}
void Enemy::Run(HDC hdc)
{}
void Enemy::End()
{}


Soldiers1Run::Soldiers1Run(int f, float t):
Animation(f,t)
{
}
void Soldiers1Run::Init(const char* DirectName)
{
	LoadDirectory(DirectName);
}
void Soldiers1Run::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount] ->GetWidth()/2,y-mImg[mCount]->GetHeight()/2 );
	
	mDeltaTime += GameFrame::GetDeltaTime();
	if (mDeltaTime > mTime)
	{
		mDeltaTime -= mTime;
		mCount++;
		if (mCount == mFrame)
			mCount = 0;
	}

}

Soldiers1::Soldiers1(int x, int y, int hp):
Enemy(x,y,hp)
{
	Init();
}
void Soldiers1::Init()
{
	Soldiers1Run* SR = new Soldiers1Run(38, 0.3);
	SR->Init("Enemy");
	m_MapAct["Εά"] = SR;

	SetAct("Εά");
}
void Soldiers1::Run(HDC hdc)
{
	m_pAct->Render1(hdc,mXpos,mYpos);
}
void Soldiers1::End()
{

}