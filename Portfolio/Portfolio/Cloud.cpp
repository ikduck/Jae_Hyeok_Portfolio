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
Cloud::~Cloud() { }

Object* Cloud::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(3.0f, 3.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	CBuffer[0] = (char*)"     ,,,,,     ";
	CBuffer[1] = (char*)",,,,,     ,,,,,";
	CBuffer[2] = (char*)"     ,,,,,";


	Speed = 2.0f;
	Color = 8;  // 9 ÆÄ¶û

	return this;
}

int Cloud::Update()
{
	TransInfo.Position.y += Speed;

	return 0;
}

void Cloud::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			CBuffer[i], Color);
	}
}

void Cloud::Release()
{

}

/*
	     ,,,,,       ,,,,
     ,,,      ,,,,,,,     ,,,,
,,,,                        ,,
,,                            ,,,
   ,,,,              ,,,,,,,,,,,
       ,,,,,,,,,,,,,,,
*/