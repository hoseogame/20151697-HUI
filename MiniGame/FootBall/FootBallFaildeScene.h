#pragma once
#include "FootBallState.h"
#include "FootBallGame.h"

class FootBallFaildeScene final : public FootBallState
{
public:
	explicit FootBallFaildeScene() = default;
	virtual  ~FootBallFaildeScene() = default;
	explicit FootBallFaildeScene(const FootBallFaildeScene&) = delete;
	FootBallFaildeScene& operator = (const FootBallFaildeScene&) = delete;

public:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

private:


};
