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

	Screen::GetInstance()->screenPrint(0, 0, "��������������������������������������������������������������");
	Screen::GetInstance()->screenPrint(0, 1, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 2, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 3, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 4, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 5, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 6, "��                       *.   .*                            ��");
	Screen::GetInstance()->screenPrint(0, 7, "��                    *.��������.*��                        ��");
	Screen::GetInstance()->screenPrint(0, 8, "��                    ��������������                        ��");
	Screen::GetInstance()->screenPrint(0, 9, "��                    ��������������                        ��");
	Screen::GetInstance()->screenPrint(0, 10, "��                    ��������������~                       ��");
	Screen::GetInstance()->screenPrint(0, 11, "��                    ������������                          ��");
	Screen::GetInstance()->screenPrint(0, 12, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 13, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 14, "��                      You Win!!                           ��");
	Screen::GetInstance()->screenPrint(0, 15, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 16, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 17, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 18, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 19, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 20, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 21, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 22, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 23, "��������������������������������������������������������������");

	sprintf_s(string, "%d", _Stage + 1);
	Screen::GetInstance()->screenPrint(19, 7, string);
	sprintf_s(string, "����: %d", _stageInfo.m_nTotalGrade);
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
