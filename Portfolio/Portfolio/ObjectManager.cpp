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
	// pObject에 DisableList에 저장된 주소값을 가져와서 넣음
	Object* pObject = ObjectPool::GetInstance()->ThrowObject(_Key);

	// pObject에 아무것도 없으면 clone을 만들어줌
	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->PrototypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	// 똑같이 EnableList에 공간 없으면 만들어주고 있으면 그냥 넣음
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
	// EnableList의 키 찾기
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	// EnableList의 키가 마지막 지점일때
	if (iter == EnableList->end())
		// nullptr 반환
		return nullptr;

	// value 주소값을 반환
	return  &iter->second;
	
}

// 위치와 주소값을 받아옴
list<Object*>::iterator ObjectManager::ThrowObject(list<Object*>::iterator _Where, Object* _Object)
{
	// EnableList의 키값을 iter에 넣음
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	// EnableList가 마지막 지점일때 위치 반환
	if (iter == EnableList->end())
		return _Where;

	// CatchObject를 실행 ObjectPool에 전달
	ObjectPool::GetInstance()->CatchObject(_Object);
	// EnableList에서 삭제
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
