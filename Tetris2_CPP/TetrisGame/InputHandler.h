#pragma once

class Board;

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void Init(Board* board);
	void handleInput();
	bool _blockMoving;

private:
	Board*	_board;
};

