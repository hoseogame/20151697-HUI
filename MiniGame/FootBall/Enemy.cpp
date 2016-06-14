#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::init(SNAKESTAGE_INFO &_sStageInfo)
{
	// Note: �� ĳ���� ���� ����
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
				MoveTime = rand() % 100 + 100; // �ּ� 100���� 299����

				_sStageInfo.nMap[i][j] = -1; // ���� ���·� ��ȯ
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
			// ���� �ε��� ���
			if (sStageInfo.nMap[GET_Y][GET_X - 1] == 0)
			{
				// ���� ��ȯ�� ���� ���� �κ�
				while (eDirect == LEFT)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // ���ο� ������ �����Ѵ�
			}
			else {
				subVec2X();
			}
		}
		break;
	case RIGHT:
		if (GET_X + 1 < MAP_COL)
		{
			// ���� �ε��� ���
			if (sStageInfo.nMap[GET_Y][GET_X + 1] == 0)
			{
				// ���� ��ȯ�� ���� ���� �κ�
				while (eDirect == RIGHT)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // ���ο� ������ �����Ѵ�
			}
			else {
				addVec2X();
			}
		}
		break;
	case UP:
		if (GET_Y - 1 >= 0)
		{
			// ���� �ε��� ���
			if (sStageInfo.nMap[GET_Y - 1][GET_X] == 0)
			{
				// ���� ��ȯ�� ���� ���� �κ�
				while (eDirect == UP)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // ���ο� ������ �����Ѵ�
			}
			else {
				subVec2Y();
			}
		}
		break;
	case DOWN:
		// ���� �ε��� ���
		if (GET_Y + 1 < MAP_ROW)
		{

			if (sStageInfo.nMap[GET_Y + 1][GET_X] == 0)
			{
				// ���� ��ȯ�� ���� ���� �κ�
				while (eDirect == DOWN)
				{
					eDirect = static_cast<DIRECT>(dist(rng));
				}
				setDirect(eDirect); // ���ο� ������ �����Ѵ�
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
	// �� ĳ���� �׸���
	if (is_life() == 1)
	{
		_map[GET_Y][GET_X] = 2;
	}
}
