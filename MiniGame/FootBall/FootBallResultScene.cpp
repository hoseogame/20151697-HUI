#include "FootBallResultScene.h"

void FootBallResultScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if (_kbhit())
		exit(1);
}

void FootBallResultScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	char string[100];
	Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	Screen::GetInstance()->screenPrint(0, 1, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 2, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 3, "┃             □━━━□                   ┃");
	Screen::GetInstance()->screenPrint(0, 4, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 5, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 6, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 7, "┃                                          ┃");
							 sprintf_s(string, "┃      성공한 스테이지 :  %2d               ┃", _stage + 1);
	Screen::GetInstance()->screenPrint(0, 8, string);
	Screen::GetInstance()->screenPrint(0, 9, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 10, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 11, "┃   ___▒▒▒___                           ┃");
	Screen::GetInstance()->screenPrint(0, 12, "┃     (*^  ^*)                             ┃");
	Screen::GetInstance()->screenPrint(0, 13, "┃ =====○==○=====                         ┃");
	Screen::GetInstance()->screenPrint(0, 14, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 15, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 16, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 17, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 18, "┃                      ┗●┛              ┃");
	Screen::GetInstance()->screenPrint(0, 19, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 20, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 21, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
