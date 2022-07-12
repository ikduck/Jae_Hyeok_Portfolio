#pragma once
#include "Scene.h"

class Menu2 : public Scene
{
private:
	int Color;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	Menu2();
	virtual  ~Menu2();
};

