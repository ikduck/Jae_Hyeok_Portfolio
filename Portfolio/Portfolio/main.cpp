// *** Framework v14.0	( Bridge )
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"
// Portfolio
// ���� , ���� ����
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

// ���� - �ּҸ� �ٲܼ� ����
// ���� - �ּҰ� �ٲ��� ����, �����ϴ� ���� �ƴ� �ڽ� �ּҿ� �����ؼ� �ִ���

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
	system("title ������ - 1945");	
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

// main�� �ΰ��� ���� �������α׷��� ���ư��� main�� �����Ҽ�����
// ������ �Ȳ���� ���鶧�� ����� background�� ���� �ҷ��ͼ� ���
// ����ó����ɻ� �ʱ�

// ���� ���̽�
// 2~3��� �𸮾�5
// ��Ÿ���� �����

// c c++ ����
// ����Ƽ ����
// ���̽�
// �ڵ��׽�Ʈ

// ���� 3�� ��ǻ�� ����