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
	// �ѹ��� ��������ָ� �Ǽ� update�� ���� �ʿ䰡����
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

	// PlayerBullet �ʹ����� ������ ����� 
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

	// �� �� ������ �������� �����
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
	// bool �� �ϳ��༭ �ε����� ����  bool���� ���� �������� ���ϱ�
	// Bullet �� Enemy�� ���� �������ߵǴµ� 

	// �浹
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
					CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�", 15);
					// ������ ����Ʈ�� Player������ ���	
					
					// --Player.P_HP;
					// if (Player.P_HP <= 0)
					// {
					//		// ���̵� GameOver;
					// }
				}

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); )
					{
						if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
						{
							// �Ѿ������ֱ�
							Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�", 15);

							E_Hp->E_Hp -= PB->PB_Damage;

							if (E_Hp->E_Hp <= 0)
							{
								CursorManager::GetInstance()->WriteBuffer(40.0f, 1.0f, (char*)"���", 15);
								// ���� �����ֱ�
								Del_ = true;
							}
						}
						else
							++Bulletiter;
					}
				}
				// bool���� ���� �������� ���ϱ�?
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
	// 				// ���� �Ȱ�ġ�� �ϴ¹�??
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
	// 	   				// E_Count�� 50�� �Ǹ� �������� �Ѿ
	//					++Show_Stage;
	//				}
	// 			}
	//		}  
	// }

}

void Stage::Score()
{
	// ��¾��� �Ҳ��� ���ʻ��
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 5.0f, (char*)"1P : ", 15);
	CursorManager::GetInstance()->WriteBuffer(
		5.0f, 5.0f, InGame_Score, 15);
}

// �Ѹ¾����� ���� �������� �ϴ¹�

// �浹�ؾߵǴ� �͵�
// 1. �����۰� �÷��̾��� �浹
// 2. ���� �÷��̾��� �浹
// 3. ���� �÷��̾� �Ѿ��� �浹
// 4. ���� �Ѿ˰� �÷��̾��� �浹
// �浹�ϸ� �ȵǴ� �͵�
// 