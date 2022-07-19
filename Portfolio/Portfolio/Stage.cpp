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
#include "PlayerBullet.h"

Stage::Stage() : Check() { }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;
	InGame_Score = 0;
	ObjectManager::GetInstance()->AddObject("Player");
	// 한번만 실행시켜주면 되서 update에 있을 필요가없음
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	//  UserInstance -> Player;

	Bridge* pBridge = new Enemy1;
	ObjectManager::GetInstance()->AddObject("Enemy", pBridge);
	eEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->back();

	eEnemy->SetPosition(40.0f,30.0f);

	pUI = new ScrollBox;
	pUI->Initialize();
}

void Stage::Update()
{
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	MoveCount();
	Bilde_Stage();

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
			if ((*iter)->GetPosition().y >= 60.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().y < -5.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().x < 0.0f)
				iter = pEnemyList->erase(iter);
			else if ((*iter)->GetPosition().x > 80.0f)
				iter = pEnemyList->erase(iter);
			else
				++iter;
		}
	}

	BulletBridge* PB = new PlayerBullet;
	EnemyBridge* E_Hp = new Enemy1;
	Player Player;
	// bool 값 하나줘서 부딛히고 나면  bool값에 따라서 삭제할지 정하기
	// Bullet 와 Enemy가 같이 지워져야되는데 

	// 충돌
	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{		
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); )
			{
				Del_ = false;
				if (CollisionManager::RectCollision(pPlayer, *Enemyiter))
				{
					Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);
					// 터지는 이펙트와 Player데미지 닳게	
					
					// --Player.P_HP;
					// if (Player.P_HP <= 0)
					// {
					//		// 씬이동 GameOver;
					// }
				}

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); )
					{
						if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
						{
							// 총알지워주기
							Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);

							E_Hp->E_Hp -= PB->PB_Damage;

							if (E_Hp->E_Hp <= 0)
							{
								CursorManager::GetInstance()->WriteBuffer(40.0f, 1.0f, (char*)"사망", 15);
								// 몬스터 지워주기
								Del_ = true;
							}
						}
						else
							++Bulletiter;
					}
				}
				// bool값에 따라서 지워줄지 정하기?
				if (Del_ == true)
				{
					Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					InGame_Score += 1000;
				}
				if (Del_ == false)
				{
					++Enemyiter;
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

void Stage::MoveCount()
{
	if (Count <= 30)
		++Count;

	else
		Count = 0;
}

void Stage::Bilde_Stage()
{

	// if (Show_Stage == 0)
	// {
	// 		if (Count == 15)
	// 		{
	// 			for (int i = 0; i < 2; ++i)
	// 			{
	// 				// 몬스터 안겹치게 하는법??
	// 
	// 				srand(DWORD(GetTickCount64() * (i + 3)));
	// 
	// 				Bridge* pBridge = new Enemy1;
	// 				ObjectManager::GetInstance()->AddObject("Enemy", pBridge);
	// 				eEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->back();
	// 
	// 				eEnemy->SetPosition((float)(rand() % 76), (float)(rand() % -2));
	// 
	//				++E_Count;
	// 
	//				if(E_Count == 50)
	// 				{
	// 	   				// E_Count가 50이 되면 스테이지 넘어감
	//					++Show_Stage;
	//				}
	// 			}
	//		}  
	// }

}

void Stage::Score()
{
	// 출력어케 할껀지 왼쪽상단
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 5.0f, (char*)"1P : ", 15);
	CursorManager::GetInstance()->WriteBuffer(
		5.0f, 5.0f, InGame_Score, 15);
}

// 총맞았을때 몬스터 지워지게 하는법

// 충돌해야되는 것들
// 1. 아이템과 플레이어의 충돌
// 2. 적과 플레이어의 충돌
// 3. 적과 플레이어 총알의 충돌
// 4. 적의 총알과 플레이어의 충돌
// 충돌하면 안되는 것들
// 