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
	int E_Hp;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	int GetE_Hp() const { return  E_Hp; }

	EnemyBridge() : Speed(0), Color(0), E_Hp(0) {};
	virtual ~EnemyBridge() {};
};

