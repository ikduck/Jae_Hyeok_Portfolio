#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	//** Bullet의 데이터만 넣음
	// 총알 데미지
	float Speed;
	int Color;
	char* Buffer;
	int PB_Damage;
	int PB_BulletNum;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	
	int GetE_Hp() const { return  PB_Damage; }

	BulletBridge() : Speed(0), Color(0), PB_Damage(0) , PB_BulletNum(0) {};
	virtual ~BulletBridge() {};
};

