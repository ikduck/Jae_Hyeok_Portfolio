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

	// Enemy 삭제 확인 bool
	bool Del_BM;
	bool Del_Player;

	bool Stop_Game;
	bool Stage_Clear;
	bool Stage_Over;

	// stage구현
	int Show_Stage = 0;
	int Count;
	int Count1;
	int E_Count;

	// Player 관련 변수
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

	// 점수 화면 출력할거임
	void Score();
	
	void ShowPlayerLife();

	//게임 끝나면 초기화 함
	void ResetPlayerInfo();
	void GameClear();
	void GameOver();

	Stage();
	virtual ~Stage();
};

