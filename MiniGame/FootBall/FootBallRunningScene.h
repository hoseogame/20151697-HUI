#pragma once
#include "FootBallState.h"
#include "Effect.h"
#include "Goaldae.h"

class FootBallRunningScene final : public FootBallState
{
public:
	explicit FootBallRunningScene();
	virtual  ~FootBallRunningScene();
	explicit FootBallRunningScene(const FootBallRunningScene&) = delete;
	FootBallRunningScene& operator = (const FootBallRunningScene&) = delete;

public:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

public:

private:
	Effect m_effect;
	Goaldae *m_goaldae;
	Ball m_ball;

private:
	int m_Length;
	int m_Goal;
	int m_BallCount;
	int m_GoalBallCount;
	int m_IsGoal;

	bool isnew_ball;
};
