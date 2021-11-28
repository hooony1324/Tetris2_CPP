#pragma once

// 블럭 생성 기능
// 키보드 입력 기능
// 노멀 스텝 기능
// 게임 오버 체크 기능
// 1칸 내려갈 수 있는지 체크
 
class GameManager
{
public:
	static GameManager& instance()
	{
		static GameManager* instance = new GameManager();
		return *instance;
	}

	void Init();
	void Update(uint64 deltaTick);

private:


private:
	int64				MOVE_TICK = 40;
	uint64				_sumTick = 0;
	class Board*		_board;
	class InputHandler* _inputHandler;
	class Block*		_block;
};

