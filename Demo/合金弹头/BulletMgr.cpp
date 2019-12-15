#include"BulletMgr.h"


/*--------------------------------RoleBulletMgr--------------------------------------------*/
RoleBulletMgr* RoleBulletMgr::m_pBulletMgr = 0;
RoleBulletMgr::RoleBulletMgr()
{
	m_pBulletMgr = this;
	new Bullet1(9);
	new Boom(31);
}
void RoleBulletMgr::Update(float deltaTime, float backgroundDis)
{
	list<IMovable *>::iterator i;
	for (i = mMovableList.begin(); i != mMovableList.end(); i++)
	{
		(*i)->Update(deltaTime, backgroundDis);
	}
}
void  RoleBulletMgr::CollisionDetect(list<IMovable *> *el)
{
	list<IMovable *>::iterator itr1 = mMovableList.begin(), end1 = mMovableList.end(), temp1;
	while (itr1 != end1)
	{
		temp1 = itr1++;
		if (!RestrictInBoundary((*temp1)->GetRect()))
		{
			delete (*temp1);
			mMovableList.erase(temp1);
		}
		else if ((*temp1)->GetExist())
		{
			delete (*temp1);
			mMovableList.erase(temp1);
		}
		else if ((*temp1)->mExist.Die == FALSE)
		{
			list<IMovable *>::iterator itr2 = el->begin(), end2 = el->end(), temp2;
			while (itr2 != end2)
			{
				RECT r;
				temp2 = itr2++;
				if (!(*temp2)->mExist.Die && IntersectRect(&r, &((*temp2)->GetRect()), &(*temp1)->GetRect()))
				{
					(*temp2)->Bleed((*temp1)->GetPower());
					(*temp1)->Bleed((*temp2)->GetPower());
					break;
				}

			}
		}
	}
}

RoleBulletMgr* RoleBulletMgr::GetBulletMgr()
{
	if (!m_pBulletMgr)
		m_pBulletMgr = new RoleBulletMgr;
	return m_pBulletMgr;
}


/*--------------------------------EnemyBulletMgr--------------------------------------------*/

EnemyBulletMgr* EnemyBulletMgr::m_pBulletMgr = 0;
EnemyBulletMgr::EnemyBulletMgr()
{
	m_pBulletMgr = this;
	delete new Bullet2(13);
	delete new Bullet3(19);
	delete new Bullet4(10);
}
void EnemyBulletMgr::Update(float deltaTime, float backgroundDis)
{
	list<IMovable *>::iterator i;
	for (i = mMovableList.begin(); i != mMovableList.end(); i++)
	{
		(*i)->Update(deltaTime, backgroundDis);
	}
}
void  EnemyBulletMgr::CollisionDetect(IMovable* p)
{
	list<IMovable *>::iterator itr = mMovableList.begin(), end = mMovableList.end(), temp;
	while (itr != end)
	{
		RECT r;
		temp = itr++;
		Bullet1* b = (Bullet1*)(*temp);
		if (!RestrictInBoundary(b->GetRect()))
		{
			delete b;
			mMovableList.erase(temp);
		}
		else if (b->GetExist())
		{
			delete b;
			mMovableList.erase(temp);
		}
		else if (b->mExist.Die == FALSE)
		{
			if (IntersectRect(&r, &(b->GetRect()), &(p->GetRect())))
			{
				p->Bleed(b->GetPower());
				b->Bleed(p->GetPower());
			}
		}

	}
}
EnemyBulletMgr* EnemyBulletMgr::GetBulletMgr()
{
	if (!m_pBulletMgr)
		m_pBulletMgr = new EnemyBulletMgr;
	return m_pBulletMgr;
}