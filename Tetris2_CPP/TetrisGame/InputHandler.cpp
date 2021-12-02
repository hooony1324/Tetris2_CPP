#include "pch.h"
#include "InputHandler.h"
#include "Board.h"

void InputHandler::handleInput()
{
	

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		// 왼쪽으로 이동

	}

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		// 오른쪽으로 이동

	}

	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		// 아래로 이동 + 노멀 스텝 기능 이용

	}

	else
	{
		// Normal Step
	}

}
