#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"

const char* TILE = "��";
const char* TILE_EMPTY = "��";	// �ٴڿ� ���� �� ���� ���� �뵵

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init()
{
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	// ���� ���� ��ü�� ���
	for (int32 y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int32 x = 0; x < BOARD_WIDTH; x++)
		{
			ConsoleColor color = GetTileColor(Pos{ y, x });
			ConsoleHelper::SetCursorColor(color);
			cout << TILE;
		}

		cout << endl;
	}
}

void Board::GenerateMap()
{
	for (int32 y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int32 x = 0; x < BOARD_WIDTH; x++)
		{
			if (x == 0 || x == BOARD_WIDTH - 1)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x > BOARD_WIDTH)
		return TileType::NONE;

	if (pos.y < 0 || pos.y > BOARD_HEIGHT)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case TileType::EMPTY:
		return ConsoleColor::BLACK;
	case TileType::WALL:
		return ConsoleColor::WHITE;
	}

	return ConsoleColor::WHITE;
}
