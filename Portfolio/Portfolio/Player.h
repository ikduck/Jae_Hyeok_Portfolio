#pragma once
#include "Object.h"
#include "PlayerInfo.h"

class Player : public Object
{
private:
	int Color;
	int Speed;
	PlayerInfo P_Info;
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	int P_HP;
	virtual Object* Clone()override { return new Player(*this); }

	Player();
	Player(Transform _TransInfo);
	virtual ~Player();
};

