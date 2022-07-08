#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { }

void Bullet::Initialize()
{
	strKey = "Bullet";
	/*
		Buffer[0][0] = (char*)" ";
		Buffer[0][1] = (char*)"¦«";
		Buffer[0][2] = (char*)" ";
		Buffer[1][0] = (char*)"";
		Buffer[1][1] = (char*)"¦ª";
		Buffer[1][2] = (char*)"";
	*/

	Buffer[0] = (char*)" ¦« ";
	Buffer[1] = (char*)" ¦ª ";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Color = 15;
}

int Bullet::Update()
{
	 // TransInfo.Direction = MathManager::GetDirection(
	 // 	TransInfo.Position, Vector3(0.0f, 25.0f));
	 // 
	 // TransInfo.Position += TransInfo.Direction;

	TransInfo.Position.y -= 2.0f;

	return 0;
}

void Bullet::Render()
{
	// for (int i = 0; i < MAX_SIZE; ++i)
	// {
	// 	for (int j = 0; j < MAX_SIZE; ++j)
	// 	{
	// 		CursorManager::GetInstance()->WriteBuffer(
	// 			TransInfo.Position.x,
	// 			TransInfo.Position.y + i,
	// 			Buffer[i][j], Color);
	// 	}
	// }

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);
	}
}

void Bullet::Release()
{

}