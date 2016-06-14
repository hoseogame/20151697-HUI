#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::init(SNAKESTAGE_INFO &_sStageInfo)
{
	// Note: 적 캐릭터 추출 과정
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (_sStageInfo.nMap[i][j] == 2)
			{
				nLife = 1;
				setVec2X(j);
				setVec2Y(i);
				eDirect = static_cast<DIRECT>(dist(rng));
				OldTime = clock();
				MoveTime = rand() % 100 + 100; // 최소 100에서 299까지

				_sStageInfo.nMap[i][j] = -1; // 공백 상태로 전환
				return;
			}
		}
	}
}

void Enemy::update(SNAKESTAGE_INFO &sStageInfo)
{

	switch (eDirect)
	{
	case LEFT:
		if (GET_X - 1 >= 0)
		{
			// 벽에 부딪힌 경우
			if (sStageInfo.nMap[GET_Y][GET_X - 1] == 0)
			{
				// 방향 전환을 위한 랜덤 부분
				while (eDirect == LEFT)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // 새로운 방향을 제시한다
			}
			else {
				subVec2X();
			}
		}
		break;
	case RIGHT:
		if (GET_X + 1 < MAP_COL)
		{
			// 벽에 부딪힌 경우
			if (sStageInfo.nMap[GET_Y][GET_X + 1] == 0)
			{
				// 방향 전환을 위한 랜덤 부분
				while (eDirect == RIGHT)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // 새로운 방향을 제시한다
			}
			else {
				addVec2X();
			}
		}
		break;
	case UP:
		if (GET_Y - 1 >= 0)
		{
			// 벽에 부딪힌 경우
			if (sStageInfo.nMap[GET_Y - 1][GET_X] == 0)
			{
				// 방향 전환을 위한 랜덤 부분
				while (eDirect == UP)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // 새로운 방향을 제시한다
			}
			else {
				subVec2Y();
			}
		}
		break;
	case DOWN:
		// 벽에 부딪힌 경우
		if (GET_Y + 1 < MAP_ROW)
		{

			if (sStageInfo.nMap[GET_Y + 1][GET_X] == 0)
			{
				// 방향 전환을 위한 랜덤 부분
				while (eDirect == DOWN)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // 새로운 방향을 제시한다
			}
			else {
				addVec2Y();
			}
		}
		break;
	}

}

void Enemy::render(int(*&_map)[29])
{
	// 적 캐릭터 그리기
	if (is_life() == 1)
	{
		_map[GET_Y][GET_X] = 2;
	}
}
