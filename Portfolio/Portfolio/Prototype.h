#pragma once
#include "Headers.h"

class Object;
class Prototype
{
private:
	static Prototype* Instance;
	Prototype();
	map<string, Object*> PrototypeList;
public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype;

		return Instance;
	}

	void initialize();
	Object* PrototypeObject(string _Key);

	~Prototype();
};

