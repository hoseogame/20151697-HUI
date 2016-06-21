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
				_time.UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
			}
			break;
		}
	}
	

	if (_stage == 0)
	{ 
		Screen::GetInstance()->screenPrint(0, 0, "����������������������������������������������");
		Screen::GetInstance()->screenPrint(0, 1, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 2, "��             �ব������                   ��");
		Screen::GetInstance()->screenPrint(0, 3, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 4, "��                        ///.   ��~~~      ��");
		Screen::GetInstance()->screenPrint(0, 5, "��                       (^.^)              ��");
		Screen::GetInstance()->screenPrint(0, 6, "��                      ���� ����           ��");
		Screen::GetInstance()->screenPrint(0, 7, "��                         ����             ��");
		Screen::GetInstance()->screenPrint(0, 8, "��                     ��  ����             ��");
		Screen::GetInstance()->screenPrint(0, 9, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 10, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
		Screen::GetInstance()->screenPrint(0, 12, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 13, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
		Screen::GetInstance()->screenPrint(0, 15, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 16, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 17, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
		Screen::GetInstance()->screenPrint(0, 19, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 20, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 21, "��                                          ��");
		Screen::GetInstance()->screenPrint(0, 22, "����������������������������������������������");
	}
}
