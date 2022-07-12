#pragma once
#include "Headers.h"

class CursorManager
{
	// 콘솔의 커서창을 바꿔주는 함수
	/*
public:
	static void SetCurosrPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),  Pos);
		// SetConsoleCursorPosition : 콘솔창의 좌표 
	}	

	static void Draw(float _x, float _y, string _str)
	{
		SetCurosrPosition(_x, _y);
		cout << _str;
	}
	*/ 
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;

		return Instance;
	}
private:
	int BufferIndex;			// ** 버퍼의 인덱스 접근을 위한 변수
	HANDLE hBuffer[2];		// ** 두개의 버퍼 
public:
	void CreateBuffer(const int& _Width, const int& _Height);				// ** 버퍼를 생성 (폭 , 높이)
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);			// ** 그리기 버퍼 (좌표, 출력할 화면 , 컬러값)
	void WriteBuffer(float _x, float _y, int _Value, int  _Color = 15);
	void WriteBuffer(Vector3 _Position, char* _str, int  _Color = 15);		// ** Vector3로 좌표 받아옴
	void WriteBuffer(Vector3 _Position, int _Value, int  _Color = 15);		// ** 
	void FlippingBuffer();			// ** 버퍼 전환
	void ClearBuffer();				// ** 그려진 내용 삭제 
	void DestroyBuffer();				// ** 버퍼 해제
	void SetColor(int _Color);		// ** 문자열 색상 변경
private:
	CursorManager();
public:
	~CursorManager();


};



