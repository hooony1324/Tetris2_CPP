#pragma once

#include "ConsoleHelper.h"
class Block;

enum
{
	BOARD_WIDTH = 12,	// ��Ʈ���� ������ 10x20
	BOARD_HEIGHT = 20,	// 2��ŭ�� ������ ����

	INFO_WIDTH = 6,
	INFO_HEIGHT = 20,

	WIDTH = BOARD_WIDTH + INFO_WIDTH,
	HEIGHT = BOARD_HEIGHT,
};

enum class TileType
{
	NONE = 0,		// ���� �Ѿ ����
	WALL,			// ��
	EMPTY,			// ���� ������ �� �ִ� ����
	BLOCK,			// ��Ʈ���� ��

};

class Board
{
public:
	Board();
	~Board();

	void			Init();
	void			Render();


	/*** �� ***/
	void			GenerateMap();
	void			UpdateMap();
	void			clear();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);
	
	/*** �� ***/
	void GenerateBlock();
	void SetCurrentBlock();

	void MoveBlockLeft();
	void MoveBlockRight();

private:
	TileType _tile[HEIGHT][WIDTH];

	// ���� ������, ��Ʈ�� ���� ���
	Block*	_currentBlock;

	// ������ ������ �� ����Ʈ(ť)

	// �ٴڿ� ���� �� ����(���� ���� ���� ���� ��ġ���� ���پ� �˻�?)

};


