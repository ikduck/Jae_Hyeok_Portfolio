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

	// DisableList�� ������ �����϶� 
	if (Disableiter == DisableList.end())
	{
		// ���ο� ���� ������ �� �־���
		list<Object*> TempList;
		TempList.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		// �� ������ ���� �־���
		Disableiter->second.push_back(_Object);
}

Object* ObjectPool::ThrowObject(string _Key)
{
	// Ű ��������
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	// DisableList.end() (Ű���� �������� ������) �ų�
	// Disableiter->second.size()�� 0�̸�(Disableiter�� list�� ���Ұ� ����) false�� �Ǽ� if���� ������ ������������
	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		// pObject�� Disableiter�� ����ù ���Ҹ� �����ϰ�
		Object* pObject = Disableiter->second.front();
		// Disableiter�� ����ù ���Ҹ� ����
		Disableiter->second.pop_front();

		// �ʱ�ȭ
		pObject->Initialize(_Key);
		// pObject�� ��ȯ
		return pObject;
	}

	// ������ ������ �������� ����
	return nullptr;
}

void ObjectPool::Update()
{
	// ȭ�鿡 ���
	// CursorManager::GetInstance()->WriteBuffer(85.0f, 0.0f, (char*)"DisableList : ");
	// CursorManager::GetInstance()->WriteBuffer(100.0f, 0.0f, DisableList["Bullet"].size());
	// 
	// CursorManager::GetInstance()->WriteBuffer(85.0f, 1.0f, (char*)"EnableList : ");
	// CursorManager::GetInstance()->WriteBuffer(100.0f, 1.0f, EnableList["Bullet"].size());

	// Ű
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
				// CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�");
				// (*iter).second.erase(iter2);
				
				break;

			default:
				++iter2;
			}
		}
	}
}

// DisableList -> EnableList Ű��, ��ġ���� �˾ƾ� �ټ�����	
// DisableList�� 10�̻��̸� EnableList ���Ѱ��� DisableList.secound.size() > 10;	
