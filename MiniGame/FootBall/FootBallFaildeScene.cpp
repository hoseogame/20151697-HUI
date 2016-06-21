#include "FootBallFaildeScene.h"

void FootBallFaildeScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if (_kbhit())
	{
		_player.getch();

		switch (_player.getKey())
		{
		case 'y':
		case 'Y':
			_time.UpdateOldTime = clock(); //init()
			_gameState = READY;
			break;
		case 'n':
		case 'N':
			_gameState = RESULT;
			break;
		}
	}

}

void FootBallFaildeScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	Screen::GetInstance()->screenPrint(0, 1, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 2, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 3, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 4, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 5, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 6, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 7, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 8, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 9, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 10, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 11, "┃                    미션 실패 !!!!        ┃");
	Screen::GetInstance()->screenPrint(0, 12, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 13, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 14, "┃                 ●┳━┓                 ┃");
	Screen::GetInstance()->screenPrint(0, 15, "┃                   ┛  ┗                 ┃");
	Screen::GetInstance()->screenPrint(0, 16, "┃                  ■■■■                ┃");
	Screen::GetInstance()->screenPrint(0, 17, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 18, "┃        다시 하시겠습니까? (y/n)          ┃");
	Screen::GetInstance()->screenPrint(0, 19, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 20, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 21, "┃                                          ┃");
	Screen::GetInstance()->screenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
