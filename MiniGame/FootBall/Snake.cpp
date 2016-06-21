#include "Snake.h"

Snake::Snake()
{
	MoveTime = 100;
	OldTime = clock();
	eDirect = LEFT;
	nLife = 4;
	nEatCount = 0;
	eat = false;
}

void Snake::move()
{
	// Note: Step 1 . ��� ���� ��ǥ�� ���� ��ǥ�� ����
	sHeadold.setX(GET_X);
	sHeadold.setY(GET_Y);

	for (int i = 0; i < nLife - 1; i++)
	{
		sTailOld[i].setX(sTail[i].getX());
		sTailOld[i].setY(sTail[i].getY());
	}

	// Note: Step 2. ���� ��ǥ�� ���� ��ǥ�� ����
	sTail[0].setX(sHeadold.getX());
	sTail[0].setY(sHeadold.getY());

	for (int i = 1; i < nLife - 1; i++)
	{
		sTail[i].setX(sTailOld[i - 1].getX());
		sTail[i].setY(sTailOld[i - 1].getY());
	}
}

void Snake::init(SNAKESTAGE_INFO &sStageInfo)
{
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (sStageInfo.nMap[i][j] == 3)
			{
				setVec2X(j);
				setVec2Y(i);
				sStageInfo.nMap[i][j] = -1; // ���� ���·� ��ȯ

											// for�� 2�� Ż�� ����
				i = MAP_ROW;
				j = MAP_COL;
			}
		}
	}

	sHeadold.setX(GET_X);
	sHeadold.setY(GET_Y);

	// Note: Snake ���� �ʱ�ȭ, �⺻ 3��
	for (int i = 0; i < 3; i++)
	{
		sTail[i].setX(GET_X + i + 1);
		sTail[i].setY(GET_Y);
	}

	nLife = 4;
	nEatCount = 0;
	eat = false;
}

void Snake::update(SNAKESTAGE_INFO &_sStageInfo)
{
	switch (eDirect)
	{
	case LEFT:
		if (GET_X - 1 >= 0)
		{
			// �浹 üũ 
			if (_sStageInfo.nMap[GET_Y][GET_X - 1] == 0) // ���� �浹 
				break;

			if (_sStageInfo.nMap[GET_Y][GET_X - 1] == 1) // ���̸� ���� ��찡 �ȴ�.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y][GET_X - 1] = -1; // ���̴� �������� ó��
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // ������ �ִ� ���̴�.
				move();

			subVec2X();
		}
		break;

	case RIGHT:
		if (GET_X + 1 < MAP_COL)
		{
			if (_sStageInfo.nMap[GET_Y][GET_X + 1] == 0) // ���� �浹 
				break;

			if (_sStageInfo.nMap[GET_Y][GET_X + 1] == 1) // ���̸� ���� ��찡 �ȴ�.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y][GET_X + 1] = -1; // �������� ó��
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // ������ �ִ� ���̴�.
				move();

			addVec2X();
		}
		break;

	case UP:
		if (GET_Y - 1 >= 0)
		{
			if (_sStageInfo.nMap[GET_Y - 1][GET_X] == 0) // ���� �浹 
				break;

			if (_sStageInfo.nMap[GET_Y - 1][GET_X] == 1) // ���̸� ���� ��찡 �ȴ�.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y - 1][GET_X] = -1; // �������� ó��
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // ������ �ִ� ���̴�.
				move();

			subVec2Y();
		}
		break;

	case DOWN:
		if (GET_Y + 1 < MAP_ROW)
		{
			if (_sStageInfo.nMap[GET_Y + 1][GET_X] == 0) // ���� �浹 
				break;

			if (_sStageInfo.nMap[GET_Y + 1][GET_X] == 1) // ���̸� ���� ��찡 �ȴ�.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y + 1][GET_X] = -1; // �������� ó��
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // ������ �ִ� ���̴�.
				move();

			addVec2Y();
		}
		break;
	}
}

void Snake::render(int(*&_map)[29])
{
	// ���ΰ� �Ӹ�
	_map[GET_Y][GET_X] = 3;

	// ����
	for (int i = 0; i < nLife - 1; i++)
		_map[getTailArray(i).getY()][getTailArray(i).getX()] = 4;
}