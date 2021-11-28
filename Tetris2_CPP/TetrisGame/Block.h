#pragma once

typedef int(*arrPointer)[4];

	// �������� �� ���¸� ����
	// Move(��, ��, �Ʒ�)
	// Move�������� Ȯ���ϴ� ���
	// ���忡���� ��ǥ ����
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
	int _x = 4;	// Board�� ������� ����
	int _rotationState = 0;
	int _state[4][4][4];

	void SetState_O();
	void SetState_J();

	// ȸ�� ���¸� �̹� ������ 2���� ���� ����
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