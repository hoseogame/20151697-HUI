#pragma once
#include "FootBallState.h"
#include "Player.h"
#include "FootBallDefault.h"
#include "FootBallInitScene.h"
#include "FootBallReadyScene.h"
#include "FootBallRunningScene.h"
#include "FootBallResultScene.h"
#include "FootBallFaildeScene.h"
#include "FootBallSuccessScene.h"
#include "ConsoleGame.h"

class FootBallGame final : public ConsoleGame
{
	/*CLASS_VARIABLE(int, ex)*/

private:

public:
	explicit FootBallGame();
	virtual  ~FootBallGame();
	FootBallGame(const FootBallGame&) = delete;
	FootBallGame& operator = (const FootBallGame&) = delete;

public:
	void stateChange(FootBallState* _state);

private:
	void update() override;
	void render() override;

public:
	void init() override;
	void run() override;

private:
	GAME_STATE m_gameState;
	FOOTBALLSTAGE_INFO m_stageInfo;
	FOOTBALLTIME m_time;
	Player<int> m_player;

	int m_stage;
	
private:
	FootBallState* m_state;

};
