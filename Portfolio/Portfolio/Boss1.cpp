#include "Boss1.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "EnemyBullet.h"
#include "ObjectManager.h"

Boss1::Boss1() { }
Boss1::~Boss1() { }

void Boss1::Initialize()
{
	Buffer[0] = (char*)"ㅁ";
	Buffer[1] = (char*)"ㅁ";
	Buffer[2] = (char*)"ㅁ";
	Buffer[3] = (char*)"ㅁ";
	Buffer[4] = (char*)"ㅁ";
	Buffer[5] = (char*)"ㅁ";
	/*

	*/
	// list로 , Player는 따로 빼서  , Monster도 따로 만들어주기

	Speed = 0.3f;
	Color = 12;
	E_Hp = 1;
}

int Boss1::Update(Transform& TransInfo)
{
	// TransInfo.Direction = MathManager::GetDirection(
	// 	TransInfo.Position, Vector3(40.0f, 60.0f));
	// Fire_EBullet();

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	TransInfo.Position.y += Speed;

	return 0;
}

void Boss1::Render()
{
	// if E_HP <= 0;  터지는 모션 아니면 평소모션
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + i,
			Buffer[i], Color);
	}
}

void Boss1::Release()
{

}

void Boss1::SetD(Transform& Info)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), Vector3(40.0f, 30.0f)));

}