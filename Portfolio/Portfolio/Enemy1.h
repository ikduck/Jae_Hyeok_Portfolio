#pragma once
#include "EnemyBridge.h"

class Enemy1 : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;


	// void DieEnemy();

	// int GetE_Hp() const { return  E_Hp; }

	Enemy1();
	virtual ~Enemy1();
};
