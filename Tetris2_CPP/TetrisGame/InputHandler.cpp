#include "pch.h"
#include "InputHandler.h"
#include "Board.h"

void InputHandler::handleInput()
{
	

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		// �������� �̵�

	}

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		// ���������� �̵�

	}

	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		// �Ʒ��� �̵� + ��� ���� ��� �̿�

	}

	else
	{
		// Normal Step
	}

}
