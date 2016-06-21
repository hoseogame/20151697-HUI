#include "SnakeSuccessScene.h"

SnakeSuccessScene::SnakeSuccessScene()
{
}

SnakeSuccessScene::~SnakeSuccessScene()
{
}

void SnakeSuccessScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	char string[100];

	Screen::GetInstance()->screenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	Screen::GetInstance()->screenPrint(0, 1, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 2, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 3, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 4, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 5, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 6, "早                       *.   .*                            早");
	Screen::GetInstance()->screenPrint(0, 7, "早                    *.旨旬旨旬.*渠                        早");
	Screen::GetInstance()->screenPrint(0, 8, "早                    旨朴朽曳朴旬欽                        早");
	Screen::GetInstance()->screenPrint(0, 9, "早                    早收朽曳收早п                        早");
	Screen::GetInstance()->screenPrint(0, 10, "早                    早收朽曳收早蹂~                       早");
	Screen::GetInstance()->screenPrint(0, 11, "早                    曲收旭曲收旭                          早");
	Screen::GetInstance()->screenPrint(0, 12, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 13, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 14, "早                      You Win!!                           早");
	Screen::GetInstance()->screenPrint(0, 15, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 16, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 17, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 18, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 19, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 20, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 21, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 22, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	sprintf_s(string, "%d", _Stage + 1);
	Screen::GetInstance()->screenPrint(19, 7, string);
	sprintf_s(string, "識薄: %d", _stageInfo.m_nTotalGrade);
	Screen::GetInstance()->screenPrint(18, 17, string);
}

void SnakeSuccessScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	clock_t CurTime = clock();

	if (CurTime - _time.m_UpdateOldTime > 3000)
	{
		FILE *fp;

		_time.m_UpdateOldTime = CurTime;
		++_Stage;
		_gameState = READY;
		if (kLast_Stage == _Stage)
		{
			_gameState = RESULT;
			return;
		}

		fopen_s(&fp, kStrFileName[_Stage], "r");
		fscanf_s(fp, "%d %d %d\n", &_stageInfo.LimitTime, &_stageInfo.nEatCount, &_stageInfo.nEnemyCount);
		fread(_stageInfo.nMap, sizeof(int), MAP_COL*MAP_ROW, fp);
		fclose(fp);

		Screen::GetInstance()->screenInit();
	}
}
