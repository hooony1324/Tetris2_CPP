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
	NONE = 0,		// ���� �Ѿ ����
	WALL,			// ����� ���� ��
	EMPTY,			// ����� ������ �� �ִ� ����
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

