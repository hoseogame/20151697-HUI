#include "FootBallRunningScene.h"

FootBallRunningScene::FootBallRunningScene() :
	m_Goal(0),
	m_BallCount(0),
	m_GoalBallCount(3),
	isnew_ball(true),
	m_IsGoal(0)
{

}

FootBallRunningScene::~FootBallRunningScene()
{
	if(m_goaldae)
		delete m_goaldae;
	m_goaldae = nullptr;
}

void FootBallRunningScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if(isnew_ball == true)
	{ 
		m_goaldae = new Goaldae(_stageInfo);
		isnew_ball = false;
	}

	// ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
	int remain = remain = m_goaldae->getInfo().m_nLength - m_ball.CENTER_X + 1;
	int nLength = _stageInfo.nGoalDaeLength * 2 + 1;

	#pragma region _Ű�Է�_

	if (_kbhit())
	{
		_player.getch();

		switch (_player.getKey())
		{
		case 'j':
			if (m_ball.getInfo().m_PlayerPos.movePos.getX() > 2) // ���� �浹 ��� ��ǥ üũ
			{
				m_ball.subPlayerMoveX();
				// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
				if (m_ball.MOVE_X - m_ball.CENTER_X < 2 || m_ball.MOVE_X + remain > 43)
					m_ball.subPlayerMoveX();

				m_ball.setPlayerX(m_ball.MOVE_X - m_ball.CENTER_X);
			}
			break;

		case 'l':
			if (m_ball.getInfo().m_PlayerPos.movePos.getX() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
			{
				m_ball.addPlayerMoveX();
				// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
				if (m_ball.MOVE_X - m_ball.CENTER_X < 2 || m_ball.MOVE_X + remain > 43)
					m_ball.addPlayerMoveX();

				m_ball.setPlayerX(m_ball.MOVE_X - m_ball.CENTER_X);
			}
			break;

		case 'k':
			if (m_ball.getInfo().nIsReady)
			{
				m_ball.setVec2X(m_ball.MOVE_X);
				m_ball.setVec2Y(m_ball.MOVE_Y - 1);
				m_ball.setOldTime(clock());
				m_ball.setisReady(0);
			}
			break;

		}
	}
#pragma endregion

	if (_time.CurTime - _time.GameStartTime > _time.LimitTime) // Note: ���� �ð�
	{
		_gameState = STOP;
	}
	else 
	{
		// Note: ���
		if (_time.CurTime - m_goaldae->getInfo().OldTime > m_goaldae->getInfo().MoveTime)
		{
			m_goaldae->setOldTime(_time.CurTime);
			if (m_goaldae->GET_X + m_goaldae->getInfo().nDist >= 2 && ((m_goaldae->getInfo().nLineX[nLength - 1] + 3) + m_goaldae->getInfo().nDist) <= 43)
			{
				m_goaldae->setVec2X(m_goaldae->GET_X + m_goaldae->getInfo().nDist);
				for (int i = 0; i < nLength; i++)
				{
					m_goaldae->setLineX(i, m_goaldae->GET_X + 2 * (i + 1));
				}
			}
			else {
				m_goaldae->setDist(m_goaldae->getInfo().nDist * -1); // -1 �� ������ �ٲپ� ��.
			}
		}

		if (m_ball.getInfo().nIsReady == 0) // �̵� ���� �� 
		{	// �̵� �ð� ���ݿ� ���� �̵�
			if ((_time.CurTime - m_ball.getInfo().OldTime) > m_ball.getInfo().MoveTime)
			{
				if (m_ball.GET_Y - 1 > 0)
				{
					m_ball.subVec2Y();
					m_ball.setOldTime(_time.CurTime); // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
											   // ��� ���� �浹
					if (m_ball.GET_X >= m_goaldae->getInfo().nLineX[0] && m_ball.GET_X + 1 <= m_goaldae->getInfo().nLineX[nLength - 1] + 1)
					{
						if (m_ball.GET_Y <= m_goaldae->GET_Y)
						{   // �� �ʱ�ȭ
							m_ball.setisReady(1);
							m_ball.setVec2X(m_ball.MOVE_X);
							m_ball.setVec2Y(m_ball.MOVE_Y -1);
							m_BallCount++;  // ������ ���� ����										

							if (m_BallCount == m_GoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS m_Goal = 1
							{
								_gameState = STOP;
								m_Goal = 1;
							}

							// ȿ�� ���
							if (m_IsGoal == 0)
							{
								m_IsGoal = 1;
								m_effect.setStartTime(_time.CurTime);
							}
						}
						// ��� �浹 
					}
					else if ((m_ball.GET_X >= m_goaldae->getInfo().nLineX[0] - 2 && m_ball.GET_X <= m_goaldae->getInfo().nLineX[0] - 1) ||
						(m_ball.GET_X + 1 >= m_goaldae->getInfo().nLineX[0] - 2 && m_ball.GET_X + 1 <= m_goaldae->getInfo().nLineX[0] - 1) ||
						(m_ball.GET_X >= m_goaldae->getInfo().nLineX[nLength - 1] + 2 && m_ball.GET_X <= m_goaldae->getInfo().nLineX[nLength - 1] + 3) ||
						(m_ball.GET_X + 1 >= m_goaldae->getInfo().nLineX[nLength - 1] + 2 && m_ball.GET_X + 1 <= m_goaldae->getInfo().nLineX[nLength - 1] + 3))
					{
						if (m_ball.GET_Y <= m_goaldae->GET_Y)
						{   // �� �ʱ�ȭ
							m_ball.setisReady(1);
							m_ball.setVec2X(m_ball.MOVE_X);
							m_ball.setVec2Y(m_ball.MOVE_Y - 1);
						}
					}
				}
				else { // �� �ʱ�ȭ
					m_ball.setisReady(1);
					m_ball.setVec2X(m_ball.MOVE_X);
					m_ball.setVec2Y(m_ball.MOVE_Y - 1);
				}
			}
		}
		else {
			m_ball.setVec2X(m_ball.MOVE_X);
		}
		// ȿ�� 
		if (m_IsGoal == 1)
		{
			if (_time.CurTime - m_effect.getStartTime() > m_effect.getStayTime())
				m_IsGoal = 0;
		}
	}

	if (_gameState == STOP)
	{ 
		if (m_Goal == 1)
		{
			_gameState = SUCCESS;
			_time.UpdateOldTime = _time.CurTime;
		}
		else {
			_gameState = FAILED;
		}
	}
}

void FootBallRunningScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	int nLength;

	#pragma region _BackScreen_
	char string[100];

	Screen::GetInstance()->screenPrint(0, 0, "����������������������������������������������");
	Screen::GetInstance()->screenPrint(0, 1, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 2, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 3, "��                                          ��");
						   sprintf_s(string, "��                                          ����������: %d", _stage + 1);
	Screen::GetInstance()->screenPrint(0, 4, string);
	Screen::GetInstance()->screenPrint(0, 5, "��                                          ��");
					   	   sprintf_s(string, "�������������������������������������������������� �ð�: %d", _stageInfo.LimitTime / 1000);
	Screen::GetInstance()->screenPrint(0, 6, string);
	Screen::GetInstance()->screenPrint(0, 7, "��                                          ��");
						   sprintf_s(string, "��                                          ������ �ð�: %d", (clock() - _time.GameStartTime) / 1000);
	Screen::GetInstance()->screenPrint(0, 8, string);
	Screen::GetInstance()->screenPrint(0, 9, "��                                          ��");
						   sprintf_s(string, "��                                          ����ǥ ����: %d ", m_GoalBallCount);
	Screen::GetInstance()->screenPrint(0, 10, string);
	Screen::GetInstance()->screenPrint(0, 11, "��                                          ��");
	   					    sprintf_s(string, "��                                          ������ �� ����: %d ", m_BallCount);
	Screen::GetInstance()->screenPrint(0, 12, string);

	Screen::GetInstance()->screenPrint(0, 13, "��                                          ��");
						    sprintf_s(string, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 14, string);
	Screen::GetInstance()->screenPrint(0, 15, "��                                          ��");
						    sprintf_s(string, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 16, string);
	Screen::GetInstance()->screenPrint(0, 17, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 18, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 19, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 20, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 21, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 22, "��                                          ��");
	Screen::GetInstance()->screenPrint(0, 23, "����������������������������������������������");
#pragma endregion

	Screen::GetInstance()->screenPrint(m_goaldae->GET_X, m_goaldae->GET_Y, "��");
	nLength = _stageInfo.nGoalDaeLength * 2 + 1;

	for (int i = 0; i < nLength; i++)
		Screen::GetInstance()->screenPrint(m_goaldae->getInfo().nLineX[i], m_goaldae->GET_Y, "��");

	Screen::GetInstance()->screenPrint(m_goaldae->getInfo().nLineX[nLength - 1] + 2, m_goaldae->GET_Y, "��");

	// Note: ȿ�� ���  	
	if (m_IsGoal == 1)
	{
		m_effect.GoalMessage();
	}

	// Note: 2 �÷��� Ŭ���� 
	if (m_ball.POS_X < 2)  //  ���� Ŭ���� ó��
		Screen::GetInstance()->screenPrint(2, m_ball.MOVE_Y, &g_strPlayer[(m_ball.POS_X - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
	else if (m_ball.MOVE_X + (m_goaldae->getInfo().m_nLength - m_ball.CENTER_X + 1) > 43) // ������ Ŭ���� ó��
	{
		strncat_s(string, g_strPlayer, m_goaldae->getInfo().m_nLength - ((m_ball.MOVE_X + m_ball.CENTER_X + 1) - 43));
		Screen::GetInstance()->screenPrint(m_ball.POS_X, m_ball.MOVE_Y, string);
	}
	else { // 1 �÷��� �̵�
		Screen::GetInstance()->screenPrint(m_ball.POS_X, m_ball.MOVE_Y, g_strPlayer);
	}

	Screen::GetInstance()->screenPrint(m_ball.GET_X, m_ball.GET_Y, "��");

}
