#include "Enemy1.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

Enemy1::Enemy1() { }
Enemy1::~Enemy1() { }

void Enemy1::Initialize()
{
	Buffer[0] = (char*)"  ┬  ";
	Buffer[1] = (char*)"─┼─";

	// list로 , Player는 따로 빼서  , Monster도 따로 만들어주기

	Speed = 1.0f;
	Color = 12;
	E_Hp = 1;
}

int Enemy1::Update(Transform& TransInfo)
{
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(80.0f, 70.0f));

	TransInfo.Position.y += TransInfo.Direction.y * Speed;


	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy1::Render()
{
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

