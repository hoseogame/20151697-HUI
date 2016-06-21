#include "SnakeInitScene.h"

SnakeInitScene::SnakeInitScene()
{
}

SnakeInitScene::~SnakeInitScene()
{
}

void SnakeInitScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
		Screen::GetInstance()->screenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		Screen::GetInstance()->screenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
		Screen::GetInstance()->screenPrint(0, 2, "┃■                                                      ■┃");
		Screen::GetInstance()->screenPrint(0, 3, "┃■                                                      ■┃");
		Screen::GetInstance()->screenPrint(0, 4, "┃■           ◎  ■■■■■          ◎                 ■┃");
		Screen::GetInstance()->screenPrint(0, 5, "┃■         ♥  ■■                     ♥              ■┃");
		Screen::GetInstance()->screenPrint(0, 6, "┃■           ■   ┏━━━━━━━━┓                  ■┃");
		Screen::GetInstance()->screenPrint(0, 7, "┃■       ■■■   ┃★   Snake    ★┃                  ■┃");
		Screen::GetInstance()->screenPrint(0, 8, "┃■                ┗━━━━━┳━━┛                  ■┃");
		Screen::GetInstance()->screenPrint(0, 9, "┃■     ◎               /)/)  ┃ ☆     ■■■■■■■■■┃");
		Screen::GetInstance()->screenPrint(0, 10, "┃■                 ★(*'')/                             ■┃");
		Screen::GetInstance()->screenPrint(0, 11, "┃■                                       ◎   ♥        ■┃");
		Screen::GetInstance()->screenPrint(0, 12, "┃■                 ◎                                   ■┃");
		Screen::GetInstance()->screenPrint(0, 13, "┃■    ■■■■■■                                      ■┃");
		Screen::GetInstance()->screenPrint(0, 14, "┃■              ■               ●◆◆                 ■┃");
		Screen::GetInstance()->screenPrint(0, 15, "┃■      ♥◎    ■                   ◆                 ■┃");
		Screen::GetInstance()->screenPrint(0, 16, "┃■              ■  Press Space Key !! ◆◆◆◆◆◆     ■┃");
		Screen::GetInstance()->screenPrint(0, 17, "┃■              ■                                      ■┃");
		Screen::GetInstance()->screenPrint(0, 18, "┃■              ■■■■■     ◎  ♥ ■■■■■        ■┃");
		Screen::GetInstance()->screenPrint(0, 19, "┃■                                    ■                ■┃");
		Screen::GetInstance()->screenPrint(0, 20, "┃■                                    ■     ◎  ♥     ■┃");
		Screen::GetInstance()->screenPrint(0, 21, "┃■                                    ■                ■┃");
		Screen::GetInstance()->screenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■■■■■■■■■┃");
		Screen::GetInstance()->screenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void SnakeInitScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_player, int & _Stage)
{
	if (_kbhit())
	{
		_player.getch();

		switch (_player.getKey())
		{
		case ' ':
			if (_Stage == 0)
			{
				_gameState = READY;
				_time.m_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
			}
		}
	}
}
