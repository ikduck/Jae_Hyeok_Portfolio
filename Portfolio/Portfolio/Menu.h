#pragma once
#include "Scene.h"
#include "PlayerInfo.h"

class Menu : public Scene
{
private:
	int Color;
	int Count;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void MoveCount();

	Menu();
	virtual  ~Menu();
};

