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

class Board
{
public:
	Board();
	~Board();

	void			Init();
	int**			getData();

public:
	int**	_boardData;
	int		_width = BOARD_WIDTH;
	int		_height = BOARD_HEIGHT;

};


