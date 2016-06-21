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

	Screen::GetInstance()->screenPrint(0, 0, "��������������������������������������������������������������");
	Screen::GetInstance()->screenPrint(0, 1, "�������������������������������᦭");
	Screen::GetInstance()->screenPrint(0, 2, "����                  ��                                  �᦭");
	Screen::GetInstance()->screenPrint(0, 3, "����                  ��                                  �᦭");
	Screen::GetInstance()->screenPrint(0, 4, "����                  ��                                  �᦭");
	Screen::GetInstance()->screenPrint(0, 5, "����          �����������                        �᦭");
	Screen::GetInstance()->screenPrint(0, 6, "����                                                      �᦭");
	Screen::GetInstance()->screenPrint(0, 7, "����                                                      �᦭");
	Screen::GetInstance()->screenPrint(0, 8, "����                  ��������������������                �᦭");
	Screen::GetInstance()->screenPrint(0, 9, "����                  ����   Sanke    �ڦ�                �᦭");
	Screen::GetInstance()->screenPrint(0, 10, "����                  ��������������������                �᦭");
	Screen::GetInstance()->screenPrint(0, 11, "����                      /)/)    �� ��                   �᦭");
	Screen::GetInstance()->screenPrint(0, 12, "����                   ��(*'')/                           �᦭");
	Screen::GetInstance()->screenPrint(0, 13, "����                                    ���� :            �᦭");
	Screen::GetInstance()->screenPrint(0, 14, "����                                                      �᦭");
	Screen::GetInstance()->screenPrint(0, 15, "����        �¢¢¢¢¢¢�  Game Over  �¢¢¢¢¢¢�     �᦭");
	Screen::GetInstance()->screenPrint(0, 16, "����                                                      �᦭");
	Screen::GetInstance()->screenPrint(0, 17, "����                          ���������            �᦭");
	Screen::GetInstance()->screenPrint(0, 18, "����                          ��                          �᦭");
	Screen::GetInstance()->screenPrint(0, 19, "����                          ��                          �᦭");
	Screen::GetInstance()->screenPrint(0, 20, "����                          ��                          �᦭");
	Screen::GetInstance()->screenPrint(0, 21, "����                          ��                          �᦭");
	Screen::GetInstance()->screenPrint(0, 22, "�������������������������������᦭");
	Screen::GetInstance()->screenPrint(0, 23, "��������������������������������������������������������������");

	sprintf_s(string, "%d", _stageInfo.m_nTotalGrade);
	Screen::GetInstance()->screenPrint(48, 13, string);

}

void SnakeResultScene::update(SNAKESTAGE_INFO &_stageInfo, GAME_STATE &_gameState, SNAKETIME &_time, Player<int> &_plyer, int & _Stage)
{
	if (_kbhit())
		exit(1);
}
