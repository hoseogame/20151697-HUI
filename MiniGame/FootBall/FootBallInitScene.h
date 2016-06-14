#pragma once
#include "FootBallState.h"

class FootBallInitScene final : public FootBallState
{
public:
	explicit FootBallInitScene() = default;
	virtual  ~FootBallInitScene() = default;
	explicit FootBallInitScene(const FootBallInitScene&) = delete;
	FootBallInitScene& operator = (const FootBallInitScene&) = delete;

public:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

private:

};
