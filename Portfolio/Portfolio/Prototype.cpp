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
	
	// 생성하고 초기화한후  바로 보내줌 (디자인 패턴)
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
	
	// PrototypeList에 아무것도 없으면 동작하지말고
	if (iter == PrototypeList.end())
		return nullptr;

	// 문제없으면 주소값을 반환함
	return iter->second;
}