#pragma once
#include "Vector2D.h"
#include <ctime>
#include "Header.h"

struct FOOTBALLSTAGE_INFO
{
	int nGoalBall;			// �����ؾ� �� ���� ���� 
	clock_t LimitTime;      // ���� �ð� 
	int nGoalDaeLength;		// ��� ���� 
	int nGoalDaeX;			// ��� �̵� X ��ǥ
	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
	clock_t MoveTime;		// ��� �̵� �ð� ����
	int nDist;				// ��� �̵� �Ÿ�
};

struct FOOTBALLTIME
{
	clock_t CurTime;
	clock_t LimitTime;
	clock_t GameStartTime;
	clock_t UpdateOldTime;
};