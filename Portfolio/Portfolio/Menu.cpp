#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include "Player.h"
#include "PlayerInfo.h"

Menu::Menu() : Color(0) { }
Menu::~Menu() { }

void Menu::Initialize()
{
	Color = 10;
	Color1 = 15;
	Color2 = 9;
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey(); 

	if (dwKey & KEY_RIGHT)
	{
		PlayerInfo::GetInstance()->SetPlayerType(1);
		SceneManager::GetInstance()->SetScene(MENU2);
	}

	if (dwKey & KEY_ENTER) 
	{
		SceneManager::GetInstance()->SetScene(STAGE); 
	}
}

void Menu::Render()
{
	// 비행기 이미지
	CursorManager::GetInstance()->WriteBuffer(
		10.0f, 3.0f, (char*)"          .~ ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		15.0f, 4.0f, (char*)"    .;=!", Color);
	CursorManager::GetInstance()->WriteBuffer(
		15.0f, 5.0f, (char*)"    ,*!=; ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		15.0f, 6.0f, (char*)"   ,;:!*", Color);
	CursorManager::GetInstance()->WriteBuffer(
		15.0f, 7.0f, (char*)"   -:~!*.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 8.0f, (char*)"    ..,;:..... .~:~!#! ....~:-...", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 9.0f, (char*)"    .,,$#$:;####=,,*:~;=*~=##@=:;##!-,.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		1.0f, 10.0f, (char*)"    -~~=$~~$$=$=*~*:~;$* :==$=~!##=;~~.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 11.0f, (char*)"     $*:~!*    ,*:~;$*    -;~;=;.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 12.0f, (char*)"	#*:~;$-   ,*:~;=;    -:~;=#;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 13.0f, (char*)"	#*;~!$~   ,==*=;     ,:~!=@;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 14.0f, (char*)"	$*;~!$~-;.-$@#$!.,. .~;:!=@;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		2.0f, 15.0f, (char*)"    .,=;~~;!:!;;;=###*;;:-~;:~:*#;.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		2.0f, 16.0f, (char*)"  .,:;=;~~;;-~~~:=$*$*:~--~;:~:**!~.....,,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 17.0f, (char*)"--~~!!;~;::::;;=$*$*;;:::;;:!*;~--~-~:;:-.....,,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 18.0f, (char*)"::::!**!;:;;;;;*=!$*;;;;;;!*=*!:::::~~~~~--~~:;;-.,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 19.0f, (char*)";;;;!=$=;;;;;;;!!:*!;;;;;;!$$*!;;;;;;;:::::~~~~~~~!~", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 20.0f, (char*)"::::!=$=;;;;;;;!=;=;;;;;;;!$$*!:::::::::::::::::::;#.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 21.0f, (char*)"~~~~!===*;:::::;=;=::::::!*$$=;~~~~~~~~~~~~~~~~~:;*@.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 22.0f, (char*)"~~~~!=**=:~~~~:;*;*:~~~~:!==$=;~~~~--~~~~~~~~~:;*=@*", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 23.0f, (char*)"----*=*==~~~~~~:*;*~~~~~~;==$=;------~~~::;!!*=$$=!.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 24.0f, (char*)"~--~*=$$=----~~:!;*~~~---;$$$=;--~~:;!!**=$@@#*!:,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 25.0f, (char*)"*!!;=$$$=~------:!;------;$$$$*!!**=###=!!!!;:.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 26.0f, (char*)"$$#$$$$$=*!!;:~~~!~~::;!!=$=$$##@#$$*;:,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 27.0f, (char*)"~-~*$$**$@$;::=*=$**=$=*##=*=#=;;:~-.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 28.0f, (char*)"   -*$**$#-  .;;;;;;;;~,;==*=#;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 29.0f, (char*)"	;$*=##.             ,*$*=;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 30.0f, (char*)"	*$**$#.             -=$*=,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 31.0f, (char*)"	=!!**$-             ~=***=", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 32.0f, (char*)"    =:!!;$*             ~*!!!!$:", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 33.0f, (char*)"    =:!!;$$             ~*!!;!$", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 34.0f, (char*)"    =;!!;$$             ~=!!!*$,", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 35.0f, (char*)"    #=!!*@$             #=!!*@$", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 36.0f, (char*)"    @$!*#@$             @$!*#@$", Color);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 37.0f, (char*)"   ~=###@====*~~;!====$#@@@##@#~", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 38.0f, (char*)"  =*$=******!!!**********===$;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 39.0f, (char*)"  ::!;;;;;;;;;;;;;;;;;;;;**:*#:", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 40.0f, (char*)"  ::!;;;;;;;;;;;;;;;;;;;;**:*#:", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 41.0f, (char*)"  *;!;;;;;;;;;;;;;;;;;;;;**!#*.", Color);
	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 42.0f, (char*)"  *$#####@##@@@@#@@@###@###@@;", Color);
	CursorManager::GetInstance()->WriteBuffer(
		0.0f, 44.0f, (char*)"────────────────────────────────────────", Color1);

	// select 버튼
	CursorManager::GetInstance()->WriteBuffer(
		9.5f, 45.0f, (char*)" #########", 14);
	CursorManager::GetInstance()->WriteBuffer(
		11.5f, 46.0f, (char*)"#     #", 14);
	CursorManager::GetInstance()->WriteBuffer(
		12.5f, 47.0f, (char*)"#   #", 14);
	CursorManager::GetInstance()->WriteBuffer(
		13.5f, 48.0f, (char*)"# #", 14);
	CursorManager::GetInstance()->WriteBuffer(
		14.5f, 49.0f, (char*)"#", 14);

	// 비행기 선택
	CursorManager::GetInstance()->WriteBuffer(
		11.5f, 52.0f, (char*)"┼┴┼", Color2);
	CursorManager::GetInstance()->WriteBuffer(
		11.5f, 53.0f, (char*)"├─┤", Color2);
		
	CursorManager::GetInstance()->WriteBuffer(
		36.5f, 52.0f, (char*)"─┼─", Color);
	CursorManager::GetInstance()->WriteBuffer(
		36.5f, 53.0f, (char*)"  ┴  ", Color);

	CursorManager::GetInstance()->WriteBuffer(
		61.5f, 51.0f, (char*)"┌─────┐", Color1);
	CursorManager::GetInstance()->WriteBuffer(
		61.5f, 52.0f, (char*)"│ comming  │", Color1);
	CursorManager::GetInstance()->WriteBuffer(
		61.5f, 53.0f, (char*)"│   soon   │", Color1);
	CursorManager::GetInstance()->WriteBuffer(
		61.5f, 54.0f, (char*)"└─────┘ ", Color1);
	// 80 3개 3 

	CursorManager::GetInstance()->WriteBuffer(
		59.0f, 7.0f, (char*)"Lightning", 9);
	CursorManager::GetInstance()->WriteBuffer(
		60.0f, 9.0f, (char*)"P - 38", 15);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 10.0f, (char*)"CREW: 1 LEMGTH : 11.53m", 15);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 11.0f, (char*)"   WIMGSPAM : 15.85m", 15);

	CursorManager::GetInstance()->WriteBuffer(
		47.0f, 34.0f, (char*)"MAX OUTPUT : 1600hp/3100rpm", 15);
	CursorManager::GetInstance()->WriteBuffer(
		47.0f, 35.0f, (char*)" MAX SPEED : 666km/h7620m", 15);
	CursorManager::GetInstance()->WriteBuffer(
		47.0f, 36.0f, (char*)"        WEIGHT : 7435kg", 15);
}

/*

*/

void Menu::MoveCount()
{
	/*
	if (Count <= 25)
		++Count;

	else
		Count = 0;
	*/
}

void Menu::Release()
{

}

