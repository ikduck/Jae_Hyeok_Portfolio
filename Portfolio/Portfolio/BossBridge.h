#pragma once
#include "Bridge.h"

class BossBridge : public Bridge
{
protected:
	//** Bullet�� �����͸� ����
	// �Ѿ� ������
	float Speed;
	int Color;
	char* Buffer[6];

	// �Ѿ� �߻� ����
	int Count;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void SetD(Transform& Info)PURE;

	virtual void Fire_EBullet()PURE;

	int E_Hp;

	BossBridge() : Speed(0), Color(0), Count(0) {};
	virtual ~BossBridge() {};
};