#pragma once
#include "BulletBridge.h"

class PlayerBullet : public BulletBridge
{
private:

public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	PlayerBullet();
	virtual ~PlayerBullet();
};

