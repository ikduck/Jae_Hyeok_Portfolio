#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Color;
	int Speed;
	char SelectPlayer;
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	char GetPlayer() const { return SelectPlayer;  }
	void SetScale(char _SelectPlayer) { SelectPlayer = _SelectPlayer; }

	virtual Object* Clone()override { return new Player(*this); }

	Player();
	Player(Transform _TransInfo);
	virtual ~Player();
};

