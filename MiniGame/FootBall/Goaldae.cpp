#include "Goaldae.h"

Goaldae::Goaldae(const FOOTBALLSTAGE_INFO &_stageInfo)
{
	int nLength;

	m_info.m_nLength = strlen(g_strPlayer);

	setVec2X(_stageInfo.nGoalDaeX);
	setVec2Y(_stageInfo.nGoalDaeY);
	nLength = _stageInfo.nGoalDaeLength;
	m_info.MoveTime = _stageInfo.MoveTime;
	m_info.OldTime = clock();
	m_info.nDist = _stageInfo.nDist;
	nLength = _stageInfo.nGoalDaeLength * 2 + 1; // Note: 배열의 최대 길이

	for (int i = 0; i < nLength; i++)
	{
		m_info.nLineX[i] = GET_X + 2 * (i + 1);
	}
}

void Goaldae::init()
{
}

void Goaldae::update()
{
}

void Goaldae::render()
{
}
