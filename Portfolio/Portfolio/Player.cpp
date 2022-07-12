#include "Player.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "NormalBullet.h"
#include "Object.h"
#include "ObjectManager.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() { Release(); }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;

	if (SelectPlayer == 0)
	{
		Buffer[0] = (char*)"┼┼┼";
		Buffer[1] = (char*)"├─┤";
	}
	else if (SelectPlayer == 1)
	{
		Buffer[0] = (char*)"┼┼┼";
		Buffer[1] = (char*)"├─┤";
	}

	TransInfo.Position = Vector3(40.0f, 50.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 6.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;
	Color = 15;

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1;

	if (dwKey & KEY_SPACE)
	{
		Bridge* pBridge = new NormalBullet;
		ObjectManager::GetInstance()->AddObject("Bullet", pBridge);
		ObjectManager::GetInstance()->GetObjectList("Bullet")->back()->SetPosition(TransInfo.Position);
	}

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);
	}
}

void Player::Release()
{
	::Safe_Delete(pBridge);
}




// 피타고라스 + 외적 내적
// 
// 이때까지는 Bullet에 속성없이 그냥 키 값으로만 넘겻는데
// CreateBullet에서 속성을 주고 넘겨줌