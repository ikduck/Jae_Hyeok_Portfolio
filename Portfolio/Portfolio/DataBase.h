#pragma once

class DataBase
{
private:
	int PlayerType;

public:

	int GetPlayerType() const { return PlayerType; }
	void SetPlayerType(int _PlayerType) { PlayerType = _PlayerType; }


	DataBase() {}
	~DataBase() {}
};
