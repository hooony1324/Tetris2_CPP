#include "pch.h"
#include "Board.h"

Board::Board()
{
	// 보드 정보 초기화
	_boardData = new int* [_width]();
	for (int i = 0; i < _height; ++i)
		_boardData[i] = new int[_width]();
}

Board::~Board()
{
	delete _boardData;
}

void Board::Init()
{
	// 0 -> 벽 1 -> 빈 공간 2, 3, 4, 5, 6, 7, 8 -> 블럭
	// 보드 기본 생성 : 왼쪽 오른쪽 벽

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			if (x == 0 || x == 11 || x == _width - 1)
				_boardData[y][x] = 0;
			else if ((y == 0 || y == _height - 1) && (11 < x && x < _width - 1))
				_boardData[y][x] = 0;
			else
				_boardData[y][x] = 1;
		}
	}


}

int** Board::getData()
{
	return _boardData;
}




