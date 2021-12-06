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
		
		// 왼쪽으로 이동
		_board->MoveBlockLeft();

	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{

		// 오른쪽으로 이동
		_board->MoveBlockRight();

	}

	else if (GetAsyncKeyState(VK_DOWN))
	{

		// 아래로 이동 + 노멀 스텝 기능 이용
		_board->MoveBlockDown();

	}

}
