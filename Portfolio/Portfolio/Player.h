#pragma once
#include "Object.h"
#include "ObjectManager.h"

class Player : public Object
{
private:
	int Color;
	int Speed;
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Player(*this); }

	Player();
	Player(Transform _TransInfo);
	virtual ~Player();
};

