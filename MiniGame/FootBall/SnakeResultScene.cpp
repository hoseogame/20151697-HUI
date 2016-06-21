#include "SnakeResultScene.h"

SnakeResultScene::SnakeResultScene()
{
}

SnakeResultScene::~SnakeResultScene()
{
}

void SnakeResultScene::render(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	char string[100];

	Screen::GetInstance()->screenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	Screen::GetInstance()->screenPrint(0, 1, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
	Screen::GetInstance()->screenPrint(0, 2, "早﹥                  ﹥                                  ﹥早");
	Screen::GetInstance()->screenPrint(0, 3, "早﹥                  ﹥                                  ﹥早");
	Screen::GetInstance()->screenPrint(0, 4, "早﹥                  ﹥                                  ﹥早");
	Screen::GetInstance()->screenPrint(0, 5, "早﹥          ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥                        ﹥早");
	Screen::GetInstance()->screenPrint(0, 6, "早﹥                                                      ﹥早");
	Screen::GetInstance()->screenPrint(0, 7, "早﹥                                                      ﹥早");
	Screen::GetInstance()->screenPrint(0, 8, "早﹥                  旨收收收收收收收收旬                ﹥早");
	Screen::GetInstance()->screenPrint(0, 9, "早﹥                  早≠   Sanke    ≠早                ﹥早");
	Screen::GetInstance()->screenPrint(0, 10, "早﹥                  曲收收收收收有收收旭                ﹥早");
	Screen::GetInstance()->screenPrint(0, 11, "早﹥                      /)/)    早 ≧                   ﹥早");
	Screen::GetInstance()->screenPrint(0, 12, "早﹥                   ≠(*'')/                           ﹥早");
	Screen::GetInstance()->screenPrint(0, 13, "早﹥                                    識薄 :            ﹥早");
	Screen::GetInstance()->screenPrint(0, 14, "早﹥                                                      ﹥早");
	Screen::GetInstance()->screenPrint(0, 15, "早﹥        ⅩⅩⅩⅩⅩⅩⅩ  Game Over  ⅩⅩⅩⅩⅩⅩⅩ     ﹥早");
	Screen::GetInstance()->screenPrint(0, 16, "早﹥                                                      ﹥早");
	Screen::GetInstance()->screenPrint(0, 17, "早﹥                          ﹥﹥﹥﹥﹥﹥﹥﹥            ﹥早");
	Screen::GetInstance()->screenPrint(0, 18, "早﹥                          ﹥                          ﹥早");
	Screen::GetInstance()->screenPrint(0, 19, "早﹥                          ﹥                          ﹥早");
	Screen::GetInstance()->screenPrint(0, 20, "早﹥                          ﹥                          ﹥早");
	Screen::GetInstance()->screenPrint(0, 21, "早﹥                          ﹥                          ﹥早");
	Screen::GetInstance()->screenPrint(0, 22, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
	Screen::GetInstance()->screenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	sprintf_s(string, "%d", _stageInfo.m_nTotalGrade);
	Screen::GetInstance()->screenPrint(48, 13, string);

}

void SnakeResultScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	if (_kbhit())
		exit(1);
}
