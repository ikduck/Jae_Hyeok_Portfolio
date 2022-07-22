#include "Cloud.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "PlayerBullet.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Menu.h"
#include "Menu2.h"

Cloud::Cloud() { }
Cloud::Cloud(Transform _TransInfo) : Object(_TransInfo), Color(0), Speed(0) { }
Cloud::~Cloud() { Release(); }

Object* Cloud::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(3.0f, 3.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Speed = 3.0f;
	Color = 15;  // 9 ÆÄ¶û

	return this;
}

int Cloud::Update()
{
	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Cloud::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Cloud::Release()
{
	::Safe_Delete(pBridge);
}

/*
	     ,,,,,       ,,,,
     ,,,      ,,,,,,,     ,,,,
,,,,                        ,,
,,                            ,,,
   ,,,,              ,,,,,,,,,,,
       ,,,,,,,,,,,,,,,
*/