#pragma once
#include "Scene.h"
#include "PlayerInfo.h"

class Menu : public Scene
{
private:
	int Color;
	int Count;
	int Pt1;
	PlayerInfo P_Info;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void MoveCount();

	// int GetPt()  { return Pt1; }
	// void SetPt(int _Pt1) { Pt1 = _Pt1; }

	Menu();
	virtual  ~Menu();
};

