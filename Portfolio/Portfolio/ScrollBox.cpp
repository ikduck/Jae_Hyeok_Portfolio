#include "ScrollBox.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "Stage.h"
#include "PlayerInfo.h"
ScrollBox::ScrollBox() : Select(0) { }
ScrollBox::ScrollBox(Transform _TransInfo) : Select(0) { }
ScrollBox::~ScrollBox() { Release(); }

void ScrollBox::Initialize()
{
	strKey = "ScrollBox";

	/*
	TextureList.push_back("┌──────────┐");
	TextureList.push_back("│　　　　　　　　　　│");
	TextureList.push_back("│　　　　　　　　　　│");
	TextureList.push_back(" ／￣￣ ￣￣￣￣／￣＼｜");
	TextureList.push_back("｜　　　　　　　｜┼  ｜");
	TextureList.push_back(" ＼______________＼__／");
	*/

	// ▶
	/*
	TextureList.push_back("┌───────────┐");
	TextureList.push_back("│　     1. 게임 종료　  　 │");
	TextureList.push_back("│　　　  　　　　　　　 │");
	TextureList.push_back("│　  2.  Retrun Game     │ ");
	TextureList.push_back("│　　  　　　　　　　　 │");
	TextureList.push_back("└───────────┚");
	*/

	TransInfo.Position = Vector3(60.0f, 5.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(14.0f, 2.0f);
}

int ScrollBox::Update()
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	// auto iter = TextureList.begin();
	// ++iter;

	/*
	if (dwKey & KEY_CTRL)
	{
		//if (TransInfo.Position.x > 30)
		//{
		//}
		TextureList.insert(iter, "│　　　　　　　　　　│");
		++TransInfo.Scale.y;	
	}
	*/

	if (dwKey & KEY_RIGHT)
	{
		Select = 1;
	}
	if (dwKey & KEY_LEFT)
	{
		Select = 0;
	}

	if (dwKey & KEY_ENTER)
	{
		if (Select == 0)
		{
			exit(0);
		}
		if (Select == 1)
		{
			PlayerInfo::GetInstance()->SetGameRE(false);
		}
	}

	return 0;
}

void ScrollBox::Render()
{
	/*
	for (int i = 0; i < TextureList.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y + i,
			TextureList[i], 15);
	}
	*/

	// CursorManager::GetInstance()->WriteBuffer(
	// 	TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
	// 	TransInfo.Position.y + i,
	// 	TextureList[i], 15);
	
	// CursorManager::Draw(
	// 	TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
	// 	TransInfo.Position.y + i,
	// 	TextureList[i]);
	if(PlayerInfo::GetInstance()->GetGameRE() == true)
	{
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 27.0f, (char*)"┌───────────┐", 15);
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 28.0f, (char*)"│　     1. 게임 종료　 │", 15);
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 29.0f, (char*)"│　　　  　　　　　　　│", 15);
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 30.0f, (char*)"│　  2.  Retrun Game   │", 15);
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 31.0f, (char*)"│　　  　　　　　　　　│", 15);
		CursorManager::GetInstance()->WriteBuffer(
			24.0f, 32.0f, (char*)"└───────────┚", 15);

		if (Select == 0)
		{
			CursorManager::GetInstance()->WriteBuffer(
				26.0f, 28.0f, (char*)" ▶", 15);
		}
		if (Select == 1)
		{
			CursorManager::GetInstance()->WriteBuffer(
				26.0f, 30.0f, (char*)" ▶", 15);
		}
	}
}

void ScrollBox::Release()
{
}

// 브릿지 패턴
// 오브젝트 풀 패턴
// clone 패턴
// 맵 ->  더블버퍼