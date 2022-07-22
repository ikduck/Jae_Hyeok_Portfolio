#pragma once
#include "Bridge.h"

class CloudBridge : public Bridge
{
protected:
	float Speed;
	int Color;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void SetD(Transform& Info)PURE;

	CloudBridge() : Speed(0), Color(0) {};
	virtual ~CloudBridge() {};

};