// Portfolio - Logo
#include "Headers.h"
#include "MainUpdate.h"
// C언어 = 수학

int main(void)
{
	system("title 김재혁 - 1945");	

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

// Ui추가
// Logo 1945 출력하고 press space or enter key to start
// Menu 에서 비행기 설명 및 그림 enter누르면 확정 후 시작
// Scene에 비행기 마다 화면 출력?
// Stage 에서 점수, 목숨, 아이템(궁극기)
// 총알 위로 발사 , 적 총알은 아래로 

// 구조를 완벽하게 이해한다고해도 에러가 너무 많이뜸;;
