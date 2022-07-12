#pragma once
#include "Headers.h"

class Bridge;
class Object
{
protected:
	// 어디에서든지 접근할수 있기 때문에 에러가 생기면 찾기 굉장히 어려움
	// static을 사용한다는 지뢰를 하나 심는다고 생각하면됨(편한만큼 리스크가 크다)
	// static list<Object*> BulletList;

	Transform TransInfo;
	string strKey;
	char* Buffer[MAX_SIZE];
	Bridge* pBridge; 
public:
	virtual Object* Initialize(string _Key)PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	string GetKey() const { return strKey; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetScale(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }

	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }

public:
	Object();
	Object(Transform _TransInfo);
	virtual ~Object();
};



// L value -> 뭔가를 담을수 있는 것 , int i 
// R value -> 담을수 없는 것  , 120