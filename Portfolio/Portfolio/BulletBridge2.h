#pragma once
#include "Bridge.h"

class BulletBridge2 : public Bridge
{
protected:
	//** Bullet의 데이터만 넣음
	// 총알 데미지
	float Speed;
	int Color;
	char* Buffer;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void SetD(Transform& TransInfo)PURE;

	int EB_Damage;

	BulletBridge2() : Speed(0), Color(0), Buffer(nullptr) {};
	virtual ~BulletBridge2() {};
};
