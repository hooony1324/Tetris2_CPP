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


