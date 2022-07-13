#include "PlayerBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

PlayerBullet::PlayerBullet() { }
PlayerBullet::~PlayerBullet() { }

void PlayerBullet::Initialize()
{
	// ** Bullet�� 
	// ������.
	// type

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	Speed = 3.0f;
	Color = 15;
	PB_Damage = 1;
	// �Ѿ˰���
	PB_BulletNum = 1;
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
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x + 2,
			pObject->GetPosition().y + i,
			Buffer[i], Color);
	}
}

void PlayerBullet::Release()
{

}

