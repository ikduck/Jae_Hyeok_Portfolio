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
	/*
	int Hp;
	*/
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	EnemyBridge() : Speed(0), Color(0) {};
	virtual ~EnemyBridge() {};
};

