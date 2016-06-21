#include "SnakeFailedScene.h"

SnakeFailedScene::SnakeFailedScene()
{
}

void SnakeFailedScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	Screen::GetInstance()->screenPrint(0, 1, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 2, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 3, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 4, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 5, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 6, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 7, "┃                     *┭┮  ┭┮*                         ┃");
	Screen::GetInstance()->screenPrint(0, 8, "┃                  *.  ㅣㅣ▽ㅣㅣ   .*                     ┃");
	Screen::GetInstance()->screenPrint(0, 9, "┃               ┏ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┓                   ┃");
	Screen::GetInstance()->screenPrint(0, 10, "┃               ┃     미션 실패      ┃                   ┃");
	Screen::GetInstance()->screenPrint(0, 11, "┃               ┗ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┛                   ┃");
	Screen::GetInstance()->screenPrint(0, 12, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 13, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 14, "┃                   (*⌒⌒*)                               ┃");
	Screen::GetInstance()->screenPrint(0, 15, "┃                  ┏O━━━O━━━━━━━━━━┓        ┃");
	Screen::GetInstance()->screenPrint(0, 16, "┃                  ┃계속하시겠습니까? <y/n>     ┃        ┃");
	Screen::GetInstance()->screenPrint(0, 17, "┃                  ┗━━━━━━━━━━━━━━┛        ┃");
	Screen::GetInstance()->screenPrint(0, 18, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 19, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 20, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 21, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 22, "┃                                                          ┃");
	Screen::GetInstance()->screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void SnakeFailedScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_player, int & _Stage)
{
	if (_kbhit())
	{
		_player.getch();

		switch (_player.getKey())
		{
		case 'y':
		case 'Y':
			FILE *fp;

			fopen_s(&fp, kStrFileName[_Stage], "r");
			fscanf_s(fp, "%d %d %d\n", &_stageInfo.LimitTime, &_stageInfo.nEatCount, &_stageInfo.nEnemyCount);
			fread(_stageInfo.nMap, sizeof(int), MAP_COL*MAP_ROW, fp);
			fclose(fp);

			Screen::GetInstance()->screenInit();
			_gameState = READY;
			_time.m_UpdateOldTime = clock();
			break;
		case 'n':
		case 'N':
			_gameState = RESULT;
			break;
		}
	}
}
