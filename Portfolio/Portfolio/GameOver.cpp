#include "GameOver.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include "Menu.h"

GameOver::GameOver() : Color(0), Count(0) {  }
GameOver::~GameOver() { }

void GameOver::Initialize()
{
	Color = 15;
}

void GameOver::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(LOGO);
	}
}

void GameOver::Render()
{
	MoveCount();

	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 25.0f, (char*)" ######      ###    ##     ## ########     #######  ##     ## ######## ######## ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 26.0f, (char*)"##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 27.0f, (char*)"##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 28.0f, (char*)"##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 29.0f, (char*)"##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 30.0f, (char*)"##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 31.0f, (char*)" ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##", Color);

	if (Count >= 5 && Count <= 25)
	{
		CursorManager::GetInstance()->WriteBuffer(
			35.0f, 36.0f, (char*)"Press enter", Color);
	}

}

void GameOver::MoveCount()
{
	if (Count <= 25)
		++Count;

	else
		Count = 0;
}

void GameOver::Release()
{
}


