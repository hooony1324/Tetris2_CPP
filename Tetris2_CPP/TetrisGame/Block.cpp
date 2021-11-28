#include "pch.h"
#include "Block.h"

Block::Block()
{
	//(rand() % (int)BlockType::BT_LENGTH); // 0 ~ 6 까지의 난수
	int idx = (int)(rand() % 2);
	
	switch (idx)
	{
	case 0:
		SetState_O();
		break;
	case 1:
		SetState_J();
		break;
	}

}

void Block::SetState_O()
{
	_BT = BlockType::BT_O;
	_rotationState = 0;

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			_state[0][y][x] = block_O[y][x];
		}
	}
}

void Block::SetState_J()
{
	_BT = BlockType::BT_J;
	_rotationState = (int)(rand() % 4);

	for (int z = 0; z < 4; ++z)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				_state[z][y][x] = block_J[z][y][x];
			}
		}
	}
}

arrPointer Block::GetBlock()
{
	return _state[_rotationState];
}

void Block::Rotate()
{
	++_rotationState;
}
