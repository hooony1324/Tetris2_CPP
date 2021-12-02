#pragma once

class Board;

// Board출력, 사용자 입력,
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

/*** 멤버 ***/
// 더블 버퍼링
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

