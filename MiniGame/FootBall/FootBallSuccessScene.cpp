#include "FootBallSuccessScene.h"

void FootBallSuccessScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if (_time.CurTime - _time.UpdateOldTime > 3000)
	{
		_time.UpdateOldTime = _time.CurTime;
		++_stage;
		_time.UpdateOldTime = clock(); //init()
		_gameState = READY;
	}
}

void FootBallSuccessScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	Screen::GetInstance()->screenPrint(0, 1, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 2, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 3, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 4, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 5, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 6, "┃                ////＼＼                  ┃");
	Screen::GetInstance()->screenPrint(0, 7, "┃               q ∧  ∧ p                 ┃");
	Screen::GetInstance()->screenPrint(0, 8, "┃               (└──┘)                 ┃");
	Screen::GetInstance()->screenPrint(0, 9, "┃             ♬ 미션 성공 ♪              ┃");
	Screen::GetInstance()->screenPrint(0, 10, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 11, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 12, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 13, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 14, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 15, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 16, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 17, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 18, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 19, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 20, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 21, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 22, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
