#include "Bullet2.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Bridge.h"

Bullet2::Bullet2() { }
Bullet2::Bullet2(Transform _TransInfo) : Object(_TransInfo) { }
Bullet2::~Bullet2() { Release(); }

Object* Bullet2::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	return this;
}

int Bullet2::Update()
{
	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Bullet2::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Bullet2::Release()
{
	::Safe_Delete(pBridge);
}