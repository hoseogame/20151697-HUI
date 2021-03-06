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
	Screen::GetInstance()->screenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
	Screen::GetInstance()->screenPrint(0, 1, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 2, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 3, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 4, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 5, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 6, "早                ////′′                  早");
	Screen::GetInstance()->screenPrint(0, 7, "早               q ∥  ∥ p                 早");
	Screen::GetInstance()->screenPrint(0, 8, "早               (戌式式戎)                 早");
	Screen::GetInstance()->screenPrint(0, 9, "早             Ｏ 嘐暮 撩奢 Ｎ              早");
	Screen::GetInstance()->screenPrint(0, 10, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 11, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 12, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 13, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 14, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 15, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 16, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 17, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 18, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 19, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 20, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 21, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 22, "早                                          早");
	Screen::GetInstance()->screenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收旭");
}
