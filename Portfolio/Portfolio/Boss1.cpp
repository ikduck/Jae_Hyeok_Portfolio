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
	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";
	Buffer[2] = (char*)"��";
	Buffer[3] = (char*)"��";
	Buffer[4] = (char*)"��";
	Buffer[5] = (char*)"��";
	/*

	*/
	// list�� , Player�� ���� ����  , Monster�� ���� ������ֱ�

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
	// if E_HP <= 0;  ������ ��� �ƴϸ� ��Ҹ��
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