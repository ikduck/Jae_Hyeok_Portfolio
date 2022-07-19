#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	//** Bullet�� �����͸� ����
	// �Ѿ� ������
	float Speed;
	int Color;
	char* Buffer[MAX_SIZE];


public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	int E_Hp;

	EnemyBridge() : Speed(0), Color(0) {};
	virtual ~EnemyBridge() {};
};

