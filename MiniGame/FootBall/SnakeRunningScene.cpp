#include "SnakeRunningScene.h"

SnakeRunningScene::SnakeRunningScene()
{
	m_nGrade = 0; // 점수 
	m_pEnemy = nullptr;

	// 적 캐릭터 설정
	if (m_pEnemy != nullptr)
		delete[](m_pEnemy);
}

SnakeRunningScene::~SnakeRunningScene()
{
	if (m_pEnemy != nullptr)
		delete [] (m_pEnemy);
}

void SnakeRunningScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	static int nMap[MAP_ROW][MAP_COL]; // 출력용
	char string[100];
	int(*pMap)[29] = nMap;

	//출력용 맵에 복사 
	memcpy(nMap, _stageInfo.nMap, sizeof(int) * MAP_ROW * MAP_COL);

	// 적 캐릭터 그리기
	for (int i = 0; i < _stageInfo.nEnemyCount; i++)
	{
		m_pEnemy[i].render(pMap);
	}

	// 머리, 꼬리 그리기
	m_cSnake.render(pMap);

	// 맵그리기
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (nMap[i][j] == -1)
				Screen::GetInstance()->screenPrint((j * 2) + 2, i + 1, "  ");
			else
				Screen::GetInstance()->screenPrint((j * 2) + 2, i + 1, kStateShape[nMap[i][j]]);
		}
	}

	// Note: 스테이지 정보 출력
	sprintf_s(string, "%d Stage", _Stage + 1);
	Screen::GetInstance()->screenPrint(61, 5, string);
	sprintf_s(string, "남은시간: %d분 %d초", _time.m_RemainTime / 60, _time.m_RemainTime % 60);
	Screen::GetInstance()->screenPrint(61, 7, string);
	sprintf_s(string, "먹이수: %d", m_cSnake.getEatCount());
	Screen::GetInstance()->screenPrint(61, 9, string);
	sprintf_s(string, "득점: %d", m_nGrade);
	Screen::GetInstance()->screenPrint(61, 11, string);
}

void SnakeRunningScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	clock_t CurTime = clock();

	if (is_init)
	{
		m_pEnemy = new Enemy[_stageInfo.nEnemyCount];

		// note: 적 캐릭터 추출과정
		for (int i = 0; i < _stageInfo.nEnemyCount; ++i)
		{
			m_pEnemy[i].init(_stageInfo);
		}
		// Note: 주인공 추출 과정
		m_cSnake.init(_stageInfo);
		
		is_init = false;
	}

	_time.m_RemainTime = (_stageInfo.LimitTime - (CurTime - _time.m_GameStartTime)) / 1000; // 게임 진행 남은 시간

	if ((CurTime - _time.m_GameStartTime) > _stageInfo.LimitTime || m_cSnake.getEatCount() == _stageInfo.nEatCount)
	{
		_gameState = STOP;
		return;
	}

	if (_kbhit())
	{
		_plyer.getch();

		switch (_plyer.getKey())
		{
		case 75:
			m_cSnake.setDirect(LEFT);
			break;

		case 77:
			m_cSnake.setDirect(RIGHT);
			break;

		case 72:
			m_cSnake.setDirect(UP);
			break;

		case 80:
			m_cSnake.setDirect(DOWN);
			break;
		}
	}

	// Note: 주인공 이동
	if (CurTime - m_cSnake.getOldTime() > m_cSnake.getMoveTime())
	{
		m_cSnake.setOldTime(CurTime);
		m_cSnake.update(_stageInfo);

		switch (m_cSnake.getDirect())
		{
		case LEFT:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X - 1, m_cSnake.GET_Y))// 적캐릭터와 충돌한 경우
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case RIGHT:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X + 1, m_cSnake.GET_Y))// 적캐릭터와 충돌한 경우
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case UP:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X, m_cSnake.GET_Y - 1))// 적캐릭터와 충돌한 경우
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case DOWN:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X, m_cSnake.GET_Y + 1))// 적캐릭터와 충돌한 경우
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;
		}
	}

	if (m_cSnake.isEat())
	{
		m_nGrade += 10;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// 적 캐릭터 이동
	for (int i = 0; i < _stageInfo.nEnemyCount; i++)
	{
		if (m_pEnemy[i].is_life() == 1)
		{
			// 적 캐릭터의 방향 전환과 이동에 관한것
			if (CurTime - m_pEnemy[i].getOldTime() > m_pEnemy[i].getMoveTime())
			{
				m_pEnemy[i].setOldTime(CurTime);
				m_pEnemy[i].update(_stageInfo);
			}

			// 뱀 머리와 적 캐릭터의 충돌
			if (m_cSnake.GET_X == m_pEnemy[i].GET_X && m_cSnake.GET_Y == m_pEnemy[i].GET_Y)
			{
				m_pEnemy[i].death();
				m_cSnake.subLife();

				if (m_cSnake.getLife() < 1) // 머리가 죽으면 게임을 종료한다.
				{
					_gameState = STOP;
				}
			}

			// 뱀 꼬리와 적 캐릭터의 충돌
			for (int j = 0; j < m_cSnake.getLife() - 1; j++)
			{
				if (m_pEnemy[i].GET_X == m_cSnake.getTailArray(j).getX() && m_pEnemy[i].GET_Y == m_cSnake.getTailArray(j).getY())
				{
					m_pEnemy[i].death();
					m_cSnake.subLife();
				}
			}
		}
	}

	if (_gameState == STOP)
	{
		//// 성공이냐 실패를 판단해주어서 출력을 해주는 부분이 와야 한다.  
		if (m_cSnake.getEatCount() >= _stageInfo.nEatCount)
		{
			_time.m_UpdateOldTime = CurTime;
			_gameState = SUCCESS;
			_stageInfo.m_nTotalGrade += m_nGrade;
		}
		else {
			_gameState = FAILED;
		}
	}

}

// Note: 적 캐릭터와 충돌 체크 
bool SnakeRunningScene::IsCollision(int count, int _x, int _y)
{
	for (int i = 0; i < /*m_sStageInfo.nEnemyCount*/count; i++)
	{
		if (m_pEnemy[i].is_life() == 1)
		{
			if (m_pEnemy[i].GET_X == _x && m_pEnemy[i].GET_Y == _y)
			{
				m_pEnemy[i].death();
				return true; ///충돌
			}
		}
	}

	return false;
}