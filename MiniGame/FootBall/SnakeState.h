#pragma once
#include "SnakeDefault.h"
#include "Screen.h"
#include <stdio.h>
#include <conio.h>
#include "Player.h"

class SnakeState abstract
{
public:
	explicit SnakeState() = default;
	virtual ~SnakeState() = default;
	SnakeState(const SnakeState&) = delete;
	SnakeState& operator = (const SnakeState&) = delete;

public:
	virtual void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage) = 0;
	virtual void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage) = 0;

};

