#include "Prototype.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

Prototype* Prototype::Instance = nullptr;
Prototype::Prototype() { }
Prototype::~Prototype() { }

void Prototype::initialize()
{
	Transform Info;
	
	// �����ϰ� �ʱ�ȭ����  �ٷ� ������ (������ ����)
	string Key = "Player";
	PrototypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "Enemy";
	PrototypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	PrototypeList[Key] = (new Bullet(Info))->Initialize(Key);

}

Object* Prototype::PrototypeObject(string _Key)
{
	map<string, Object*>::iterator iter = PrototypeList.find(_Key);
	
	// PrototypeList�� �ƹ��͵� ������ ������������
	if (iter == PrototypeList.end())
		return nullptr;

	// ���������� �ּҰ��� ��ȯ��
	return iter->second;
}