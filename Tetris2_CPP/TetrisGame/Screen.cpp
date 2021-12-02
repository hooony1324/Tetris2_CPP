#include "pch.h"
#include "Screen.h"
#include "Board.h"

Screen::Screen()
{
	// FPS, GUIDE
	_numofFPS = 0;
	_FPSTextInfo = new char[5];
	memset(_FPSTextInfo, '\0', 5);

	// BOARD CONTROLL
	_board = new Board();

}

Screen::~Screen()
{
	CloseHandle(_hScreen[0]);
	CloseHandle(_hScreen[1]);
}

void Screen::Init()
{
	CONSOLE_CURSOR_INFO cci;

	// 화면 버퍼 2개를 만든다.
	_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(_hScreen[0], &cci);
	SetConsoleCursorInfo(_hScreen[1], &cci);

	// FPS check
	_oldTime = clock();

	// BOARD CONTROL
	_board->Init();
}

void Screen::Swap()
{
	SetConsoleActiveScreenBuffer(_hScreen[_screenIndex]);
	_screenIndex = !_screenIndex;
}

void Screen::Clear()
{
	COORD pos = { 0, 0 };
	DWORD dword;
	FillConsoleOutputCharacter(_hScreen[_screenIndex], ' ', _board->_width * _board->_height, pos, &dword);
}

void Screen::Print(int x, int y, char* string)
{
	COORD CursorPosition = { x, y };
	DWORD dword;
	SetConsoleCursorPosition(_hScreen[_screenIndex], CursorPosition);
	WriteFile(_hScreen[_screenIndex], string, strlen(string), &dword, NULL);
}

void Screen::UpdateBoard()
{
	COORD CursorPosition = { 0, 0 };
	DWORD dword;
	
	int height = _board->_height;
	int width = _board->_width;

	// char* buf; // "■", "  ", 는 2바이트

	int** boardData = _board->getData();
	
	for (int y = 0; y < height; ++y)
	{
		string strData;
		for (int x = 0; x < width; ++x)
		{
			int data = boardData[y][x];
			if (data == 0)
				strData += "■";
			else if (data == 1)
				strData += "  ";
		}
		char* buf = new char[strData.size() + 1];
		copy(strData.begin(), strData.end(), buf);
		buf[strData.size()] = '\0';
		CursorPosition.Y = y;

		SetConsoleCursorPosition(_hScreen[_screenIndex], CursorPosition);
		WriteFile(_hScreen[_screenIndex], buf, strlen(buf), &dword, NULL);
	}

	// _board의 boardData 에 접근하여 숫자를 문자로 변환
	// 바뀐 문자를 buf에 넣음(21 x 20) + 마지막'\0'

}

void Screen::Render()
{
	// FPS check
	_curTime = clock();

	Clear();

	// 1초마다 현재 버퍼 출력
	if (_curTime - _oldTime >= 1000)
	{
		sprintf(_FPSTextInfo, "FPS : %d", _numofFPS);

		// 현재 보드 출력하면서 후면 버퍼에 기록?

		_oldTime = _curTime;
		_numofFPS = 0;
	}

	++_numofFPS;
	
	// 후면 버퍼 그리기
	Print(44, 0, _FPSTextInfo);
	Print(44, 1, _FPSTextInfo);
	Print(44, 2, _FPSTextInfo);
	Print(44, 3, _FPSTextInfo);
	UpdateBoard();

	// 버퍼 교체(더블 버퍼링)
	Swap();
}