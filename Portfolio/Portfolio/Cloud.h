#pragma once
#include "Object.h"

class Cloud : public Object
{
private:
	int Color;
	int Speed;
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Cloud(*this); }

	Cloud();
	Cloud(Transform _TransInfo);
	virtual ~Cloud();
};

