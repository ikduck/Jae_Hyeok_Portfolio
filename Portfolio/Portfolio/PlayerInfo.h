#pragma once
#include "Headers.h"

class PlayerInfo
{
protected:
	int PlayerType;

	// int P_HP;
	// int P_Damage;
	// int Score;
private:
	// ΩÃ±€≈Ê ∆–≈œ
	static PlayerInfo* Instance;
	PlayerInfo();
public:
	static PlayerInfo* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new PlayerInfo;

		return Instance;
	}

	void SetPlayerInfo();

	
	void SetPlayerType(int _PlayerType) { PlayerType = _PlayerType; }
	int GetPlayerType() const { return PlayerType; }
	/*
	void SetPlayerHp(int _P_HP) { P_HP = _P_HP; }
	int GetPlayerHp() const { return P_HP; }

	void SetPlayerDamage(int _P_Damage) { P_Damage = _P_Damage; }
	int GetPlayerDamage() const { return P_Damage; }

	void SetScore(int _Score) { Score = _Score; }
	int GetScore() const { return Score; }
	*/

	~PlayerInfo();
};