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

	list<Object*>* pBulletList;
	list<Object*>* pBulletList2;
	list<Object*>* pEnemyList;
	list<Object*>* pCloudList;

	int Check;
	// int PB_Dam;

	// Enemy ���� Ȯ�� bool
	bool Del_BM;
	bool Del_Player;

	bool Stop_Game;
	bool Stage_Clear;
	bool Stage_Over;

	// stage����
	int Show_Stage = 0;
	int Count;
	int Count1;
	int E_Count;

	// Player ���� ����
	bool B_Player;

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
	void MoveCount_Stage();

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

