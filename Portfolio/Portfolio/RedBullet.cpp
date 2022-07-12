#include "RedBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
RedBullet::RedBullet() { }
RedBullet::~RedBullet() { }

void RedBullet::Initialize()
{
	// ** Bullet의 
	// 데미지.
	Speed = 3.0f;
	Color = 12;
}

int RedBullet::Update(Transform& TransInfo)
{
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position , Vector3(120.0f, 30.0f));

	TransInfo.Position.y -= TransInfo.Direction.y * Speed;

	return 0;
}

void RedBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"B", Color);
}

void RedBullet::Release()
{

}

