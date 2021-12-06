#include "pch.h"
#include "GameManager.h"
#include "Screen.h"


void GameManager::Init()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_screen = new Screen();
	_screen->Init();
}

void GameManager::Update(uint64 deltaTick)
{
	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_screen->Update(_sumTick);

		// ·»´õ
		_screen->Render();

		_sumTick = 0;
	}
}


