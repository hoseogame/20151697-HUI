#pragma once
#include "SnakeState.h"

class SnakeSuccessScene : public SnakeState
{
public:
	SnakeSuccessScene();
	~SnakeSuccessScene();

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

private:

};
