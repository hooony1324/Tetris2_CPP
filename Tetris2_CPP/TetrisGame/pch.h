#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include "Types.h"
#include <time.h>
using namespace std;

static int8 GAME_WIDTH = 18;
static int8 GAME_HEIGHT = 20;

// 블럭이 가지고 있는 위치정보
struct Pos
{
	// Pos 객체 간 연산자(예시)
	// a == b
	// a != b
	// a + b
	// a += b ( a = a + b)
	
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}

	Pos operator+=(Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

enum Dir
{
	// 반시계 방향
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4
};
