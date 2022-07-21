#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	//** Bullet의 데이터만 넣음
	// 총알 데미지
	float Speed;
	int Color;
	char* Buffer[MAX_SIZE];

	// 총알 발사 변수
	int Count;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void SetD(Transform& Info)PURE;

	virtual void Fire_EBullet()PURE;

	int E_Hp;

	EnemyBridge() : Speed(0), Color(0) , Count(0) {};
	virtual ~EnemyBridge() {};
};

