#pragma once
#include "BossBridge.h"

class Boss1 : public BossBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void SetD(Transform& Info)override;
	virtual void Fire_EBullet()override;

	// int GetE_Hp() const { return  E_Hp; }

	Boss1();
	virtual ~Boss1();
};