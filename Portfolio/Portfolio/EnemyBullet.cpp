#include "EnemyBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

EnemyBullet::EnemyBullet() { }
EnemyBullet::~EnemyBullet() { }

void EnemyBullet::Initialize()
{
	// ** Bullet의 
	// 데미지.
	// type
	Buffer = (char*)"＠"; 

	Speed = 1.0f; 
	Color = 12; 
	EB_Damage = 1; 
}

int EnemyBullet::Update(Transform& TransInfo)
{
	// TransInfo.Direction = MathManager::GetDirection(
	// 	TransInfo.Position, Vector3(40.0f, 60.0f));
	// TransInfo.Direction = Vector3(0.0f, 1.0f);

	pObject->SetPosition(pObject->GetPosition().x , pObject->GetPosition().y + pObject->GetDirection().y * Speed);
	// TransInfo.Position.y += TransInfo.Direction.y * Speed; // Enemy값을 가지고 노는건데 왜 됨?

	// pObject->GetPosition().y = pObject->GetPosition().y + 2;
	return 0;
}

void EnemyBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x + 2,
		pObject->GetPosition().y,
		Buffer, Color);
}

void EnemyBullet::Release()
{

}

void EnemyBullet::SetD(Transform& TransInfo)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), Vector3(40.0f, 60.0f)));
}

