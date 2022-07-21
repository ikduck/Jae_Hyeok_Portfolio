#pragma once
#include "BulletBridge2.h"

class EnemyBullet : public BulletBridge2
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void SetD(Transform& TransInfo)override;

	EnemyBullet();
	virtual ~EnemyBullet();
};

