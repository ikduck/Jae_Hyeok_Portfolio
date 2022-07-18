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
	// �ѹ��� ��������ָ� �Ǽ� update�� ���� �ʿ䰡����
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	//  UserInstance -> Player;
	for (int i = 0; i < 5; ++i)
	{
		// ���� �Ȱ�ġ�� �ϴ¹�
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

	// �浹
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
					CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�", 15);
					// ������ ����Ʈ�� Player������ ���
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
							CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�", 15);
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

// �Ѹ¾����� ���� �������� �ϴ¹�

// �浹�ؾߵǴ� �͵�
// 1. �����۰� �÷��̾��� �浹
// 2. ���� �÷��̾��� �浹
// 3. ���� �÷��̾� �Ѿ��� �浹
// 4. ���� �Ѿ˰� �÷��̾��� �浹
// �浹�ϸ� �ȵǴ� �͵�
// 