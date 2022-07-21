#pragma once
#include "Object.h"

class Bullet2 : public Object
{
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet2(*this); }

	Bullet2();
	Bullet2(Transform _TransInfo);
	virtual ~Bullet2();
};

