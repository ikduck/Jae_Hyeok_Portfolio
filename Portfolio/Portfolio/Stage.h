#pragma once
#include "Scene.h"

class Object;
class UserInterface;
class Player;
class Stage : public Scene
{
private:
	Object* pPlayer;
	Object* eEnemy;
	Object* bCloud;
	UserInterface* pUI;

	int Check;
	// int PB_Dam;

	// Enemy ���� Ȯ�� bool
	bool Del_BM;
	bool Del_Player;

	bool Stop_Game;

	// stage����
	int Show_Stage = 0;
	int Count;
	int E_Count;

	// Player ���� ����
	int InGame_Score;
	int P_HP;
	int PB_Damage;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void Enable_UI();
	void MoveCount();
	void Bilde_Stage();
	void Bilde_BackGround();
	// ���� ȭ�� ����Ұ���
	void Score();
	
	void ShowPlayerLife();

	//���� ������ �ʱ�ȭ ��
	void ResetPlayerInfo();
	void GameClear();
	void GameOver();

	Stage();
	virtual ~Stage();
};

