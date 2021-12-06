#include "pch.h"
#include "InputHandler.h"
#include "Board.h"

InputHandler::InputHandler()
{
	_blockMoving = false;
}

InputHandler::~InputHandler()
{
	_board = nullptr;
}

void InputHandler::Init(Board* board)
{
	_board = board;
}

void InputHandler::handleInput()
{
	
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		
		// �������� �̵�
		_board->MoveBlockLeft();

	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{

		// ���������� �̵�
		_board->MoveBlockRight();

	}

	else if (GetAsyncKeyState(VK_DOWN))
	{

		// �Ʒ��� �̵� + ��� ���� ��� �̿�
		_board->MoveBlockDown();

	}

}
