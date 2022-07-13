#pragma once
#include "Scene.h"

class Object;
class Menu : public Scene
{
private:
	int Color;
	int Count;
	Player pPlayer;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void MoveCount();

	Menu();
	virtual  ~Menu();
};

