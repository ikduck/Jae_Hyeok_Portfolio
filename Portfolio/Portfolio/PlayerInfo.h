#pragma once
#include "Headers.h"

class PlayerInfo
{
protected:
	int PlayerType;
public:

	void SetPlayerType(int _PlayerType) { PlayerType = _PlayerType; }
	int GetPlayerType() const { return PlayerType; }

	PlayerInfo() : PlayerType(0) {}
	virtual ~PlayerInfo() {}
};