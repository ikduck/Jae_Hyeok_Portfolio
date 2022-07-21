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

	// Enemy ���� Ȯ�� bool
	bool Del_BM;

	// stage����
	int Show_Stage = 0;
	int Count;
	int E_Count;

	int InGame_Score;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void Enable_UI();
	void MoveCount();
	void Bilde_Stage();
	// ���� ȭ�� ����Ұ���
	void Score();

	Stage();
	virtual ~Stage();
};

