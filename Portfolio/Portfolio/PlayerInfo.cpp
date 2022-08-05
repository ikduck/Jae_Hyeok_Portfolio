#include "PlayerInfo.h"

PlayerInfo* PlayerInfo::Instance = nullptr;
PlayerInfo::PlayerInfo() : PlayerType(0) {} // : PlayerType(0), P_HP(0), P_Damage(0), Score(0) { }
PlayerInfo::~PlayerInfo() {}

void PlayerInfo::SetPlayerInfo()
{
	PlayerType = 0;
	// P_HP = 2;
	// P_Damage = 1;
	// Score = 0;
}
