#pragma once

#include "ConsoleHelper.h"

enum
{
	BOARD_WIDTH = 12,
	BOARD_HEIGHT = 20,

	INFO_WIDTH = 8,
	INFO_HEIGHT = 20,
};

enum class TileType
{
	NONE = 0,		// 벽을 넘어선 공간
	WALL,			// 블록을 막는 벽
	EMPTY,			// 블록이 움직일 수 있는 공간
	BLOCK_RED,
	BLOCK_GREEN,
	BLOCK_BLUE,
	BLOCK_YELLOW, 
};

class Board
{
public:
	Board();
	~Board();

	void			Init();
	void			Render();

	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

private:
	TileType _tile[BOARD_HEIGHT][BOARD_WIDTH];
};

