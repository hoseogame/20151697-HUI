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
	// Note: Step 1 . 모든 현재 좌표를 이전 좌표로 복사
	sHeadold.setX(GET_X);
	sHeadold.setY(GET_Y);

	for (int i = 0; i < nLife - 1; i++)
	{
		sTailOld[i].setX(sTail[i].getX());
		sTailOld[i].setY(sTail[i].getY());
	}

	// Note: Step 2. 이전 좌표를 현재 좌표로 복사
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
				sStageInfo.nMap[i][j] = -1; // 공백 상태로 전환

											// for문 2개 탈출 조건
				i = MAP_ROW;
				j = MAP_COL;
			}
		}
	}

	sHeadold.setX(GET_X);
	sHeadold.setY(GET_Y);

	// Note: Snake 꼬리 초기화, 기본 3개
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
			// 충돌 체크 
			if (_sStageInfo.nMap[GET_Y][GET_X - 1] == 0) // 블럭과 충돌 
				break;

			if (_sStageInfo.nMap[GET_Y][GET_X - 1] == 1) // 먹이를 먹은 경우가 된다.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y][GET_X - 1] = -1; // 먹이는 공백으로 처리
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // 꼬리가 있는 것이다.
				move();

			subVec2X();
		}
		break;

	case RIGHT:
		if (GET_X + 1 < MAP_COL)
		{
			if (_sStageInfo.nMap[GET_Y][GET_X + 1] == 0) // 블럭과 충돌 
				break;

			if (_sStageInfo.nMap[GET_Y][GET_X + 1] == 1) // 먹이를 먹은 경우가 된다.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y][GET_X + 1] = -1; // 공백으로 처리
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // 꼬리가 있는 것이다.
				move();

			addVec2X();
		}
		break;

	case UP:
		if (GET_Y - 1 >= 0)
		{
			if (_sStageInfo.nMap[GET_Y - 1][GET_X] == 0) // 블럭과 충돌 
				break;

			if (_sStageInfo.nMap[GET_Y - 1][GET_X] == 1) // 먹이를 먹은 경우가 된다.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y - 1][GET_X] = -1; // 공백으로 처리
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // 꼬리가 있는 것이다.
				move();

			subVec2Y();
		}
		break;

	case DOWN:
		if (GET_Y + 1 < MAP_ROW)
		{
			if (_sStageInfo.nMap[GET_Y + 1][GET_X] == 0) // 블럭과 충돌 
				break;

			if (_sStageInfo.nMap[GET_Y + 1][GET_X] == 1) // 먹이를 먹은 경우가 된다.
			{
				nLife++;
				_sStageInfo.nMap[GET_Y + 1][GET_X] = -1; // 공백으로 처리
				nEatCount++;
				eat = true;
				/*g_nGrade += 10;*/
			}

			if (nLife > 1) // 꼬리가 있는 것이다.
				move();

			addVec2Y();
		}
		break;
	}
}

void Snake::render(int(*&_map)[29])
{
	// 주인공 머리
	_map[GET_Y][GET_X] = 3;

	// 꼬리
	for (int i = 0; i < nLife - 1; i++)
		_map[getTailArray(i).getY()][getTailArray(i).getX()] = 4;
}