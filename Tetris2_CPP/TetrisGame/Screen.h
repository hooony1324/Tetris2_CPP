#pragma once

class Board;

// Board���, ����� �Է�,
class Screen
{
public:
	Screen();
	~Screen();
	void Init();

private:
	void Swap();
	void Clear();

public:
	void Print(int x, int y, char* string);
	void UpdateBoard();
	void Render();

/*** ��� ***/
// ���� ���۸�
private:
	int				_screenIndex;
	HANDLE			_hScreen[2];
	clock_t			_curTime;
	clock_t			_oldTime;

// FPS, GUIDE
public:
	int				_numofFPS;
	char*			_FPSTextInfo;
	char*			_TetrisTextInfo;

// BOARD CONTROL
private:
	Board*			_board;
};

