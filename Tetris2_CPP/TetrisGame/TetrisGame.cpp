#include "pch.h"
#include "ConsoleHelper.h"

int main()
{
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

        ConsoleHelper::SetCursorPosition(0, 0);
        ConsoleHelper::ShowConsoleCursor(false);
        ConsoleHelper::SetCursorColor(ConsoleColor::RED);

        const char* TILE = "□";
        const char* TILE_BLACK = "■";

        for (int32 y = 0; y < 20; y++)
        {
            for (int32 x = 0; x < 20; x++)
            {
                if (x > 5 && x < 15 && y > 5 && y < 15)
                {
                    ConsoleHelper::SetCursorColor(ConsoleColor::BLUE);
                    cout << TILE_BLACK;
                    ConsoleHelper::SetCursorColor(ConsoleColor::RED);
                    continue;
                }
                cout << TILE;
            }

            cout << endl;
        }
    }

}
