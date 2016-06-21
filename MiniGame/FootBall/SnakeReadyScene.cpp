#include "SnakeReadyScene.h"

SnakeReadyScene::SnakeReadyScene()
{
}

SnakeReadyScene::~SnakeReadyScene()
{
}

void SnakeReadyScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	char string[10];

	Screen::GetInstance()->screenPrint(0, 0, "��������������������������������������������������������������");
	Screen::GetInstance()->screenPrint(0, 1, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 2, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 3, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 4, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 5, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 6, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 7, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 8, "��                                          ��              ��");
	Screen::GetInstance()->screenPrint(0, 9, "��                                    �С리����            ��");
	Screen::GetInstance()->screenPrint(0, 10, "��                                        �С린            ��");
	Screen::GetInstance()->screenPrint(0, 11, "��                                        ������            ��");
	Screen::GetInstance()->screenPrint(0, 12, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 13, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 14, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 15, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 16, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 17, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 18, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 19, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 20, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 21, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 22, "��                                                          ��");
	Screen::GetInstance()->screenPrint(0, 23, "��������������������������������������������������������������");

	sprintf_s(string, "%d Stage", _Stage + 1);
	Screen::GetInstance()->screenPrint(23, 9, string);
}

void SnakeReadyScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	clock_t CurTime = clock();

	if (CurTime - _time.m_UpdateOldTime > 3000)  // 2��
	{
		_gameState = RUNNING;
		_time.m_GameStartTime = CurTime;
	}
}
