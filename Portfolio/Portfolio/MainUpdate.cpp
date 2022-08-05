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
	PlayerInfo::GetInstance()->SetPlayerInfo(); // �����Ҷ� �÷��̾� ���� �ʱ�ȭ?
	Prototype::GetInstance()->initialize();
	CursorManager::GetInstance()->CreateBuffer(ConsoleWidthSize, ConsoleHeightSize);
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Inputkey();
	SceneManager::GetInstance()->Update();

	CursorManager::GetInstance()->FlippingBuffer();		// ��°� ������ �Լ��ϳ����� ���
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}

