#pragma once

enum
{
	// 테트리스 규격 : 10 x 20, 나머지 10은 벽(2) 게임 안내(8)
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
	블럭 생성 & 컨트롤
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
	게임 로직
************************/
public:

	void CheckLineComplete();
	void EraseLine(int start, int end);

};


