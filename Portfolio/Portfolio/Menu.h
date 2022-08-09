#pragma once
#include "Scene.h"
#include "ObjectManager.h"

class Menu : public Scene
{
private:
	int Color;
	int Color1;
	int Color2;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void MoveCount();

	Menu();
	virtual  ~Menu();
};

