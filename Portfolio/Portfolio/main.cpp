// *** Portfolio Enemy Bullet change
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

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

// 변수 사용이 전혀안됨

// 맵 제일 끝부분에서 총알 느려짐
// enemy 체력 적용안됨 (얕은복사 안되서 그런듯?)
// stage Player가 맞았을때 
// Logo에서 배경 흐르게 
// Menu에서 플레이어 타입 받을수 있게
// ui 추가 해야됨