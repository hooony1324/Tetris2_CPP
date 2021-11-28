#pragma once

typedef int(*arrPointer)[4];

	// 여러가지 블럭 형태를 가짐
	// Move(좌, 우, 아래)
	// Move가능한지 확인하는 기능
	// 보드에서의 좌표 성분
enum class BlockType
{
	BT_O,
	BT_J,
	BT_L,
	BT_S,
	BT_Z,
	BT_l,
	BT_T,
	BT_LENGTH
};

class Block
{	
public:
	Block();

	int _y = 0;
	int _x = 4;	// Board의 가운데에서 생성
	int _rotationState = 0;
	int _state[4][4][4];

	void SetState_O();
	void SetState_J();

	// 회전 상태를 이미 적용한 2차원 상태 리턴
	arrPointer GetBlock();

	void Rotate();

private:
	BlockType _BT;

};

static const int block_O[4][4] =
{
	{2, 2, 2, 2},
	{2, 3, 3, 2},
	{2, 3, 3, 2},
	{2, 2, 2, 2}
};

static const int block_J[4][4][4] = {
	{
		{2, 2, 3, 2},
		{2, 2, 3, 2},
		{2, 3, 3, 2},
		{2, 2, 2, 2}
	},

	{
		{2, 2, 2, 2},
		{2, 3, 2, 2},
		{2, 3, 3, 3},
		{2, 2, 2, 2}
	},

	{
		{2, 2, 2, 2},
		{2, 3, 3, 2},
		{2, 3, 2, 2},
		{2, 3, 2, 2}
	},

	{
		{2, 2, 2, 2},
		{3, 3, 3, 2},
		{2, 2, 3, 2},
		{2, 2, 2, 2}
	},

};