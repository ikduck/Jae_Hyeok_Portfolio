#pragma once
#include "Object.h"

class Boss : public Object
{
private:
	int Count = 0;

public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Boss(*this); }

	void Fire_EBullet();

	Boss();
	Boss(Transform _TransInfo);
	virtual ~Boss();
};