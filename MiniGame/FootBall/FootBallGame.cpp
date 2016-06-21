#include "FootBallGame.h"

FootBallGame::FootBallGame()
	:	m_state(nullptr),
		m_gameState(INIT),
		m_stage(-1)
{
	m_stageInfo.nGoalBall = 3;
	m_stageInfo.LimitTime = 1000 * 20;
	m_stageInfo.nGoalDaeLength = 1;
	m_stageInfo.nGoalDaeX = 20;
	m_stageInfo.nGoalDaeY = 3;
	m_stageInfo.MoveTime = 300;
	m_stageInfo.nDist = 1;

	m_time.CurTime = clock();
	m_time.GameStartTime = clock();
	m_time.LimitTime = clock();
	m_time.UpdateOldTime = clock();
}

FootBallGame::~FootBallGame()
{
	if (m_state)
		delete m_state;
	m_state = nullptr;
}

void FootBallGame::stateChange(FootBallState* _state)
{
	if (m_state)
		delete m_state;
	m_state = _state;
}

void FootBallGame::init()
{
	m_state = nullptr;
	m_gameState = INIT;

	m_stageInfo.nGoalBall = 3;
	m_stageInfo.LimitTime = 1000 * 20;
	m_stageInfo.nGoalDaeLength = 1;
	m_stageInfo.nGoalDaeX = 20;
	m_stageInfo.nGoalDaeY = 3;
	m_stageInfo.MoveTime = 300;
	m_stageInfo.nDist = 1;

	m_stage = -1;

	if (m_stage == -1)
	{
		m_stage = 0;
	}

	m_time.LimitTime = m_stageInfo.LimitTime;
	
	m_time.UpdateOldTime = clock();
}

void FootBallGame::render()
{
	Screen::GetInstance()->screenClear();

	m_state->render(m_stageInfo, m_gameState, m_time, m_player, m_stage);

	Screen::GetInstance()->screenFlipping();
}

void FootBallGame::update()
{
	m_time.CurTime = clock();

	m_state->update(m_stageInfo, m_gameState, m_time, m_player, m_stage);
}

void FootBallGame::run()
{
	const int kmaxStage = 2;

	while (m_stage != kmaxStage)
	{
		switch (m_gameState)
		{
		case INIT:
			stateChange(new FootBallInitScene);
			break;
		case READY:
			stateChange(new FootBallReadyScene);
			break;
		case RUNNING:
			stateChange(new FootBallRunningScene);
			break;
		case SUCCESS:
			stateChange(new FootBallSuccessScene);
			break;
		case FAILED:
			stateChange(new FootBallFaildeScene);
			break;
		case RESULT:
			stateChange(new FootBallResultScene);
			break;
		}

		m_gameState = NONE;
		
		update();
		render();
	}
}