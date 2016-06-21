#pragma once
#include "SnakeState.h"
#include <Windows.h>

class SnakeResultScene : public SnakeState
{
public:
	SnakeResultScene();
	~SnakeResultScene();

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

private:

};
