#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include"Enemy.h"
#include "Bullet.h"

#include "ObjectFactory.h"
#include"CursorManager.h"

Logo::Logo() : Color(0) , Count(0), Count1(0) {  }

Logo::~Logo() { }

void Logo::Initialize()
{
	Color = 15;
}

void Logo::Update()
{
	MoveCount();
	MoveCount2();

	if (Count1 >= 0 && Count1 <= 15)
	{
		Color = 15;
	}
	else if (Count1 >= 16 && Count1 <= 30)
	{
		Color = 9;
	}
	else if (Count1 >= 31 && Count1 <= 45)
	{
		Color = 14;
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{

	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 15.0f, (char*)"  #####  ####### ######  ### #    # ####### ######   ##### ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 16.0f, (char*)" #     #    #    #     #  #  #   #  #       #     # #     #", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 17.0f, (char*)" #          #    #     #  #  #  #   #       #     # #      ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 18.0f, (char*)"  #####     #    ######   #  ###    #####   ######   ##### ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 19.0f, (char*)"	 #    #    #   #    #  #  #   #       #   #         #", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 20.0f, (char*)" #     #    #    #    #   #  #   #  #       #    #  #     #", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.5f, 21.0f, (char*)"  #####     #    #     # ### #    # ####### #     #  ##### ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		10.0f, 22.0f, (char*)"式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式", 15);
	CursorManager::GetInstance()->WriteBuffer(
		10.0f, 23.0f, (char*)"式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式", 15);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 25.0f, (char*)"   #     ######     #          ####### ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 26.0f, (char*)"  ##     #    #     #    #     #      ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 27.0f, (char*)" # #     #    #     #    #     #      ", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 28.0f, (char*)"   #     ######     #    #     #######", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 29.0f, (char*)"   #          #     #######          #", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 30.0f, (char*)"   #     #    #          #     #     #", Color);
	CursorManager::GetInstance()->WriteBuffer(
		21.0f, 31.0f, (char*)" #####    ####           #      ##### ", Color);
	if(Count >= 5 && Count <= 25)
	{
	CursorManager::GetInstance()->WriteBuffer(
		30.0f, 40.0f, (char*)"Press enter to start", 12);
	}

}

void Logo::MoveCount()
{
	if (Count <= 25)
		++Count;

	else
		Count = 0;
}

void Logo::MoveCount2()
{
	if (Count1 < 45)
		++Count1;

	else
		Count1 = 0;
}

void Logo::Release()
{
}



/*
#	              #####           #                       #######
##             #          #         #          #           #
#  #		         #         #          #			#           #
	#			     ######          #			#	         #######
	#			       	         #         #######                       #
	#			      #        #     				    #		     #            #
#####           ####		 		        #			  ######

*/