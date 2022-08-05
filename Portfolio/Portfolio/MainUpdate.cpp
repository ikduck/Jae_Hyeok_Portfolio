#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Prototype.h"
#include "PlayerInfo.h"

MainUpdate::MainUpdate()  { }
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	PlayerInfo::GetInstance()->SetPlayerInfo(); // 시작할때 플레이어 정보 초기화?
	Prototype::GetInstance()->initialize();
	CursorManager::GetInstance()->CreateBuffer(ConsoleWidthSize, ConsoleHeightSize);
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Inputkey();
	SceneManager::GetInstance()->Update();

	CursorManager::GetInstance()->FlippingBuffer();		// 출력과 변경을 함수하나에서 사용
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}

