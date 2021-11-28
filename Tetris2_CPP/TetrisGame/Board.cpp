#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Block.h"

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
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	// ���� ���� ��ü�� ���
	for (int32 y = 0; y < HEIGHT; y++)
	{
		for (int32 x = 0; x < WIDTH; x++)
		{
			ConsoleColor color = GetTileColor(Pos{ y, x });
			ConsoleHelper::SetCursorColor(color);
			cout << TILE;
		}

		cout << endl;
	}
	
	cout << endl;

#pragma region ����ڸ޴���
	ConsoleHelper::SetCursorPosition(20, 3);
	cout << "ex)�����¿� : ����Ű\n";
	ConsoleHelper::SetCursorPosition(20, 4);
	cout << "�������� : �����̽���\n";
#pragma endregion

}

void Board::GenerateMap()
{
	// BOARD ���� ����
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

	// INFO ���� ����
	for (int32 y = 0; y < INFO_HEIGHT; y++)
	{
		for (int32 x = BOARD_WIDTH; x < WIDTH; x++)
		{
			if (x == WIDTH - 1 || y == INFO_HEIGHT - 1)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
}

void Board::UpdateMap()
{
	GenerateMap();
	// ������ ���� ���¸� ������Ʈ(������, ���� ���, ���� ��)
	// ������Ʈ�� ���带 Render

	// ���� ����� ���忡 ���
	// - �� ����
	// - _tile�� �� �Է�	
	GenerateBlock();
	SetCurrentBlock();

	
}

void Board::clear()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			_tile[y][x] = TileType::NONE;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= WIDTH)
		return TileType::NONE;

	if (pos.y < 0 || pos.y >= HEIGHT)
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

	// TODO : ��� Ÿ�Ժ� ����
	case TileType::BLOCK:
		return ConsoleColor::CYAN;

	}

	return ConsoleColor::WHITE;
}

// ���Ŀ� ť���� �������� �������� �ٲ� ����
void Board::GenerateBlock()
{
	if (_currentBlock)
		return;

	Block* block = new Block();
	_currentBlock = block;
}

void Board::SetCurrentBlock()
{
	if (!_currentBlock)
		return;

	// _tile�� currentBlock �Է�
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			arrPointer block = _currentBlock->GetBlock();
			_tile[_currentBlock->_y + y][_currentBlock->_x + x] = (TileType)block[y][x];
		}
	}
}


void Board::MoveBlockLeft()
{
	if (_currentBlock->_x <= 0)
		return;



	--_currentBlock->_x;
}

void Board::MoveBlockRight()
{
	if (_currentBlock->_x >= 9)
		return;


	++_currentBlock->_x;
}


