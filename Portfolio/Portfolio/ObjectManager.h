#pragma once
#include "Headers.h"

class Object;
class Bridge;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	ObjectManager();
	// map<string, list<Object*>> ObjectList;  //list ����
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

// ��Ȱ��ȭ �Ⱦ��¾ֵ� -> ObjectPool
// C�� ������ �����ϴ� ���� ���������ʾ� �������� ����Ƽ , �𸮾��� �����Ǿ�����

