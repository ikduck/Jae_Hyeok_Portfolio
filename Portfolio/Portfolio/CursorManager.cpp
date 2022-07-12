#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;
CursorManager::CursorManager() : BufferIndex(0) { }
CursorManager::~CursorManager() { DestroyBuffer(); }

void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	// ** 커서 설정
	CONSOLE_CURSOR_INFO Cursor;

	Cursor.bVisible = FALSE;		// ** 입력대기 커서 안보이게함
	Cursor.dwSize = 1;				// ** 커서의 사이즈 설정

	COORD Size = { (SHORT)_Width , (SHORT)_Height };			// ** 윈도우 창 사이즈
	SMALL_RECT rect = { 0, 0, (SHORT)_Width, (SHORT)_Height };			// ** 버퍼 사이즈

	// 임시로 버퍼만 만들어서 값을 세팅함		
	for (int i = 0; i < 2; ++i)
	{
		// ** 버퍼 생성
		hBuffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		// ** 버퍼 사이즈 설정
		SetConsoleScreenBufferSize(hBuffer[i], Size);
		// ** 버퍼가 포함될 윈도우 사이즈 설정
		SetConsoleWindowInfo(hBuffer[i], TRUE, &rect);
		// ** 커서 세팅
		SetConsoleCursorInfo(hBuffer[i], &Cursor);
	}
}

void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	DWORD dw;		// 의미없음 - 임시로 생성됨 사용하게 된다면 => 크기값 전달

	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// ** 텍스트 색 변경
	SetColor(_Color);

	// 버퍼에 쓰기 // hBuffer 에 (DWORD)strlen(_str) 크기만큼 보내겟다
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);

}

void CursorManager::WriteBuffer(float _x, float _y, int _Value, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// ** 텍스트 색 변경
	SetColor(_Color);

	char* Buffer = new char[4];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);
	// 버퍼에 쓰기 // hBuffer 에 (DWORD)strlen(_str) 크기만큼 보내겟다
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	DWORD dw;		// 의미없음 - 임시로 생성됨 사용하게 된다면 => 크기값 전달

	COORD CursorPosition = { (SHORT)_Position.x, (SHORT)_Position.y };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	// 버퍼에 쓰
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, int _Value, int _Color)
{
	DWORD dw;		// 의미없음 - 임시로 생성됨 사용하게 된다면 => 크기값 전달

	COORD CursorPosition = { (SHORT)_Position.x, (SHORT)_Position.y };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	char* Buffer = new char[4];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);

	// 버퍼에 쓰
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);
}

void CursorManager::FlippingBuffer()
{
	// 버퍼가 교체됨 
	SetConsoleActiveScreenBuffer(hBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;

	// 반드시 교체한후 지워야함
	ClearBuffer();
}

void CursorManager::ClearBuffer()
{
	DWORD dw;
	COORD Coord = { 0, 0 };

	FillConsoleOutputCharacter(hBuffer[BufferIndex], ' ', ConsoleWidthSize * ConsoleHeightSize, Coord, &dw);
}

void CursorManager::DestroyBuffer()
{
	for(int  i = 0; i < 2; ++i)
		CloseHandle(hBuffer[i]);

}

void CursorManager::SetColor(int _Color)
{
	SetConsoleTextAttribute(hBuffer[BufferIndex], _Color);
}

// 메뉴 UI 만들기