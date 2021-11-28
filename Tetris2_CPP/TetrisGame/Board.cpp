#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Block.h"

const char* TILE = "■";
const char* TILE_EMPTY = "□";	// 바닥에 쌓일 블럭 예상 모형 용도
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

	// 게임 공간 전체를 출력
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

#pragma region 사용자메뉴얼
	ConsoleHelper::SetCursorPosition(20, 3);
	cout << "ex)상하좌우 : 방향키\n";
	ConsoleHelper::SetCursorPosition(20, 4);
	cout << "도형변경 : 스페이스바\n";
#pragma endregion

}

void Board::GenerateMap()
{
	// BOARD 영역 지정
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

	// INFO 영역 지정
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
	// 보드의 현재 상태를 업데이트(현재블록, 다음 블록, 점수 등)
	// 업데이트된 보드를 Render

	// 현재 블록을 보드에 출력
	// - 블럭 생성
	// - _tile에 블럭 입력	
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

	// TODO : 블록 타입별 색깔
	case TileType::BLOCK:
		return ConsoleColor::CYAN;

	}

	return ConsoleColor::WHITE;
}

// 추후에 큐에서 꺼내오는 동작으로 바꿀 예정
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

	// _tile에 currentBlock 입력
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


