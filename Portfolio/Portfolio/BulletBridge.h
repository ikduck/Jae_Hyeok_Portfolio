#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	//** Bullet�� �����͸� ����
	// �Ѿ� ������
	float Speed;
	int Color;
	char* Buffer;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	int PB_Damage;

	BulletBridge() : Speed(0), Color(0) , Buffer(nullptr) {};
	virtual ~BulletBridge() {};
};

