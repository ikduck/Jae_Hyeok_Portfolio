#include "SceneManager.h"
// #include "Scene.h" // �߻�Ŭ�������� �����͵� �ǹ̰� ����
// �Ʒ� �������� �����ͼ� �پ��ϰ� ����Ұ���(������)
#include "Logo.h"
#include "Menu.h"
#include "Menu2.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;
SceneManager::SceneManager() : SceneState(nullptr) { }
SceneManager::~SceneManager() { Release(); }

// ���� �Ŵ��� (����Ȯ�� ����)
void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;

	case SCENEID::MENU:
		SceneState = new Menu;
		break;

	case SCENEID::MENU2:
		SceneState = new Menu2;
		break;

	case SCENEID::STAGE:
		SceneState = new Stage;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;

	}
	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);
}
