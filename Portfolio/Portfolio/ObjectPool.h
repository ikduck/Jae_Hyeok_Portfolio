#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
	ObjectPool();
	// 많이 사용하는 함수이기때문에 주소를 고정하여 사용함 mmorpg같은데서 쓰면 안됨
	static map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;

public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;

		return Instance;
	}

	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	void CatchObject(Object* _Object);
	Object* ThrowObject(string _Key);
	void Update();

	~ObjectPool();
};


// ObjectPool을 만들어서 총알 순환시킴
// 총알을 많이 사용하는 게임은 ObjectPool을 사용해야 최적화가 잘됨 (슈팅,fps)
// 총알이 많지 않은 게임은 ObjectPool을 만들면 비효율적임 (rpg)

// 서버 채널이 다르면 못만나는것처럼 불릿과 플레이어도 stage에 같이 존재해야지 충돌처리를 할수있음