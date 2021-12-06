#pragma once


// Board���, ����� �Է�,
class Screen
{
public:
	Screen();
	~Screen();
	void Init();
	void Update(uint64 Tick);

private:
	void Swap();
	void Clear();

public:
	void Print(int x, int y, char* string);
	void UpdateNextScreen();
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
	class Board*			_board;
	class InputHandler*		_hInput;
	uint64					_downSpeed = 1000;
	uint64					_sumTick = 0;
};

