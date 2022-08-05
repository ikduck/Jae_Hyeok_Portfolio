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
#include "Enemy1.h"
#include "BulletBridge.h"
#include "PlayerBullet.h"
#include "Cloud.h"
#include"BulletBridge2.h"
#include "EnemyBullet.h"
#include "PlayerInfo.h"

Stage::Stage() : Check() { }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;
	ResetPlayerInfo();
	ObjectManager::GetInstance()->AddObject("Player");
	// 한번만 실행시켜주면 되서 update에 있을 필요가없음
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	//  UserInstance -> Player;

	// Bridge* pBridge = new Enemy1;
	// ObjectManager::GetInstance()->AddObject("Enemy", pBridge);
	// eEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->back();

	//eEnemy->SetPosition(40.0f,30.0f);

	pUI = new ScrollBox;
	pUI->Initialize();
}

void Stage::Update()
{
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pBulletList2 = ObjectManager::GetInstance()->GetObjectList("Bullet2");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pCloudList = ObjectManager::GetInstance()->GetObjectList("Cloud");

	MoveCount();

	Bilde_Stage();
	Bilde_BackGround();
	Score();
	ShowPlayerLife();

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

	// 맵밖으로 나가면 지우기
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
	if (pBulletList2 != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList2->begin();
			iter != pBulletList2->end(); )
		{
			if ((*iter)->GetPosition().y >= 58.0f)
				iter = pBulletList2->erase(iter);
			else
				++iter;
		}
	}
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
	if (pCloudList != nullptr)
	{
		for (list<Object*>::iterator iter = pCloudList->begin();
			iter != pCloudList->end(); )
		{
			if ((*iter)->GetPosition().y >= 60.0f)
				iter = pCloudList->erase(iter);
			else
				++iter;
		}
	}

	EnemyBridge* Enemy = new Enemy1;

	// 충돌
	if (pPlayer != nullptr) 
	{ 
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); )
			{
				Del_BM = false;

				if (CollisionManager::RectCollision(pPlayer, *Enemyiter))
				{
					CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);

					--P_HP;
					Del_BM = true;
				}

				Del_Player = false;
				// 플레이어와 적 총알 충돌
				if (pBulletList2 != nullptr)
				{
					for (list<Object*>::iterator Bulletiter2 = pBulletList2->begin();
						Bulletiter2 != pBulletList2->end(); )
					{
						if (CollisionManager::RectCollision(*Bulletiter2, pPlayer))
						{
							Bulletiter2 = ObjectManager::GetInstance()->ThrowObject(Bulletiter2, (*Bulletiter2));
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);

							Del_Player = true;
						}
						else
							++Bulletiter2;
					}
				}
				if (Del_Player == true)
				{
					--P_HP;
					// 터지는 이펙트와 Player데미지 닳게	
					if (P_HP == 1)
					{
						// 기존 이미지 지우고
						// 터지는 모션 + 리스폰
						CursorManager::GetInstance()->WriteBuffer(40.0f, 1.0f, (char*)"플레이어 사망", 15);
					}
					if (P_HP <= 0)
					{
						//  GameOver;
						// ResetPlayerInfo(); // 값전부 초기화 해주고
						// SceneManager::GetInstance()->SetScene(GAMEOVER);
						// 계속 위치값을 받아오다가 안받와서 터짐
					}
				}
				// GameOver화면 띄우고 -> Logo로 다시이동 // 변수 초기화 

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); )
					{
						if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
						{
							Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다", 15);

							// 에너미 체력 가져오기
							Enemy->E_Hp -= PB_Damage;

							if (Enemy->E_Hp <= 0)
							{
								CursorManager::GetInstance()->WriteBuffer(40.0f, 1.0f, (char*)"적 사망", 15);
								Del_BM = true;
							}
						}
						else
							++Bulletiter;
					}
				}

				if (Del_BM == true )
				{
					Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					InGame_Score += 1000;
					// 몬스터 아이템 떨구기
				}

				if (Del_BM == false)
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

// stage관련
void Stage::Bilde_Stage()
{
	 if (Show_Stage == 0)
	 {
	 		if (Count == 15)
	 		{
	 			for (int i = 0; i < 2; ++i)
	 			{
	 				// 몬스터 안겹치게 하는법??
	 				srand(DWORD(GetTickCount64() * (i + 3)));
	 
	 				Bridge* pBridge = new Enemy1;
	 				ObjectManager::GetInstance()->AddObject("Enemy", pBridge);
	 				eEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->back();
	 
	 				eEnemy->SetPosition((float)(rand() % 76), (float)(rand() % -2));
	 
	 			++E_Count;
	 
	 			if(E_Count == 50)
	 				{
	 	   				// E_Count가 50이 되면 스테이지 넘어감
	 				++Show_Stage;
	 				}
	 			}
	 		}  
	 }
	// Enemy1[] 를 만들어서 넣고 서로 위치가 겹치면 지우고 다시 만들어지게
}

// 구름 리스폰
void Stage::Bilde_BackGround()
{
	if (Count == 30)
	{ 
		ObjectManager::GetInstance()->AddObject("Cloud");
		bCloud = ObjectManager::GetInstance()->GetObjectList("Cloud")->back();

		bCloud->SetPosition((float)(rand() % 76), (float)(rand() % -2));
	}
}

// 왼쪽상단 점수 표시
void Stage::Score()
{
	// 출력어케 할껀지 왼쪽상단
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 1.0f, (char*)"1P : ", 15);
	CursorManager::GetInstance()->WriteBuffer(
		5.0f, 1.0f, InGame_Score, 15);
}

void Stage::ShowPlayerLife()
{
	switch (P_HP)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(15.0f, 2.0f, (char*)"", 15);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(15.0f, 2.0f, (char*)"◈", 15);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(15.0f, 2.0f, (char*)"◈◈", 15);
		break;
	}

	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 2.0f, (char*)"Player_Life : ", 15);
}

void Stage::ResetPlayerInfo()
{
	P_HP = 2;
	PB_Damage = 1;
	InGame_Score = 0;
}

// 총맞았을때 몬스터 지워지게 하는법
// 충돌해야되는 것들
// 1. 아이템과 플레이어의 충돌 // 음..

