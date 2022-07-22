#include "Cloud1.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "EnemyBullet.h"
#include "ObjectManager.h"

Cloud1::Cloud1() { }
Cloud1::~Cloud1() { }

void Cloud1::Initialize()
{
	Buffer[0] = (char*)"      ////";
	Buffer[1] = (char*)"////     //// ";
	Buffer[2] = (char*)"    ////";
	// Buffer[3] = (char*)",,                            ,,,";
	// Buffer[4] = (char*)"   ,,,,              ,,,,,,,,,,,";
	// Buffer[5] = (char*)"       ,,,,,,,,,,,,,,,";
	Speed = 2.0f;
	Color = 15;
}

int Cloud1::Update(Transform& TransInfo)
{
	TransInfo.Position.y += Speed;

	return 0;
}

void Cloud1::Render()
{
	for(int i = 0; i < 3; ++i)
	{ 
		CursorManager::GetInstance()->WriteBuffer( 
			pObject->GetPosition().x, pObject->GetPosition().y + i,
			Buffer[i], Color);
	}

}

void Cloud1::Release()
{

}

void Cloud1::SetD(Transform& Info)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), Vector3(40.0f, 30.0f)));

}

/*
      备抚
备抚备抚备抚 
       备抚

*/