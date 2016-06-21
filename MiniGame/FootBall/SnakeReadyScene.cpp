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

	Screen::GetInstance()->screenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	Screen::GetInstance()->screenPrint(0, 1, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 2, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 3, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 4, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 5, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 6, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 7, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 8, "早                                          ≒              早");
	Screen::GetInstance()->screenPrint(0, 9, "早                                    Ｂ㏑收早汕            早");
	Screen::GetInstance()->screenPrint(0, 10, "早                                        Ｂ㏑旭            早");
	Screen::GetInstance()->screenPrint(0, 11, "早                                        旨朴旬            早");
	Screen::GetInstance()->screenPrint(0, 12, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 13, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 14, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 15, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 16, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 17, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 18, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 19, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 20, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 21, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 22, "早                                                          早");
	Screen::GetInstance()->screenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	sprintf_s(string, "%d Stage", _Stage + 1);
	Screen::GetInstance()->screenPrint(23, 9, string);
}

void SnakeReadyScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	clock_t CurTime = clock();

	if (CurTime - _time.m_UpdateOldTime > 3000)  // 2蟾
	{
		_gameState = RUNNING;
		_time.m_GameStartTime = CurTime;
	}
}
