#pragma once
#include "SnakeState.h"

class SnakeInitScene : public SnakeState
{
public:
	SnakeInitScene();
	~SnakeInitScene();

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

private:

};
