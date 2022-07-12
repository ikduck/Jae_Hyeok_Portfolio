#pragma once
#include "Headers.h"

class Object;
class Bridge;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	ObjectManager();
	// map<string, list<Object*>> ObjectList;  //list 선언
	map<string, list<Object*>>* EnableList;

public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}

	void AddObject(string _Key);
	void AddObject(string _Key, Bridge* _Bridge);
	list<Object*>* GetObjectList(string _Key);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where, Object* _Object);
	void Update();
	void Render();

	~ObjectManager();
};

// 비활성화 안쓰는애들 -> ObjectPool
// C는 서버에 접근하는 것을 지원하지않아 만들어야함 유니티 , 언리얼은 구현되어있음

