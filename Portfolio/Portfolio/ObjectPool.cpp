#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"
#include "CollisionManager.h"
ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;
ObjectPool::ObjectPool() { }
ObjectPool::~ObjectPool()  { }

/*
void ObjectPool::AddObject(string _Key, list<Object*> _List)
{
	EnableList.insert(make_pair(_Key, _List));
}

void ObjectPool::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList.find(_Object->GetKey());

	iter->second.push_back(_Object);
}
*/ 

void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Object->GetKey());

	// DisableList이 마지막 지점일때 
	if (Disableiter == DisableList.end())
	{
		// 새로운 공간 생성후 값 넣어줌
		list<Object*> TempList;
		TempList.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		// 빈 공간에 값을 넣어줌
		Disableiter->second.push_back(_Object);
}

Object* ObjectPool::ThrowObject(string _Key)
{
	// 키 복사해줌
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	// DisableList.end() (키값이 존재하지 않을때) 거나
	// Disableiter->second.size()가 0이면(Disableiter의 list에 원소가 없음) false가 되서 if문의 조건을 성립하지않음
	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		// pObject에 Disableiter의 제일첫 원소를 복사하고
		Object* pObject = Disableiter->second.front();
		// Disableiter의 제일첫 원소를 삭제
		Disableiter->second.pop_front();

		// 초기화
		pObject->Initialize(_Key);
		// pObject를 반환
		return pObject;
	}

	// 조건이 없을시 동작하지 않음
	return nullptr;
}

void ObjectPool::Update()
{
	// 화면에 출력
	// CursorManager::GetInstance()->WriteBuffer(85.0f, 0.0f, (char*)"DisableList : ");
	// CursorManager::GetInstance()->WriteBuffer(100.0f, 0.0f, DisableList["Bullet"].size());
	// 
	// CursorManager::GetInstance()->WriteBuffer(85.0f, 1.0f, (char*)"EnableList : ");
	// CursorManager::GetInstance()->WriteBuffer(100.0f, 1.0f, EnableList["Bullet"].size());

	// 키
	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		// value
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); )
		{
			int result = (*iter2)->Update();

			switch (result)
			{
			case BUFFER_OVER:
			{
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (iter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back((*iter2));
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));

				(*iter).second.erase(iter2);

			}
			case 2:
				// CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다");
				// (*iter).second.erase(iter2);
				
				break;

			default:
				++iter2;
			}
		}
	}
}

// DisableList -> EnableList 키값, 위치값을 알아야 줄수있음	
// DisableList이 10이상이면 EnableList 에넘겨줌 DisableList.secound.size() > 10;	
