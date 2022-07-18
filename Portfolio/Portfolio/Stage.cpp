#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "ScrollBox.h"
#include"ObjectPool.h"
#include "Prototype.h"
#include "Player1.h"
#include "Enemy1.h"
#include "BulletBridge.h"

Stage::Stage() : Check() { }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	// 한번만 실행시켜주면 되서 update에 있을 필요가없음
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	//  UserInstance -> Player;
	for (int i = 0; i < 5; ++i)
	{
		// 몬스터 안겹치게 하는법
		srand(DWORD(GetTickCount64() * (i + 1)));

		Bridge* pBridge = new Enemy1;
		ObjectManager::GetInstance()->AddObject("Enemy", pBridge);
		eEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->back();

		eEnemy->SetPosition((float)(rand() % 78), (float)(rand() % 10));
	}

	pUI = new ScrollBox;
	pUI->Initialize();
}

void Stage::Update()
{
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	if (dwKey & KEY_ESCAPE)
	{
		// if (pBulletList->size())
		// {
		// 	ObjectPool::GetInstance()->CatchObject(pBulletList->back());
		// 	pBulletList->pop_back();
		// }
	}

	// pPlayer->Update();
	ObjectManager::GetInstance()->Update();

	// PlayerBullet 맵밖으로 나가면 지우기 
	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end(); )
		{
			if ((*iter)->GetPosition().y <= 0.0f)
				iter = pBulletList->erase(iter);
			else
				++iter;
		}
	}

	// 적 맵 밖으로 나갔을때 지우기
	if (pEnemyList != nullptr)
	{
		for (list<Object*>::iterator iter = pEnemyList->begin();
			iter != pEnemyList->end(); )
		{
			if ((*iter)->GetPosition().y >= 58.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().y < 0.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().x < 0.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().x > 80.0f)
				iter = pEnemyList->erase(iter);
			else
				++iter;
		}
	}

	// 충돌
	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			// (*iter).second.erase(iter2);
		
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end();)
			{
				if (CollisionManager::CircleCollision(pPlayer, *Enemyiter))
				{
					Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);
					// 터지는 이펙트와 Player데미지 닳게
				}
				else
					++Enemyiter;

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); )
					{
						if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
						{
							Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);
							// pEnemyList->erase(Enemyiter);

						}
						else
							++Bulletiter;
					}
				}
			}
		}
	}

	if (Check)
		pUI->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
		pUI->Render();
}

void Stage::Release()
{	

}

void Stage::Enable_UI()
{
	Check = !Check;
}

// 총맞았을때 몬스터 지워지게 하는법

// 충돌해야되는 것들
// 1. 아이템과 플레이어의 충돌
// 2. 적과 플레이어의 충돌
// 3. 적과 플레이어 총알의 충돌
// 4. 적의 총알과 플레이어의 충돌
// 충돌하면 안되는 것들
// 