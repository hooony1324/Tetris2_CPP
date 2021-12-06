#pragma once
 
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
	int64				MOVE_TICK = 100;
	uint64				_sumTick = 0;
	class Screen*		_screen;

};

