#include "PlayerBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

PlayerBullet::PlayerBullet() { }
PlayerBullet::~PlayerBullet() { }

void PlayerBullet::Initialize()
{
	// ** Bullet의 
	// 데미지.
	// type

	Buffer = (char*)"∩";

	Speed = 3.0f;
	Color = 15;
	PB_Damage = 1;
}

int PlayerBullet::Update(Transform& TransInfo)
{
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(80.0f, 60.0f));

	TransInfo.Position.y -= TransInfo.Direction.y * Speed;

	return 0;
}

void PlayerBullet::Render()
{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x + 2,
			pObject->GetPosition().y,
			Buffer, Color);
}

void PlayerBullet::Release()
{

}

