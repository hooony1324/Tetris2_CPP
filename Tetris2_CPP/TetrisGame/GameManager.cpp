#include "pch.h"
#include "GameManager.h"
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"

void GameManager::Init()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_board = new Board();

	_board->Init();
}

void GameManager::Update(uint64 deltaTick)
{
	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;


		_board->UpdateMap();

		_board->Render();

	
		_inputHandler->handleInput(_board);

		_board->clear();
	}
}


