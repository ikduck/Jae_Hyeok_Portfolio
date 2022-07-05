#pragma once
#include "Header.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance; 
	SceneManager();
	Scene* SceneState;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}

	void SetScene(SCENEID _SceneState);
	void Update();
	void Render();
	void Release();

	~SceneManager();
};

