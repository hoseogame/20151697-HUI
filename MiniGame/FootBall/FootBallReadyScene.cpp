#include "FootBallReadyScene.h"

void FootBallReadyScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if (_time.CurTime - _time.UpdateOldTime > 2000)  // 2초
	{
		_gameState = RUNNING;
		_time.GameStartTime = _time.CurTime;
	}
}

void FootBallReadyScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	char string[100];

	Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	Screen::GetInstance()->screenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 2, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 3, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 4, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 5, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 6, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 7, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 8, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 9, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 10, "┃■■■■■                    ■■■■■■┃");
							 sprintf_s(string, "┃■■■■■     %d   스테이지   ■■■■■■┃", _stage + 1);
	Screen::GetInstance()->screenPrint(0, 11, string);
	Screen::GetInstance()->screenPrint(0, 12, "┃■■■■■                    ■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 13, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 14, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 15, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 16, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 17, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 18, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 19, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 20, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 21, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	Screen::GetInstance()->screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
