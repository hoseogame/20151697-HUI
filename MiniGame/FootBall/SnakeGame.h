#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Screen.h"
#include "Player.h"
#include "ConsoleGame.h"
#include "SnakeFailedScene.h"
#include "SnakeInitScene.h"
#include "SnakeReadyScene.h"
#include "SnakeResultScene.h"
#include "SnakeRunningScene.h"
#include "SnakeSuccessScene.h"

//오브젝트들간의 상호작용을 관리하는 클래스
class SnakeGame final : public ConsoleGame
{
public:
	explicit SnakeGame();
	virtual  ~SnakeGame();
	SnakeGame(const SnakeGame&) = delete;
	SnakeGame& operator = (const SnakeGame&) = delete;

private:
	void stateChange(SnakeState* _state);

	void update() override;
	void render() override;
	
public:
	void init() override;
	void run() override;

private:
	GAME_STATE m_eGameState;
	SNAKESTAGE_INFO m_sStageInfo; // s = struct
	SNAKETIME m_time;
	Player<int> m_nPlayer;

private:
	int	m_nStage;

private:
	SnakeState* m_state;

};