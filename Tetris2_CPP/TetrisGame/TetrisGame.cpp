﻿#include "pch.h"
#include "GameManager.h"
#include "Board.h"

int main()
{
    GameManager::instance().Init();

    uint64 lastTick = 0;
    while (1)
    {
#pragma region 프레임 관리
        const uint64 currentTick = ::GetTickCount64();
        const uint64 deltaTick = currentTick - lastTick;
        lastTick = currentTick;
#pragma endregion

        GameManager::instance().Update(deltaTick);


    }
}

