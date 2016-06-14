#pragma once
#include "SnakeState.h"
#include "Enemy.h"
#include "Snake.h"

class SnakeRunningScene : public SnakeState
{
public:
	SnakeRunningScene();
	~SnakeRunningScene();

public:
	void render(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);
	void update(SNAKESTAGE_INFO&, GAME_STATE&, SNAKETIME&, Player<int>&, int &_Stage);

public:
	// Note: 적 캐릭터와 충돌 체크 
	bool IsCollision(int count, int _x, int _y);

private:
	int	m_nGrade;		// 점수
	Enemy *m_pEnemy;
	Snake m_cSnake;

	bool is_init;

	const char kStateShape[5][3] = { "■", "♥", "⊙", "●", "◆" };

};
