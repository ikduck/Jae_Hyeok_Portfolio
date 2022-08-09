#include "Boss.h"
#include "CursorManager.h"
#include "Bridge.h"
#include "EnemyBullet.h"
#include "ObjectManager.h"

Boss::Boss() { }
Boss::Boss(Transform _TransInfo) : Object(_TransInfo) { }
Boss::~Boss() { Release(); }

Object* Boss::Initialize(string _Key)
{
	strKey = _Key;

	// Buffer[0] = (char*)"È£";
	// Buffer[1] = (char*)"¤µ";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	// TransInfo.Scale = Vector3((float)strlen(Buffer[0]),(float)MAX_SIZE);
	TransInfo.Scale = Vector3(3.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);


	return this;
}


int Boss::Update()
{

	/*
	 if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;
	*/

	Fire_EBullet();

	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Boss::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Boss::Release()
{
	::Safe_Delete(pBridge);
}

void Boss::Fire_EBullet()
{
	if (Count <= 20)
		++Count;

	else
		Count = 0;

	if (Count == 10)
	{

		Bridge* pBridge = new EnemyBullet;
		ObjectManager::GetInstance()->AddObject("Bullet2", pBridge);
		ObjectManager::GetInstance()->GetObjectList("Bullet2")->back()->SetPosition(TransInfo.Position);
		// ObjectManager::GetInstance()->GetObjectList("Bullet2")->back();
		((BulletBridge2*)pBridge)->SetD(TransInfo);
	}
}