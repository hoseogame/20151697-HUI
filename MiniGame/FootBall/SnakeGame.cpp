#include "SnakeGame.h"
#include "Enemy.h"

//Screen Copy

//#include "SnakeScreen.h"
//
//void SnakeScreen::initScreen() // 게임 소개 화면
//{
//	screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
//	screenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
//	screenPrint(0, 2, "┃■                                                      ■┃");
//	screenPrint(0, 3, "┃■                                                      ■┃");
//	screenPrint(0, 4, "┃■           ◎  ■■■■■          ◎                 ■┃");
//	screenPrint(0, 5, "┃■         ♥  ■■                     ♥              ■┃");
//	screenPrint(0, 6, "┃■           ■   ┏━━━━━━━━┓                  ■┃");
//	screenPrint(0, 7, "┃■       ■■■   ┃★   Snake    ★┃                  ■┃");
//	screenPrint(0, 8, "┃■                ┗━━━━━┳━━┛                  ■┃");
//	screenPrint(0, 9, "┃■     ◎               /)/)  ┃ ☆     ■■■■■■■■■┃");
//	screenPrint(0, 10, "┃■                 ★(*'')/                             ■┃");
//	screenPrint(0, 11, "┃■                                       ◎   ♥        ■┃");
//	screenPrint(0, 12, "┃■                 ◎                                   ■┃");
//	screenPrint(0, 13, "┃■    ■■■■■■                                      ■┃");
//	screenPrint(0, 14, "┃■              ■               ●◆◆                 ■┃");
//	screenPrint(0, 15, "┃■      ♥◎    ■                   ◆                 ■┃");
//	screenPrint(0, 16, "┃■              ■  Press Space Key !! ◆◆◆◆◆◆     ■┃");
//	screenPrint(0, 17, "┃■              ■                                      ■┃");
//	screenPrint(0, 18, "┃■              ■■■■■     ◎  ♥ ■■■■■        ■┃");
//	screenPrint(0, 19, "┃■                                    ■                ■┃");
//	screenPrint(0, 20, "┃■                                    ■     ◎  ♥     ■┃");
//	screenPrint(0, 21, "┃■                                    ■                ■┃");
//	screenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
//	screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
//}
//
//void SnakeScreen::readyScreen()
//{
//	screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
//	screenPrint(0, 1, "┃                                                          ┃");
//	screenPrint(0, 2, "┃                                                          ┃");
//	screenPrint(0, 3, "┃                                                          ┃");
//	screenPrint(0, 4, "┃                                                          ┃");
//	screenPrint(0, 5, "┃                                                          ┃");
//	screenPrint(0, 6, "┃                                                          ┃");
//	screenPrint(0, 7, "┃                                                          ┃");
//	screenPrint(0, 8, "┃                                          ●              ┃");
//	screenPrint(0, 9, "┃                                    ☜〓━┃┑            ┃");
//	screenPrint(0, 10, "┃                                        ☜〓┛            ┃");
//	screenPrint(0, 11, "┃                                        ┏┻┓            ┃");
//	screenPrint(0, 12, "┃                                                          ┃");
//	screenPrint(0, 13, "┃                                                          ┃");
//	screenPrint(0, 14, "┃                                                          ┃");
//	screenPrint(0, 15, "┃                                                          ┃");
//	screenPrint(0, 16, "┃                                                          ┃");
//	screenPrint(0, 17, "┃                                                          ┃");
//	screenPrint(0, 18, "┃                                                          ┃");
//	screenPrint(0, 19, "┃                                                          ┃");
//	screenPrint(0, 20, "┃                                                          ┃");
//	screenPrint(0, 21, "┃                                                          ┃");
//	screenPrint(0, 22, "┃                                                          ┃");
//	screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
//}
//
//void SnakeScreen::successScreen()
//{
//	screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
//	screenPrint(0, 1, "┃                                                          ┃");
//	screenPrint(0, 2, "┃                                                          ┃");
//	screenPrint(0, 3, "┃                                                          ┃");
//	screenPrint(0, 4, "┃                                                          ┃");
//	screenPrint(0, 5, "┃                                                          ┃");
//	screenPrint(0, 6, "┃                       *.   .*                            ┃");
//	screenPrint(0, 7, "┃                    *.┏┓┏┓.*대                        ┃");
//	screenPrint(0, 8, "┃                    ┏┻┫┣┻┓단                        ┃");
//	screenPrint(0, 9, "┃                    ┃━┫┣━┃해                        ┃");
//	screenPrint(0, 10, "┃                    ┃━┫┣━┃요~                       ┃");
//	screenPrint(0, 11, "┃                    ┗━┛┗━┛                          ┃");
//	screenPrint(0, 12, "┃                                                          ┃");
//	screenPrint(0, 13, "┃                                                          ┃");
//	screenPrint(0, 14, "┃                      You Win!!                           ┃");
//	screenPrint(0, 15, "┃                                                          ┃");
//	screenPrint(0, 16, "┃                                                          ┃");
//	screenPrint(0, 17, "┃                                                          ┃");
//	screenPrint(0, 18, "┃                                                          ┃");
//	screenPrint(0, 19, "┃                                                          ┃");
//	screenPrint(0, 20, "┃                                                          ┃");
//	screenPrint(0, 21, "┃                                                          ┃");
//	screenPrint(0, 22, "┃                                                          ┃");
//	screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
//}
//
//void SnakeScreen::failureScreen()
//{
//	screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
//	screenPrint(0, 1, "┃                                                          ┃");
//	screenPrint(0, 2, "┃                                                          ┃");
//	screenPrint(0, 3, "┃                                                          ┃");
//	screenPrint(0, 4, "┃                                                          ┃");
//	screenPrint(0, 5, "┃                                                          ┃");
//	screenPrint(0, 6, "┃                                                          ┃");
//	screenPrint(0, 7, "┃                     *┭┮  ┭┮*                         ┃");
//	screenPrint(0, 8, "┃                  *.  ㅣㅣ▽ㅣㅣ   .*                     ┃");
//	screenPrint(0, 9, "┃               ┏ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┓                   ┃");
//	screenPrint(0, 10, "┃               ┃     미션 실패      ┃                   ┃");
//	screenPrint(0, 11, "┃               ┗ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┛                   ┃");
//	screenPrint(0, 12, "┃                                                          ┃");
//	screenPrint(0, 13, "┃                                                          ┃");
//	screenPrint(0, 14, "┃                   (*⌒⌒*)                               ┃");
//	screenPrint(0, 15, "┃                  ┏O━━━O━━━━━━━━━━┓        ┃");
//	screenPrint(0, 16, "┃                  ┃계속하시겠습니까? <y/n>     ┃        ┃");
//	screenPrint(0, 17, "┃                  ┗━━━━━━━━━━━━━━┛        ┃");
//	screenPrint(0, 18, "┃                                                          ┃");
//	screenPrint(0, 19, "┃                                                          ┃");
//	screenPrint(0, 20, "┃                                                          ┃");
//	screenPrint(0, 21, "┃                                                          ┃");
//	screenPrint(0, 22, "┃                                                          ┃");
//	screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
//}
//
//void SnakeScreen::resultScreen()
//{
//	screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
//	screenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
//	screenPrint(0, 2, "┃■                  ■                                  ■┃");
//	screenPrint(0, 3, "┃■                  ■                                  ■┃");
//	screenPrint(0, 4, "┃■                  ■                                  ■┃");
//	screenPrint(0, 5, "┃■          ■■■■■■■■■■                        ■┃");
//	screenPrint(0, 6, "┃■                                                      ■┃");
//	screenPrint(0, 7, "┃■                                                      ■┃");
//	screenPrint(0, 8, "┃■                  ┏━━━━━━━━┓                ■┃");
//	screenPrint(0, 9, "┃■                  ┃★   Sanke    ★┃                ■┃");
//	screenPrint(0, 10, "┃■                  ┗━━━━━┳━━┛                ■┃");
//	screenPrint(0, 11, "┃■                      /)/)    ┃ ☆                   ■┃");
//	screenPrint(0, 12, "┃■                   ★(*'')/                           ■┃");
//	screenPrint(0, 13, "┃■                                    총점 :            ■┃");
//	screenPrint(0, 14, "┃■                                                      ■┃");
//	screenPrint(0, 15, "┃■        ◈◈◈◈◈◈◈  Game Over  ◈◈◈◈◈◈◈     ■┃");
//	screenPrint(0, 16, "┃■                                                      ■┃");
//	screenPrint(0, 17, "┃■                          ■■■■■■■■            ■┃");
//	screenPrint(0, 18, "┃■                          ■                          ■┃");
//	screenPrint(0, 19, "┃■                          ■                          ■┃");
//	screenPrint(0, 20, "┃■                          ■                          ■┃");
//	screenPrint(0, 21, "┃■                          ■                          ■┃");
//	screenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
//	screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
//}

SnakeGame::SnakeGame()
	:	m_eGameState(INIT),
		m_nStage(-1),
		m_state(nullptr)
{
	m_sStageInfo.m_nTotalGrade = 0; // 총점
	m_sStageInfo.LimitTime = clock();
	m_sStageInfo.nEatCount = 0;
	m_sStageInfo.nEnemyCount = 0;
	m_time.m_CurTime = clock();
	m_time.m_GameStartTime = clock();
	m_time.m_nLimitTime = clock();
	m_time.m_RemainTime = clock();
	m_time.m_UpdateOldTime = clock();

}

SnakeGame::~SnakeGame()
{

}

void SnakeGame::init()
{
	FILE *fp;

	if (m_nStage == -1) // 1번만 초기화가 되는 부분에 대한 처리 사항
	{
		m_nStage = 0;
	}

	fopen_s(&fp, kStrFileName[m_nStage], "r");
	fscanf_s(fp, "%d %d %d\n", &m_sStageInfo.LimitTime, &m_sStageInfo.nEatCount, &m_sStageInfo.nEnemyCount);
	fread(m_sStageInfo.nMap, sizeof(int), MAP_COL*MAP_ROW, fp);
	fclose(fp);
}

void SnakeGame::stateChange(SnakeState * _state)
{
	if (m_state)
		delete m_state;
	m_state = _state;
}

void SnakeGame::update()
{
	m_time.m_CurTime = clock();

	m_state->update(m_sStageInfo, m_eGameState, m_time, m_nPlayer, m_nStage);
}

void SnakeGame::render()
{
	Screen::GetInstance()->screenClear();

	m_state->render(m_sStageInfo, m_eGameState, m_time, m_nPlayer, m_nStage);

	Screen::GetInstance()->screenFlipping();
}

void SnakeGame::run()
{
	const int kmaxStage = 3;

	while (m_nStage != kmaxStage)
	{
		switch (m_eGameState)
		{
		case INIT:
			stateChange(new SnakeInitScene);
			break;
		case READY:
			stateChange(new SnakeReadyScene);
			break;
		case RUNNING:
			stateChange(new SnakeRunningScene);
			break;
		case SUCCESS:
			stateChange(new SnakeSuccessScene);
			break;
		case FAILED:
			stateChange(new SnakeFailedScene);
			break;
		case RESULT:
			stateChange(new SnakeResultScene);
			break;
		}

		m_eGameState = NONE;

		update();
		render();
	}
}
