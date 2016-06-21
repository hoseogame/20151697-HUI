#pragma once
#include "SnakeState.h"

class SnakeReadyScene : public SnakeState
{
public:
	SnakeReadyScene();
	~SnakeReadyScene();

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

private:

};
