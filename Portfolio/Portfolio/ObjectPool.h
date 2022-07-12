#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
	ObjectPool();
	// ���� ����ϴ� �Լ��̱⶧���� �ּҸ� �����Ͽ� ����� mmorpg�������� ���� �ȵ�
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


// ObjectPool�� ���� �Ѿ� ��ȯ��Ŵ
// �Ѿ��� ���� ����ϴ� ������ ObjectPool�� ����ؾ� ����ȭ�� �ߵ� (����,fps)
// �Ѿ��� ���� ���� ������ ObjectPool�� ����� ��ȿ������ (rpg)

// ���� ä���� �ٸ��� �������°�ó�� �Ҹ��� �÷��̾ stage�� ���� �����ؾ��� �浹ó���� �Ҽ�����