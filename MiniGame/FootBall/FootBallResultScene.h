#pragma once
#include "FootBallState.h"

class FootBallResultScene final : public FootBallState
{
public:
	explicit FootBallResultScene() = default;
	virtual  ~FootBallResultScene() = default;
	explicit FootBallResultScene(const FootBallResultScene&) = delete;
	FootBallResultScene& operator = (const FootBallResultScene&) = delete;

public:
	void update(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;
	void render(FOOTBALLSTAGE_INFO&, GAME_STATE&, FOOTBALLTIME&, Player<int>&, int &_Stage) override;

private:

};