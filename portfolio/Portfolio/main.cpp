// *** Portfolio Enemy Bullet change
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

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

// ���� ����� �����ȵ�

// �� ���� ���κп��� �Ѿ� ������
// enemy ü�� ����ȵ� (�������� �ȵǼ� �׷���?)
// stage Player�� �¾����� 
// Logo���� ��� �帣�� 
// Menu���� �÷��̾� Ÿ�� ������ �ְ�
// ui �߰� �ؾߵ�