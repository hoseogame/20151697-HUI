#pragma once
#include <random>
#include "Header.h"
#include <ctime>
static const int MAP_COL = 29;
static const int MAP_ROW = 22;
static const int kLast_Stage = 3;
static const char* kStrFileName[kLast_Stage] = { "map1.bin", "map1.bin", "map1.bin" };

struct SNAKESTAGE_INFO
{
	int nEnemyCount;                // Note: �� ĳ������ ����
	clock_t LimitTime;              // Note: ���������� ���� �ð�
	int nEatCount;                  // Note: ���� ����
	int nMap[MAP_ROW][MAP_COL];		// Note: �� ���� 
	int	m_nTotalGrade;				// ����
};

struct SNAKETIME
{
	clock_t m_nLimitTime;
	clock_t	m_GameStartTime;
	clock_t m_UpdateOldTime;
	clock_t m_RemainTime;
	clock_t m_CurTime;
};

static std::random_device rd;
static std::default_random_engine rng(rd());
static std::uniform_int_distribution<__int64> dist(LEFT, DOWN);