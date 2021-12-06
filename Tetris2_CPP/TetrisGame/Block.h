#pragma once

//0 0 0 0													
//0 2 2 0				■ ■								
//0 2 2 0      ->		■ ■									
//0 0 0 0													 
// 블럭 -> 맵의 빈 공간, 왼쪽 오른쪽의 벽, 타입 블록

// < Render >
// 왼쪽 오른쪽의 벽, WALL	: "■" <- 0  흰색
// 빈 공간, VOID		: "  " <- 1 흰색

// 블록	, BT_O...	: "■" <- 2, 색 있음 O, J, L, S, Z, l, T
// 블록2 : BT_O
// 블록3 : BT_J
// 블록8 : BT_T

class Block
{	
public:
	Block(int y, int x);
	~Block();

	int		_y = 0;
	int		_x = 0;
	uint64	_rotationState = 0;		// 0 ~ 3
	int		_blockType = 0; 
	int		_data[4][4][4];			// 블럭과 회전상태

	void SetType_VOID();
	void SetType_O();
	void SetType_J();
	void SetType_L();

	int** getBlockData();
	int** _blockData;

	void RotateBlockDataClock();
	void RotateBlockDataCounterClock();
};

static int BT_O[4][4][4] = {
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0}
	},
};

static int BT_J[4][4][4] = {

	{
		{0, 0, 3, 0},
		{0, 0, 3, 0},
		{0, 3, 3, 0},
		{0, 0, 0, 0},
	},

	{
		{0, 0, 0, 0},
		{0, 3, 0, 0},
		{0, 3, 3, 3},
		{0, 0, 0, 0},
	},

	{
		{0, 3, 3, 0},
		{0, 3, 0, 0},
		{0, 3, 0, 0},
		{0, 0, 0, 0},
	},

	{
		{0, 0, 0, 0},
		{3, 3, 3, 0},
		{0, 0, 3, 0},
		{0, 0, 0, 0},
	},

};

static int BT_L[4][4][4] = {

	{
		{0, 4, 0, 0},
		{0, 4, 0, 0},
		{0, 4, 4, 0},
		{0, 0, 0, 0},
	},

	{
		{0, 0, 0, 0},
		{0, 4, 4, 4},
		{0, 4, 0, 0},
		{0, 0, 0, 0},
	},

	{
		{0, 0, 0, 0},
		{0, 4, 4, 0},
		{0, 0, 4, 0},
		{0, 0, 4, 0},
	},

	{
		{0, 0, 0, 0},
		{0, 0, 4, 0},
		{4, 4, 4, 0},
		{0, 0, 0, 0},
	}

};