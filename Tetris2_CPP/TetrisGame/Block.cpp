#include "pch.h"
#include "Block.h"

Block::Block(int y, int x)
{
	// �� ���� ��ġ
	_y = y;
	_x = x;

	// Ÿ���� 2~8 ���� ����, ȸ������ 0~3 ����
	SetType_VOID();
	_blockType = (int)(rand() % 3 + 2);
	_rotationState = (int)(rand() % 4);

	// �� Ÿ�� �ʱ�ȭ
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
				_data[r][y][x] = BT_O[0][y][x]; // O ���� ȸ������ �� �Ȱ���
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
