#include "SnakeRunningScene.h"

SnakeRunningScene::SnakeRunningScene()
{
	m_nGrade = 0; // ���� 
	m_pEnemy = nullptr;

	// �� ĳ���� ����
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
	static int nMap[MAP_ROW][MAP_COL]; // ��¿�
	char string[100];
	int(*pMap)[29] = nMap;

	//��¿� �ʿ� ���� 
	memcpy(nMap, _stageInfo.nMap, sizeof(int) * MAP_ROW * MAP_COL);

	// �� ĳ���� �׸���
	for (int i = 0; i < _stageInfo.nEnemyCount; i++)
	{
		m_pEnemy[i].render(pMap);
	}

	// �Ӹ�, ���� �׸���
	m_cSnake.render(pMap);

	// �ʱ׸���
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

	// Note: �������� ���� ���
	sprintf_s(string, "%d Stage", _Stage + 1);
	Screen::GetInstance()->screenPrint(61, 5, string);
	sprintf_s(string, "�����ð�: %d�� %d��", _time.m_RemainTime / 60, _time.m_RemainTime % 60);
	Screen::GetInstance()->screenPrint(61, 7, string);
	sprintf_s(string, "���̼�: %d", m_cSnake.getEatCount());
	Screen::GetInstance()->screenPrint(61, 9, string);
	sprintf_s(string, "����: %d", m_nGrade);
	Screen::GetInstance()->screenPrint(61, 11, string);
}

void SnakeRunningScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	clock_t CurTime = clock();

	if (is_init)
	{
		m_pEnemy = new Enemy[_stageInfo.nEnemyCount];

		// note: �� ĳ���� �������
		for (int i = 0; i < _stageInfo.nEnemyCount; ++i)
		{
			m_pEnemy[i].init(_stageInfo);
		}
		// Note: ���ΰ� ���� ����
		m_cSnake.init(_stageInfo);
		
		is_init = false;
	}

	_time.m_RemainTime = (_stageInfo.LimitTime - (CurTime - _time.m_GameStartTime)) / 1000; // ���� ���� ���� �ð�

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

	// Note: ���ΰ� �̵�
	if (CurTime - m_cSnake.getOldTime() > m_cSnake.getMoveTime())
	{
		m_cSnake.setOldTime(CurTime);
		m_cSnake.update(_stageInfo);

		switch (m_cSnake.getDirect())
		{
		case LEFT:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X - 1, m_cSnake.GET_Y))// ��ĳ���Ϳ� �浹�� ���
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case RIGHT:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X + 1, m_cSnake.GET_Y))// ��ĳ���Ϳ� �浹�� ���
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case UP:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X, m_cSnake.GET_Y - 1))// ��ĳ���Ϳ� �浹�� ���
			{
				m_cSnake.subLife();
				if (m_cSnake.getLife() < 1)
				{
					_gameState = STOP;
				}
			}
			break;

		case DOWN:
			if (IsCollision(_stageInfo.nEnemyCount, m_cSnake.GET_X, m_cSnake.GET_Y + 1))// ��ĳ���Ϳ� �浹�� ���
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

	// �� ĳ���� �̵�
	for (int i = 0; i < _stageInfo.nEnemyCount; i++)
	{
		if (m_pEnemy[i].is_life() == 1)
		{
			// �� ĳ������ ���� ��ȯ�� �̵��� ���Ѱ�
			if (CurTime - m_pEnemy[i].getOldTime() > m_pEnemy[i].getMoveTime())
			{
				m_pEnemy[i].setOldTime(CurTime);
				m_pEnemy[i].update(_stageInfo);
			}

			// �� �Ӹ��� �� ĳ������ �浹
			if (m_cSnake.GET_X == m_pEnemy[i].GET_X && m_cSnake.GET_Y == m_pEnemy[i].GET_Y)
			{
				m_pEnemy[i].death();
				m_cSnake.subLife();

				if (m_cSnake.getLife() < 1) // �Ӹ��� ������ ������ �����Ѵ�.
				{
					_gameState = STOP;
				}
			}

			// �� ������ �� ĳ������ �浹
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
		//// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.  
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

// Note: �� ĳ���Ϳ� �浹 üũ 
bool SnakeRunningScene::IsCollision(int count, int _x, int _y)
{
	for (int i = 0; i < /*m_sStageInfo.nEnemyCount*/count; i++)
	{
		if (m_pEnemy[i].is_life() == 1)
		{
			if (m_pEnemy[i].GET_X == _x && m_pEnemy[i].GET_Y == _y)
			{
				m_pEnemy[i].death();
				return true; ///�浹
			}
		}
	}

	return false;
}