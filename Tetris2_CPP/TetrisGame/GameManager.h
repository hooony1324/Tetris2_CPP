#pragma once

// �� ���� ���
// Ű���� �Է� ���
// ��� ���� ���
// ���� ���� üũ ���
// 1ĭ ������ �� �ִ��� üũ
 
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

