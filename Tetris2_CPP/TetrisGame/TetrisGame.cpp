#include "pch.h"
#include "ConsoleHelper.h"

#include "Board.h"
Board board;

int main()
{
    board.GenerateMap();

    uint64 lastTick = 0;
    while (true)
    {
#pragma region 프레임 관리
        const uint64 currentTick = ::GetTickCount64();
        const uint64 deltaTick = currentTick - lastTick;
        lastTick = currentTick;
#pragma endregion

        // 입력

        // 로직

        // 렌더링
        board.Render();
    }
}
