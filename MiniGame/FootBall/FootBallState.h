#pragma once
#include "FootBallDefault.h"
#include "Screen.h"
#include <stdio.h>
#include <conio.h>
#include "Player.h"

class FootBallState abstract
{
public:

public:
	explicit FootBallState() = default;
	virtual ~FootBallState() = default;
	FootBallState(const FootBallState&) = delete;
	FootBallState& operator = (const FootBallState&) = delete;

public:
	virtual void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) = 0;
	virtual void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) = 0;

};

