#include "Enemy.h"
#include "CursorManager.h"
#include "Bridge.h"

Enemy::Enemy() { }
Enemy::Enemy(Transform _TransInfo) : Object(_TransInfo) { }
Enemy::~Enemy() { Release(); }

Object* Enemy::Initialize(string _Key)
{
	strKey = _Key;

	// Buffer[0] = (char*)"호";
	// Buffer[1] = (char*)"ㅅ";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f); 
 	// TransInfo.Scale = Vector3((float)strlen(Buffer[0]),(float)MAX_SIZE);
	TransInfo.Scale = Vector3(3.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);


	return this;
}


int Enemy::Update()
{

	/*
	 if (TransInfo.Position.x <= 0)
	 	return BUFFER_OVER;
	*/

	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Enemy::Render()
{	
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	::Safe_Delete(pBridge);
}

// 삭제방법은 여러가지가 있음 - stage에서 지울수도있고 