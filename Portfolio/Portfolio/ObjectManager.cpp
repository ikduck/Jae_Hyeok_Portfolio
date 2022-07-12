#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Object.h"
#include "ObjectPool.h"
#include "ObjectFactory.h"
#include "Bullet.h"
#include "Prototype.h"
#include "Bridge.h"

ObjectManager* ObjectManager::Instance = nullptr;
ObjectManager::ObjectManager() 
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager() { }

void ObjectManager::AddObject(string _Key)
{
	// pObject�� DisableList�� ����� �ּҰ��� �����ͼ� ����
	Object* pObject = ObjectPool::GetInstance()->ThrowObject(_Key);

	// pObject�� �ƹ��͵� ������ clone�� �������
	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->PrototypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	// �Ȱ��� EnableList�� ���� ������ ������ְ� ������ �׳� ����
	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddObject(string _Key, Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject(_Key);

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->PrototypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	// EnableList�� Ű ã��
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	// EnableList�� Ű�� ������ �����϶�
	if (iter == EnableList->end())
		// nullptr ��ȯ
		return nullptr;

	// value �ּҰ��� ��ȯ
	return  &iter->second;
	
}

// ��ġ�� �ּҰ��� �޾ƿ�
list<Object*>::iterator ObjectManager::ThrowObject(list<Object*>::iterator _Where, Object* _Object)
{
	// EnableList�� Ű���� iter�� ����
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	// EnableList�� ������ �����϶� ��ġ ��ȯ
	if (iter == EnableList->end())
		return _Where;

	// CatchObject�� ���� ObjectPool�� ����
	ObjectPool::GetInstance()->CatchObject(_Object);
	// EnableList���� ����
	return iter->second.erase(_Where);
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
	}
}
