#pragma once
#include "Vector2D.h"
#include <ctime>
#include "Header.h"

struct FOOTBALLSTAGE_INFO
{
	int nGoalBall;			// 골인해야 할 볼의 개수 
	clock_t LimitTime;      // 제한 시간 
	int nGoalDaeLength;		// 골대 길이 
	int nGoalDaeX;			// 골대 이동 X 좌표
	int nGoalDaeY;			// 골대 이동 Y 좌표 
	clock_t MoveTime;		// 골대 이동 시간 간격
	int nDist;				// 골대 이동 거리
};

struct FOOTBALLTIME
{
	clock_t CurTime;
	clock_t LimitTime;
	clock_t GameStartTime;
	clock_t UpdateOldTime;
};