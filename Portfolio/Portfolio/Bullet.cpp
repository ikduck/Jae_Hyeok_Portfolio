#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Bridge.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { Release(); }

Object* Bullet::Initialize(string _Key)
{
	strKey = _Key; // 포인터아님 2바이트짜리 특수문자임

	// Buffer[0] = (char*)"타";
	// Buffer[1] = (char*)"ㅇ";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	//TransInfo.Scale = Vector3((float)strlen(Buffer[0]), (float)MAX_SIZE);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	return this;
}

int Bullet::Update()
{	
	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Bullet::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Bullet::Release()
{
	// 소멸자가 실행되면 저절로 지워지기때문에 Release는 호출할 필요없음
	::Safe_Delete(pBridge);
}

