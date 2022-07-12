#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

NormalBullet::NormalBullet() { } 
NormalBullet::~NormalBullet() { }

void NormalBullet::Initialize()
{
	// ** Bullet의 
	// 데미지.
	// type

	Speed = 3.0f;
	Color = 15;
}

int NormalBullet::Update(Transform& TransInfo)
{
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(80.0f, 60.0f));

	TransInfo.Position.y -= TransInfo.Direction.y * Speed;

	return 0;
}

void NormalBullet::Render()
{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"B", Color);
}

void NormalBullet::Release()
{

}

