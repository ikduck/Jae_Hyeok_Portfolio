// Portfolio - Logo
#include "Headers.h"
#include "MainUpdate.h"
// C��� = ����

int main(void)
{
	system("title ������ - 1945");	

	system("mode con cols=60 lines=50");

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

// Ui�߰�
// Logo 1945 ����ϰ� press space or enter key to start
// Menu ���� ����� ���� �� �׸� enter������ Ȯ�� �� ����
// Scene�� ����� ���� ȭ�� ���?
// Stage ���� ����, ���, ������(�ñر�)
// �Ѿ� ���� �߻� , �� �Ѿ��� �Ʒ��� 

// ������ �Ϻ��ϰ� �����Ѵٰ��ص� ������ �ʹ� ���̶�;;
