#pragma once
#include "Scene.h"

class Object;
class UserInterface;
class Stage : public Scene
{
private:
	Object* pPlayer;
	Object* eEnemy;
	UserInterface* pUI;
	int Check;
	int PB_Dam;
	int E_Hp;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void Enable_UI();

	Stage();
	virtual ~Stage();
};

