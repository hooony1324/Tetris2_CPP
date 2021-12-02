#include "pch.h"
#include "Block.h"

Block::Block()
{
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
	}

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
