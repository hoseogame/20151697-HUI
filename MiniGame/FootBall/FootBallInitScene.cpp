#include "FootBallInitScene.h"

void FootBallInitScene::update(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
}

void FootBallInitScene::render(FOOTBALLSTAGE_INFO& _stageInfo, GAME_STATE& _gameState, FOOTBALLTIME& _time, Player<int>& _player, int &_stage)
{
	if (_kbhit())
	{
		_player.getch();

		switch (_player.getKey())
		{
		case ' ':
			if (_stage == 0)
			{
				_gameState = READY;
				_time.UpdateOldTime = clock();  // ready蒂 橾薑衛除 雖樓п 輿晦 嬪п 							
			}
			break;
		}
	}
	

	if (_stage == 0)
	{ 
		Screen::GetInstance()->screenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
		Screen::GetInstance()->screenPrint(0, 1, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 2, "早             ﹤收收收﹤                   早");
		Screen::GetInstance()->screenPrint(0, 3, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 4, "早                        ///.   螂~~~      早");
		Screen::GetInstance()->screenPrint(0, 5, "早                       (^.^)              早");
		Screen::GetInstance()->screenPrint(0, 6, "早                      曲朽 曳旬           早");
		Screen::GetInstance()->screenPrint(0, 7, "早                         旨旭             早");
		Screen::GetInstance()->screenPrint(0, 8, "早                     Ⅸ  旭′             早");
		Screen::GetInstance()->screenPrint(0, 9, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 10, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 11, "早       螂 埤檣 啪歜  Go! Go!              早");
		Screen::GetInstance()->screenPrint(0, 12, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 13, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 14, "早       j :豭薹 l : 螃艇薹 k :螂           早");
		Screen::GetInstance()->screenPrint(0, 15, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 16, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 17, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 18, "早        曲≒旭  space 酈蒂 揚楝輿撮蹂     早");
		Screen::GetInstance()->screenPrint(0, 19, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 20, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 21, "早                                          早");
		Screen::GetInstance()->screenPrint(0, 22, "曲收收收收收收收收收收收收收收收收收收收收收旭");
	}
}
