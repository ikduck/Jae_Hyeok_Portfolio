// *** Framework v14.0	( Bridge )
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"
// Portfolio
// 동적 , 정적 설명
/*
class AAA
{
public:
	int Number;
	static int Num;
};

class BBB : public AAA
{

}; 

class CCC : public AAA
{

};

// 동적 - 주소를 바꿀수 있음
// 정적 - 주소가 바뀌지 않음, 공유하는 것이 아님 자신 주소에 복사해서 넣는중

BBB b;
b.Number = 10;
b.Num = 100;

CCC c;
c.Number = 100;
c.Num = 1000;

cout << b.Number << endl;
cout << c.Number << endl;
cout << b.Num << endl;
cout << c.Num << endl;
*/ 

int main(void)
{
	system("title 김재혁 - 1945");	
	system("mode con cols=80 lines=60");

	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();
			Main.Render();
		}
	}

 	return 0;
 }

// main을 두개를 만들어서 보안프로그램이 돌아가는 main을 설정할수있음
// 영상이 안끊기게 만들때도 사용함 background에 먼저 불러와서 출력
// 정보처리기능사 필기

// 현재 파이썬
// 2~3년뒤 언리얼5
// 메타버스 가즈앗

// c c++ 포폴
// 유니티 포폴
// 파이썬
// 코딩테스트

// 대학 3년 컴퓨터 공학