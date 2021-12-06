#include "pch.h"
#include "Board.h"
#include "Block.h"

Board::Board()
{
	// ���� ���� �ʱ�ȭ
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
	// 0 -> �� 1 -> �� ���� 2, 3, 4, 5, 6, 7, 8 -> ��
	// ���� �⺻ ���� : ���� ������ ��

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
	_currentBlock = new Block(y, x); // 0 4 -> ������ �߻��
	_currentBlockData = _currentBlock->getBlockData();

}

bool Board::CheckBlock(int leftright, int updown, bool rotate)
{
	// ���� x : -1, y : 0			0 0 0 0 <O��, currentBlockData>
	// ������ x : +1, y : 0			0 2 2 0
	// �Ʒ� : x : 0, y : +1			0 2 2 0
	//								0 0 0 0
	RemoveCurBlock(); // board�� �ִ� curblock�� ����, curblock��ü ������ ����

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

	if (next_x < 0 || next_y < 0 || next_x > 10 || next_y > 17)
		return false;
	
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			if (_currentBlockData[y][x] == 0)
				continue;

			// _boardData �� �� ���� ���Ҵ� 1 
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
	// currBlock�� Board�� �Է�
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

	// �������� �ű� �� �ִ��� Ȯ��
	if (!CheckBlock(-1, 0, 0))
		return;

	// curBlock�� ��ġ ����
	--_currentBlock->_x;

}

void Board::MoveBlockRight()
{
	if (!_currentBlock)
		return;

	// ���������� �ű� �� �ִ��� Ȯ��
	if (!CheckBlock(1, 0, 0))
		return;

	// curBlock�� ��ġ ����
	++_currentBlock->_x;
}

void Board::MoveBlockDown()
{
	if (!_currentBlock)
		return;

	// �Ʒ��� �ű� �� �ִ��� Ȯ��
	if (!CheckBlock(0, 1, 0))
	{
		SetCurBlock();
		_currentBlock = nullptr;
		return;
	}

	// curBlock�� ��ġ ����
	++_currentBlock->_y;
}

void Board::RotateBlock()
{
	if (!_currentBlock)
		return;

	// ȸ�� �� �� �ִ��� Ȯ��
	if (!CheckBlock(0, 0, 1))
	{
		_currentBlock->RotateBlockDataCounterClock();
		RemoveCurBlock();
		return;
	}

}




