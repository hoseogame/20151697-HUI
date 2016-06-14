#pragma once
#include "FootBallState.h"
#include "FootBallGame.h"

class FootBallSuccessScene final : public FootBallState
{
public:
	explicit FootBallSuccessScene() = default;
	virtual  ~FootBallSuccessScene() = default;
	explicit FootBallSuccessScene(const FootBallSuccessScene&) = delete;
	FootBallSuccessScene& operator = (const FootBallSuccessScene&) = delete;

private:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

};
