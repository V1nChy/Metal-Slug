#include"Game.h"

GameScene::~GameScene()
{
	delete role;
	delete mEnemyMgr;
	//delete mBackG;
	delete mRoleBulletMgr;
	delete mEnemyBulletMgr;
}
void GameScene::Init()
{
	mTime = 0;
	pGF = GameFrame::GetObject();
	m_hDC = pGF->GetGO()->GethMemDC();

	mBackG = new Background(m_hDC,L"Img\\Background.png");
	role = new Role(Scene::SelectRole,1,1,100,500,100,100);
	mEnemyMgr = new EnemyMgr;
	mEnemyBulletMgr = new EnemyBulletMgr;
	mRoleBulletMgr = new RoleBulletMgr;
}
void GameScene::Enter()
{
	mTime = 0;
	role ->Enter();
	mBackG->Enter();
	mEnemyMgr->Enter();
	mEnemyBulletMgr->Enter();
	mRoleBulletMgr->Enter();
}
void GameScene::Run(float deltaTime)
{
	if (mTime == 0)
	{
		Scene::sound.play(GAME_BACKGROUND);
	}
	mTime += deltaTime;

	if (mTime < 3)
	{
		mBackG->Run3(m_hDC);
		return;
	}
	if (mBackG->IsFinish(role->GetPos().x))
	{
		mBackG->Run4(m_hDC);
		return;
	}
	if (role->GetExist())
	{
		mBackG->Run2(m_hDC);
		return;
	}

	mBackG->Update(deltaTime);
	float dis=0;
	/*if (mBackG->GetPosX()>700 && mTime < 60)
	{
		role->Move(TRUE);
	}
	else if (mBackG->GetPosX()>3370 && mTime < 120)
	{
		role->Move(TRUE);
	}
	else if (role->GetPos().x>350 && !mBackG->GetIsEnd())
	{
		dis = 300 * deltaTime;
		role->Move2(-dis);
		mBackG->MapMove(dis);
	}*/
	if (!role->Move(mBackG->GetIsEnd()))
	{
		dis = pGF->GetGI()->mXmove;
		mBackG->MapMove(pGF->GetGI()->mXmove);
	}

	mBackG->Run1(m_hDC);
	role->Run(m_hDC);

	mEnemyMgr->Draw(m_hDC);
	mEnemyMgr->Update(deltaTime, dis);
	mEnemyMgr->CollisionDetect(role);


	mRoleBulletMgr->Draw(m_hDC);
	mRoleBulletMgr->Update(deltaTime, dis);
	mRoleBulletMgr->CollisionDetect(mEnemyMgr->GetMovableList());
	mRoleBulletMgr->CollisionDetect(mEnemyBulletMgr->GetMovableList());

	mEnemyBulletMgr->Draw(m_hDC);
	mEnemyBulletMgr->Update(pGF->GetDeltaTime(), dis);
	mEnemyBulletMgr->CollisionDetect(role);
}
void GameScene::Quit()
{
	mEnemyMgr->ClearAll();
	mRoleBulletMgr->ClearAll();
	mEnemyBulletMgr->ClearAll();
}
void GameScene::End()
{
	mEnemyMgr->ClearAll();
	mRoleBulletMgr->ClearAll();
	mEnemyBulletMgr->ClearAll();

	//Bullet1::End();
	//Bullet2::End();
	//Bullet3::End();
	//Bullet4::End();
	//Boom::End();

	//Soldier1::End();
	//Soldier2::End();
	//Plane1::End();
	//Tank::End();
}