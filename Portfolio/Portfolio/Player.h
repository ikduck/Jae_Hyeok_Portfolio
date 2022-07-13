#pragma once
#include "Object.h"


class Player : public Object
{
private:
	int Color;
	int Speed;
	int PlayerLife;
	int PlayerType;
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Player(*this); }

	int GetPlayerType() const { return PlayerType; }
	void SetPlayerType(int _PlayerType) { PlayerType = _PlayerType; }

	Player();
	Player(Transform _TransInfo);
	virtual ~Player();
};

