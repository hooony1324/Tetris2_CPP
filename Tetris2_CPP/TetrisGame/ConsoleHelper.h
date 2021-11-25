#pragma once

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
	GRAY = FOREGROUND_INTENSITY,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
};


class ConsoleHelper
{
public:
	static void SetCursorPosition(int32 x, int32 y);
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};

