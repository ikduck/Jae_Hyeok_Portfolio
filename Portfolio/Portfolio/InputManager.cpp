#include "InputManager.h"

// static으로 사용할때는 전역선언 해줘야함 
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0) { }
InputManager::~InputManager() { }

void InputManager::Inputkey()
{
	Key = 0;

	if ((GetAsyncKeyState(VK_UP)) || GetAsyncKeyState('W') )
		Key |= KEY_UP;

	if ((GetAsyncKeyState(VK_DOWN)) || GetAsyncKeyState('S'))
		Key |= KEY_DOWN;

	if ((GetAsyncKeyState(VK_LEFT)) || GetAsyncKeyState('A'))
		Key |= KEY_LEFT;

	if ((GetAsyncKeyState(VK_RIGHT)) || GetAsyncKeyState('D'))
		Key |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENTER;

	if (GetAsyncKeyState(VK_LCONTROL))
		Key |= KEY_CTRL;

	if (GetAsyncKeyState(VK_LMENU))
		Key |= KEY_ALT;

	if (GetAsyncKeyState(VK_TAB))
		Key |= KEY_TAB;

	if (GetAsyncKeyState(VK_ESCAPE))
		Key |= KEY_ESCAPE;

}
