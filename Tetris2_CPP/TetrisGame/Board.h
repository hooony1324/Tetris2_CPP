#pragma once

#include "ConsoleHelper.h"
class Block;

enum
{
	BOARD_WIDTH = 12,	// 테트리스 영역은 10x20
	BOARD_HEIGHT = 20,	// 2만큼의 공간은 벽임

	INFO_WIDTH = 6,
	INFO_HEIGHT = 20,

	WIDTH = BOARD_WIDTH + INFO_WIDTH,
	HEIGHT = BOARD_HEIGHT,
};

enum class TileType
{
	NONE = 0,		// 벽을 넘어선 공간
	WALL,			// 벽
	EMPTY,			// 블럭이 움직일 수 있는 공간
	BLOCK,			// 테트리스 블럭

};

class Board
{
public:
	Board();
	~Board();

	void			Init();
	void			Render();


	/*** 맵 ***/
	void			GenerateMap();
	void			UpdateMap();
	void			clear();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);
	
	/*** 블럭 ***/
	void GenerateBlock();
	void SetCurrentBlock();

	void MoveBlockLeft();
	void MoveBlockRight();

private:
	TileType _tile[HEIGHT][WIDTH];

	// 현재 생성된, 컨트롤 중인 블록
	Block*	_currentBlock;

	// 다음에 생성될 블럭 리스트(큐)

	// 바닥에 쌓인 블럭 상태(현재 블럭의 가장 높은 위치부터 한줄씩 검사?)

};


