#include "pch.h"
#include "InputHandler.h"
#include "Board.h"

void InputHandler::handleInput(Board* board)
{
	

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		// �������� �̵�
		board->MoveBlockLeft();
	}

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		// ���������� �̵�
		board->MoveBlockRight();
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
