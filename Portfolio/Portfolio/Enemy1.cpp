#include "Enemy1.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "EnemyBullet.h"
#include "ObjectManager.h"

Enemy1::Enemy1() { }
Enemy1::~Enemy1() { }

void Enemy1::Initialize()
{
	Buffer[0] = (char*)"  ┬  ";
	Buffer[1] = (char*)"─┼─";

	// list로 , Player는 따로 빼서  , Monster도 따로 만들어주기

	Speed = 0.3f;
	Color = 12;
	E_Hp = 1;
}

int Enemy1::Update(Transform& TransInfo)
{
	// TransInfo.Direction = MathManager::GetDirection(
	// 	TransInfo.Position, Vector3(40.0f, 60.0f));
	// Fire_EBullet();

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	TransInfo.Position.y += Speed;

	return 0;
}

void Enemy1::Render()
{
	// if E_HP <= 0;  터지는 모션 아니면 평소모션
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + i,
			Buffer[i], Color);
	}
}

void Enemy1::Release()
{

}

void Enemy1::SetD(Transform& Info)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), Vector3(40.0f, 30.0f)));

}

void Enemy1::Fire_EBullet()
{
	// if (Count <= 20)
	// 	++Count;
	// 
	// else
	// 	Count = 0;
	// 
	// if (Count == 10)
	// {
	// 
	// 	Bridge* pBridge = new EnemyBullet;
	// 	ObjectManager::GetInstance()->AddObject("Bullet2", pBridge);
	// 	ObjectManager::GetInstance()->GetObjectList("Bullet2")->back()->SetPosition(pObject->GetPosition());
	// 	// ObjectManager::GetInstance()->GetObjectList("Bullet2")->back();
	// 	((BulletBridge2*)pBridge)->SetD(pObject->GetDirection());
	// }
}


