#pragma once
#include "FootBallState.h"

class FootBallReadyScene final : public FootBallState
{
public:
	explicit FootBallReadyScene() = default;
	virtual  ~FootBallReadyScene() = default;
	explicit FootBallReadyScene(const FootBallReadyScene&) = delete;
	FootBallReadyScene& operator = (const FootBallReadyScene&) = delete;

public:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

private:

};
