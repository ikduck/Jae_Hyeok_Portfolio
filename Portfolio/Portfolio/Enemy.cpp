#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy() { }
Enemy::Enemy(Transform _TransInfo) : Object(_TransInfo) { }
Enemy::~Enemy() { }

void Enemy::Initialize()
{
	strKey = "Enemy";
	/*
		 Buffer[0][0] = (char*)"戌";
		 Buffer[0][1] = (char*)"成";
		 Buffer[0][2] = (char*)"污";
		 Buffer[1][0] = (char*)"式";
		 Buffer[1][1] = (char*)"托";
		 Buffer[1][2] = (char*)"式";
	 */
	// Buffer[0] = (char*)"戌成污"; 
	// Buffer[0] = (char*)"式托式";	
	Buffer[0] = (char*)" I "; 
	Buffer[1] = (char*)" I  ";
	//戌成污
	//式托式


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	Color = 20;
}


int Enemy::Update()
{
	//TransInfo.Position.x -= 2;

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
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

void Enemy::Release()
{

}