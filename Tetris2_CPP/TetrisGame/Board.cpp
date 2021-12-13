#include "pch.h"
#include "Board.h"
#include "Block.h"

Board::Board()
{
	// 보드 정보 초기화
	_boardData = new int* [_width]();
	for (int i = 0; i < _height; ++i)
		_boardData[i] = new int[_width]();
}

Board::~Board()
{
	delete[] _boardData;
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

void Board::Update()
{
	if (_currentBlock == nullptr)
		InstantiateBlock(0, 4);

	SetCurBlock();

}

int** Board::getBoardData()
{
	return _boardData;
}

void Board::InstantiateBlock(int y, int x)
{
	// 게임 로직 
	CheckLineComplete();

	_currentBlock = new Block(y, x); // 0 4 -> 보드의 중상단
	_currentBlockData = _currentBlock->getBlockData();

}

bool Board::CheckBlock(int leftright, int updown, bool rotate)
{
	// 왼쪽 x : -1, y : 0			0 0 0 0 <O블럭, currentBlockData>
	// 오른쪽 x : +1, y : 0			0 2 2 0
	// 아래 : x : 0, y : +1			0 2 2 0
	//								0 0 0 0
	RemoveCurBlock(); // board에 있는 curblock만 제거, curblock자체 정보는 존재

	if (rotate)
	{
		_currentBlock->RotateBlockDataClock();
	}

	_currentBlockData = _currentBlock->getBlockData();

	bool result = true;
	int curBlock_x = _currentBlock->_x;
	int curBlock_y = _currentBlock->_y;

	int next_x = curBlock_x + leftright;
	int next_y = curBlock_y + updown;

	if (next_x < 0 || next_y < 0 || next_x > 10 || next_y > 19)
		return false;
	
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			if (_currentBlockData[y][x] == 0)
				continue;

			// _boardData 의 빈 공간 원소는 1 
			if (_boardData[next_y + y][next_x + x] != 1)
			{
				return false;
			}
		}
	}

	return result;
}

void Board::RemoveCurBlock()
{
	_currentBlockData = _currentBlock->getBlockData();
	int curBlock_x = _currentBlock->_x;
	int curBlock_y = _currentBlock->_y;

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			if (_currentBlockData[y][x] == 0)
				continue;

			if (_currentBlockData[y][x] == _currentBlock->_blockType)
				if (_boardData[curBlock_y + y][curBlock_x + x] == _currentBlock->_blockType)
					_boardData[curBlock_y + y][curBlock_x + x] = 1;
		}
	}
}

void Board::SetCurBlock()
{
	// currBlock을 Board에 입력
	_currentBlockData = _currentBlock->getBlockData();
	int curBlock_x = _currentBlock->_x;
	int curBlock_y = _currentBlock->_y;
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			if (_currentBlockData[y][x] == 0)
				continue;
			_boardData[curBlock_y + y][curBlock_x + x] = _currentBlock->_blockType;
		}
	}
}

void Board::MoveBlockLeft()
{
	if (!_currentBlock)
		return;

	// 왼쪽으로 옮길 수 있는지 확인
	if (!CheckBlock(-1, 0, 0))
		return;

	// curBlock의 위치 갱신
	--_currentBlock->_x;

}

void Board::MoveBlockRight()
{
	if (!_currentBlock)
		return;

	// 오른쪽으로 옮길 수 있는지 확인
	if (!CheckBlock(1, 0, 0))
		return;

	// curBlock의 위치 갱신
	++_currentBlock->_x;
}

void Board::MoveBlockDown()
{
	if (!_currentBlock)
		return;

	// 아래로 옮길 수 있는지 확인
	if (!CheckBlock(0, 1, 0))
	{
		SetCurBlock();
		_currentBlock = nullptr;
		return;
	}

	// curBlock의 위치 갱신
	++_currentBlock->_y;
}

void Board::RotateBlock()
{
	if (!_currentBlock)
		return;

	// 회전 할 수 있는지 확인
	if (!CheckBlock(0, 0, 1))
	{
		_currentBlock->RotateBlockDataCounterClock();
		RemoveCurBlock();
		return;
	}

}

void Board::CheckLineComplete()
{
	int y_start = 0;
	int y_end = 0;

	// 첫 라인 찾음
	for (int y = 19; y >= 0; --y)
	{
		int cnt = 0;
		for (int x = 1; x < 11; ++x)
		{
			if (_boardData[y][x] != 1)
				++cnt;
		}
		if (cnt == 10)
		{
			y_start = y;
			y_end = y_start;
			break;
		}
	}

	if (y_start == 0)
		return;
	
	// 첫라인 이후부터 연속된 라인 찾음
	for (int y = y_end - 1; y >= 0; --y)
	{
		int cnt = 0; // 블럭 한줄은 10개
		for (int x = 1; x < 11; ++x)
		{
			if (_boardData[y][x] != 1)
				++cnt;
		}

		if (cnt == 10)
		{
			y_end = y;
		}
		else
			break;
	}

	EraseLine(y_start, y_end);
	
}

void Board::EraseLine(int start, int end)
{
	int mvDown = start - end + 1;

	for (int y = start; y >= end; --y)
	{
		// 라인 지우기
		for (int x = 1; x < 11; ++x)
		{
			_boardData[y][x] = 1;
		}
	}


	// 데이터 밑으로 당기기
	for (int y = end - 1; y >= 0; --y)
	{
		for (int x = 1; x < 11; ++x)
		{
			if (_boardData[y + mvDown][x] == 1)
			{
				_boardData[y + mvDown][x] = _boardData[y][x];
				_boardData[y][x] = 1;
			}
		}
	}
	
	
}




