#include "Player.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "PlayerBullet.h"
#include "Object.h"
#include "Menu.h"
#include "Menu2.h"
#include "PlayerInfo.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo),  Color(0), Speed(0) { }
Player::~Player() { Release(); }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;
	
	switch (PlayerInfo::GetInstance()->GetPlayerType())
	{
	case 0:
		Buffer[0] = (char*)"┼┼┼";
		Buffer[1] = (char*)"├─┤";
		break;
	case 1:
		Buffer[0] = (char*)"─┼─";
		Buffer[1] = (char*)"  ┴  ";
		break;
	}

	/*
	if ( PlayerInfo::GetInstance()->GetPlayerType() ==  0) // ObManager->GetPlayerType() ==
	{
			Buffer[0] = (char*)"┼┼┼";
		Buffer[1] = (char*)"├─┤";
	}

	else if (PlayerInfo::GetInstance()->GetPlayerType() == 1) // ObManager->GetPlayerType() == 
	{
		Buffer[0] = (char*)"─┼─";
		Buffer[1] = (char*)"  ┴  ";
	}
	*/

	TransInfo.Position = Vector3(40.0f, 50.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(3.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;
	Color = 10;  // 9 파랑

	return this;
}

int Player::Update()
{
	switch (PlayerInfo::GetInstance()->GetPlayerType())
	{
	case 0:
		Buffer[0] = (char*)"┼┼┼";
		Buffer[1] = (char*)"├─┤";
		break;
	case 1:
		Buffer[0] = (char*)"─┼─";
		Buffer[1] = (char*)"  ┴  ";
		break;
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		if (TransInfo.Position.y > 0.0f)
		{
			TransInfo.Position.y -= 1;
		}
	}

	if (dwKey & KEY_DOWN)
	{
		if (TransInfo.Position.y < 58.0f)
		{
			TransInfo.Position.y += 1;
		}
	}

	if (dwKey & KEY_LEFT)
	{
		if (TransInfo.Position.x > 0.0f)
		{
			TransInfo.Position.x -= 1;
		}
	}

	if (dwKey & KEY_RIGHT)
		if (TransInfo.Position.x < 74.0f)
		{
			TransInfo.Position.x += 1;
		}

	if (dwKey & KEY_SPACE)
	{
		Bridge* pBridge = new PlayerBullet;
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
}




// 피타고라스 + 외적 내적
// 
// 이때까지는 Bullet에 속성없이 그냥 키 값으로만 넘겻는데
// CreateBullet에서 속성을 주고 넘겨줌

// ????

/*

*/