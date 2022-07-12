#pragma once
#include "UserInterface.h"

class ScrollBox : public UserInterface
{
public:
	virtual void Initialize();
	virtual int Update();
	virtual void Render();
	virtual void Release();

	ScrollBox();
	ScrollBox(Transform _TransInfo);
	virtual ~ScrollBox();
};