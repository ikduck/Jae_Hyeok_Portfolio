#pragma once
#include "Scene.h"

class Logo : public Scene
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

	Logo();
	virtual  ~Logo();
};

