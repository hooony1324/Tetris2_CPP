#pragma once

enum
{
	// ��Ʈ���� �԰� : 10 x 20, ������ 10�� ��(2) ���� �ȳ�(8)
	BOARD_WIDTH = 19,	
	BOARD_HEIGHT = 20,	
};

enum class TileType
{		
	WALL = 0,
	EMPTY,
	BLOCK,			
};

class Block;

class Board
{
public:
	Board();
	~Board();

	void			Init();
	void			Update();
	int**			getBoardData();

public:
	int**		_boardData;
	int			_width = BOARD_WIDTH;
	int			_height = BOARD_HEIGHT;

/***********************
	�� ���� & ��Ʈ��
************************/
public:
	void InstantiateBlock(int y, int x);

	bool CheckBlock(int leftright, int updown, bool rotate);
	void RemoveCurBlock();
	void SetCurBlock();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void RotateBlock();

private:
	Block*		_currentBlock;
	int**		_currentBlockData;
	Block*		_nextBlock;

/***********************
	���� ����
************************/
public:

	void CheckLineComplete();
	void EraseLine(int start, int end);

};


