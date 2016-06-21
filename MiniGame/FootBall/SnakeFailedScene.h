#pragma once
#include "SnakeState.h"

class SnakeFailedScene : public SnakeState
{
public:
	SnakeFailedScene();
	~SnakeFailedScene() = default;

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

private:

};