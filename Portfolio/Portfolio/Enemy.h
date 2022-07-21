#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
	int Count = 0;

public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }

	void Fire_EBullet();
	
	Enemy();
	Enemy(Transform _TransInfo);
	virtual ~Enemy();
};
