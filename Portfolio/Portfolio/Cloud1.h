#pragma once
#include "CloudBridge.h"

class Cloud1 : public CloudBridge
{
private:
	char* Buffer[];
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void SetD(Transform& Info)override;

	Cloud1();
	virtual ~Cloud1();
};

