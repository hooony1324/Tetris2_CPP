#include "pch.h"
#include "Block.h"

Block::Block(int y, int x)
{
	// 블럭 생성 위치
	_y = y;
	_x = x;

	// 타입은 2~8 랜덤 생성, 회전상태 0~3 랜덤
	SetType_VOID();
	_blockType = (int)(rand() % 7 + 2);
	_rotationState = (int)(rand() % 4);

	// 블럭 타입 초기화
	switch (_blockType)
	{
	case 2:
		SetType_O();
		break;
	case 3:
		SetType_J();
		break;
	case 4:
		SetType_L();
		break;
	case 5:
		SetType_S();
		break;
	case 6:
		SetType_Z();
		break;
	case 7:
		SetType_l();
		break;
	case 8:
		SetType_T();
		break;
	}

	_blockData = new int* [4]();
	for (int i = 0; i < 4; ++i)
		_blockData[i] = new int[4]();
}

Block::~Block()
{
	delete[] _data;
}

void Block::SetType_VOID()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = 0;
		}
	}
}

void Block::SetType_O()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_O[0][y][x]; // O 블럭은 회전상태 다 똑같음
		}
	}
}

void Block::SetType_J()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_J[r][y][x];
		}
	}
}

void Block::SetType_L()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_L[r][y][x];
		}
	}
}

void Block::SetType_S()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_S[r][y][x];
		}
	}
}

void Block::SetType_Z()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_Z[r][y][x];
		}
	}
}

void Block::SetType_l()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_l[r][y][x];
		}
	}
}

void Block::SetType_T()
{
	for (int r = 0; r < 4; ++r)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				_data[r][y][x] = BT_T[r][y][x];
		}
	}
}

int** Block::getBlockData()
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			_blockData[y][x] = _data[_rotationState][y][x];
		}
	}

	return _blockData;
}

void Block::RotateBlockDataClock()
{
	_rotationState = (_rotationState + 1) % 4;
}

void Block::RotateBlockDataCounterClock()
{
	_rotationState = (_rotationState - 1) % 4;
}
