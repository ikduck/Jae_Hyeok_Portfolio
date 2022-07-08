#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() { }


void Player::Initialize()
{
	strKey = "Player";

	/*
		 Buffer[0][0] = (char*)"¦«";
		 Buffer[0][1] = (char*)"¦«";
		 Buffer[0][2] = (char*)"¦«";
		 Buffer[1][0] = (char*)"¦²";
		 Buffer[1][0] = (char*)"¦¡";
		 Buffer[1][0] = (char*)"¦©";
	*/ 

	// Buffer[0] = (char*)"¦«¦«¦«";
	// Buffer[1] = (char*)"¦²¦¡¦©";

	Buffer[0] = (char*)" ¦« ";
	Buffer[1] = (char*)" ¦ª ";
	//¦¡¦¢¦¡
	//¦¢¦¡¦¢

	// ¦«¦«¦«
	// ¦²¦¡¦©

	TransInfo.Position = Vector3(30.0f, 45.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);;

	Color = 15;
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
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Bullet>::CreateObject(TransInfo.Position));
	}

	return 0;
}

void Player::Render()
{
	/*
	 for (int i = 0; i < MAX_SIZE; ++i)
	 {
	 	for (int j = 0; j < MAX_SIZE; ++j)
	 	{
	 		CursorManager::GetInstance()->WriteBuffer(
	 			TransInfo.Position.x,
	 			TransInfo.Position.y + i,
	 			Buffer[i][j], Color);
	 	}
	 }
	*/

	for (int i = 0; i < MAX_SIZE; ++i)
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