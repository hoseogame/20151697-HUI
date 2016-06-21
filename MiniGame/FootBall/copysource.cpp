//#include <stdio.h>
//#include <conio.h>
//#include <string.h>
//#include <windows.h>
//#include <time.h>
////#include <fmod.h>
//
//static int g_nScreenIndex;
//static HANDLE g_hScreen[2];
//
//void ScreenInit()
//{
//	CONSOLE_CURSOR_INFO cci;
//
//	// ������ �ܼ�â 2���� �����.
//	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	// Ŀ�� �����
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;
//	SetConsoleCursorInfo(g_hScreen[0], &cci);
//	SetConsoleCursorInfo(g_hScreen[1], &cci);
//}
//
//void ScreenFlipping()
//{
//	Sleep(10);
//	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
//	g_nScreenIndex = !g_nScreenIndex;
//}
//
//void ScreenClear()
//{
//	COORD Coor = { 0, 0 };
//	DWORD dw;
//	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
//}
//
//void ScreenRelease()
//{
//	CloseHandle(g_hScreen[0]);
//	CloseHandle(g_hScreen[1]);
//}
//
//void ScreenPrint(int x, int y, char *string)
//{
//	DWORD dw;
//	COORD CursorPosition = { x, y };
//	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
//	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
//}
//
//// 1 ~ 15 ���� ���� ���� ����
//void SetColor(unsigned short color)
//{
//	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
//}
//
//typedef enum _GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT } GAME_STATE;
//
//typedef struct _PLAYER
//{
//	int nCenterX, nCenterY;
//	int nMoveX, nMoveY;
//	int nX, nY;
//} PLAYER;
//
//typedef struct _BALL
//{
//	int nIsReady;        // �غ� ����(1), ������(0)
//	int nMoveX, nMoveY;  // �̵� ��ǥ
//	clock_t MoveTime;    // �̵� �ð� ����
//	clock_t OldTime;     // ���� �̵� �ð�
//} BALL;
//
//typedef struct _GOAL_DAE
//{
//	int nMoveX, nMoveY;     // �̵� ��ǥ 
//	int nLength;			// ��� ����	
//	int nLineX[7];			// ���� ���� x ��ǥ (7��)
//	clock_t	MoveTime;		// �̵� �ð� ����
//	clock_t	OldTime;	    // ���� �̵� �ð�
//	int	nDist;				// �̵� �Ÿ�
//} GOAL_DAE;
//
//typedef struct _EFFECT
//{
//	clock_t StratTime; // ȿ�� �߻� �ð�
//	clock_t StayTime;  // ȿ�� ���� �ð�	
//} EFFECT;
//
//typedef struct _STAGE_INFO
//{
//	int nGoalBall;			// �����ؾ� �� ���� ���� 
//	clock_t LimitTime;      // ���� �ð� 
//	int nGoalDaeLength;		// ��� ���� 
//	int nGoalDaeX;			// ��� �̵� X ��ǥ
//	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
//	clock_t MoveTime;		// ��� �̵� �ð� ����
//	int nDist;				// ��� �̵� �Ÿ�
//} STAGE_INFO;
//
//GOAL_DAE g_sGoalDae;
//BALL g_sBall;
//PLAYER g_sPlayer;
//EFFECT g_sEffect;
//
//char g_strPlayer[] = "�����ܦ���";
//STAGE_INFO g_sStageInfo[] = { { 3, 1000 * 20, 1, 20, 3, 300, 1 },{ 10, 1000 * 30, 2, 20, 5, 300, 1 } };
//int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
//clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;
//
//GAME_STATE g_GameState = INIT;
//
//void InitScreen()
//{
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "��                                          ��");
//	ScreenPrint(0, 2, "��             �ব������                   ��");
//	ScreenPrint(0, 3, "��                                          ��");
//	ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
//	ScreenPrint(0, 5, "��                       (^.^)              ��");
//	ScreenPrint(0, 6, "��                      ���� ����           ��");
//	ScreenPrint(0, 7, "��                         ����             ��");
//	ScreenPrint(0, 8, "��                     ��  ����             ��");
//	ScreenPrint(0, 9, "��                                          ��");
//	ScreenPrint(0, 10, "��                                          ��");
//	ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
//	ScreenPrint(0, 12, "��                                          ��");
//	ScreenPrint(0, 13, "��                                          ��");
//	ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
//	ScreenPrint(0, 15, "��                                          ��");
//	ScreenPrint(0, 16, "��                                          ��");
//	ScreenPrint(0, 17, "��                                          ��");
//	ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
//	ScreenPrint(0, 19, "��                                          ��");
//	ScreenPrint(0, 20, "��                                          ��");
//	ScreenPrint(0, 21, "��                                          ��");
//	ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//void ReadyScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "�����������������������᦭");
//	ScreenPrint(0, 2, "�����������������������᦭");
//	ScreenPrint(0, 3, "�����������������������᦭");
//	ScreenPrint(0, 4, "�����������������������᦭");
//	ScreenPrint(0, 5, "�����������������������᦭");
//	ScreenPrint(0, 6, "�����������������������᦭");
//	ScreenPrint(0, 7, "�����������������������᦭");
//	ScreenPrint(0, 8, "�����������������������᦭");
//	ScreenPrint(0, 9, "�����������������������᦭");
//	ScreenPrint(0, 10, "��������                    ������᦭");
//	sprintf_s(string, "��������     %d   ��������   ������᦭", g_nStage + 1);
//	ScreenPrint(0, 11, string);
//	ScreenPrint(0, 12, "��������                    ������᦭");
//	ScreenPrint(0, 13, "�����������������������᦭");
//	ScreenPrint(0, 14, "�����������������������᦭");
//	ScreenPrint(0, 15, "�����������������������᦭");
//	ScreenPrint(0, 16, "�����������������������᦭");
//	ScreenPrint(0, 17, "�����������������������᦭");
//	ScreenPrint(0, 18, "�����������������������᦭");
//	ScreenPrint(0, 19, "�����������������������᦭");
//	ScreenPrint(0, 20, "�����������������������᦭");
//	ScreenPrint(0, 21, "�����������������������᦭");
//	ScreenPrint(0, 22, "�����������������������᦭");
//	ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void BackScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "��                                          ��");
//	ScreenPrint(0, 2, "��                                          ��");
//	ScreenPrint(0, 3, "��                                          ��");
//	sprintf_s(string, "��                                          ����������: %d", g_nStage + 1);
//	ScreenPrint(0, 4, string);
//	ScreenPrint(0, 5, "��                                          ��");
//	sprintf_s(string, "�������������������������������������������������� �ð�: %d", g_sStageInfo[g_nStage].LimitTime / 1000);
//	ScreenPrint(0, 6, string);
//	ScreenPrint(0, 7, "��                                          ��");
//	sprintf_s(string, "��                                          ������ �ð�: %d", (clock() - g_GameStartTime) / 1000);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "��                                          ��");
//	sprintf_s(string, "��                                          ����ǥ ����: %d ", g_sStageInfo[g_nStage].nGoalBall);
//	ScreenPrint(0, 10, string);
//	ScreenPrint(0, 11, "��                                          ��");
//	sprintf_s(string, "��                                          ������ �� ����: %d ", g_nBallCount);
//	ScreenPrint(0, 12, string);
//
//	ScreenPrint(0, 13, "��                                          ��");
//	sprintf_s(string, "��                                          ��");
//	ScreenPrint(0, 14, string);
//	ScreenPrint(0, 15, "��                                          ��");
//	sprintf_s(string, "��                                          ��");
//	ScreenPrint(0, 16, string);
//	ScreenPrint(0, 17, "��                                          ��");
//	ScreenPrint(0, 18, "��                                          ��");
//	ScreenPrint(0, 19, "��                                          ��");
//	ScreenPrint(0, 20, "��                                          ��");
//	ScreenPrint(0, 21, "��                                          ��");
//	ScreenPrint(0, 22, "��                                          ��");
//	ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void GoalMessage(int nX, int nY)
//{
//	ScreenPrint(nX, nY, "�� )) ���� (( ��");
//	ScreenPrint(nX, nY + 1, "��(^^')/ ��(\"*')/");
//	ScreenPrint(nX, nY + 2, "   ��       ��");
//	ScreenPrint(nX, nY + 3, "  ����    ����");
//}
//
//void SuccessScreen()
//{
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "��                                          ��");
//	ScreenPrint(0, 2, "��                                          ��");
//	ScreenPrint(0, 3, "��                                          ��");
//	ScreenPrint(0, 4, "��                                          ��");
//	ScreenPrint(0, 5, "��                                          ��");
//	ScreenPrint(0, 6, "��                ////����                  ��");
//	ScreenPrint(0, 7, "��               q ��  �� p                 ��");
//	ScreenPrint(0, 8, "��               (��������)                 ��");
//	ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
//	ScreenPrint(0, 10, "��                                          ��");
//	ScreenPrint(0, 11, "��                                          ��");
//	ScreenPrint(0, 12, "��                                          ��");
//	ScreenPrint(0, 13, "��                                          ��");
//	ScreenPrint(0, 14, "��                                          ��");
//	ScreenPrint(0, 15, "��                                          ��");
//	ScreenPrint(0, 16, "��                                          ��");
//	ScreenPrint(0, 17, "��                                          ��");
//	ScreenPrint(0, 18, "��                                          ��");
//	ScreenPrint(0, 19, "��                                          ��");
//	ScreenPrint(0, 20, "��                                          ��");
//	ScreenPrint(0, 21, "��                                          ��");
//	ScreenPrint(0, 22, "��                                          ��");
//	ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void FailureScreen()
//{
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "��                                          ��");
//	ScreenPrint(0, 2, "��                                          ��");
//	ScreenPrint(0, 3, "��                                          ��");
//	ScreenPrint(0, 4, "��                                          ��");
//	ScreenPrint(0, 5, "��                                          ��");
//	ScreenPrint(0, 6, "��                                          ��");
//	ScreenPrint(0, 7, "��                                          ��");
//	ScreenPrint(0, 8, "��                                          ��");
//	ScreenPrint(0, 9, "��                                          ��");
//	ScreenPrint(0, 10, "��                                          ��");
//	ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
//	ScreenPrint(0, 12, "��                                          ��");
//	ScreenPrint(0, 13, "��                                          ��");
//	ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
//	ScreenPrint(0, 15, "��                   ��  ��                 ��");
//	ScreenPrint(0, 16, "��                  �����                ��");
//	ScreenPrint(0, 17, "��                                          ��");
//	ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
//	ScreenPrint(0, 19, "��                                          ��");
//	ScreenPrint(0, 20, "��                                          ��");
//	ScreenPrint(0, 21, "��                                          ��");
//	ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//void ResultScreen()
//{
//	char string[100];
//	ScreenPrint(0, 0, "����������������������������������������������");
//	ScreenPrint(0, 1, "��                                          ��");
//	ScreenPrint(0, 2, "��                                          ��");
//	ScreenPrint(0, 3, "��             �ব������                   ��");
//	ScreenPrint(0, 4, "��                                          ��");
//	ScreenPrint(0, 5, "��                                          ��");
//	ScreenPrint(0, 6, "��                                          ��");
//	ScreenPrint(0, 7, "��                                          ��");
//	sprintf_s(string, "��      ������ �������� :  %2d               ��", g_nStage + 1);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "��                                          ��");
//	ScreenPrint(0, 10, "��                                          ��");
//	ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
//	ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
//	ScreenPrint(0, 13, "�� =====��==��=====                         ��");
//	ScreenPrint(0, 14, "��                                          ��");
//	ScreenPrint(0, 15, "��                                          ��");
//	ScreenPrint(0, 16, "��                                          ��");
//	ScreenPrint(0, 17, "��                                          ��");
//	ScreenPrint(0, 18, "��                      ���ܦ�              ��");
//	ScreenPrint(0, 19, "��                                          ��");
//	ScreenPrint(0, 20, "��                                          ��");
//	ScreenPrint(0, 21, "��                                          ��");
//	ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//void Init()
//{
//	int nLength;
//
//	if (g_nStage == -1)
//	{
//		g_nStage = 0;
//	}
//
//	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;  // ���� �ð� ����
//	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall; // ��ǥ ���� ����
//
//	g_sPlayer.nCenterX = 4;
//	g_sPlayer.nCenterY = 0;
//	g_sPlayer.nMoveX = 20;
//	g_sPlayer.nMoveY = 22;
//	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//	g_nLength = strlen(g_strPlayer);
//
//	// ���� �ʱ�ȭ
//	g_sBall.nIsReady = 1;
//	g_sBall.nMoveX = g_sPlayer.nMoveX;
//	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//	g_sBall.MoveTime = 100;
//
//	// ��� �ʱ�ȭ
//	g_sGoalDae.nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;
//	g_sGoalDae.nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
//	g_sGoalDae.nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
//	g_sGoalDae.MoveTime = g_sStageInfo[g_nStage].MoveTime;
//	g_sGoalDae.OldTime = clock();
//	g_sGoalDae.nDist = g_sStageInfo[g_nStage].nDist;
//	nLength = g_sGoalDae.nLength * 2 + 1; // Note: �迭�� �ִ� ����
//
//	for (int i = 0; i < nLength; i++)
//	{
//		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
//	}
//
//	// ȿ�� 
//	g_sEffect.StayTime = 2000; // 2�� ����
//	g_nGoal = 0;      // �������� �Ϸ� ����
//	g_UpdateOldTime = clock();
//	g_nBallCount = 0;  // ������ ���� ����
//}
//
//void Update()
//{
//	clock_t CurTime = clock();
//	int nLength = g_sGoalDae.nLength * 2 + 1; // Note: �迭�� �ִ� ����
//
//	switch (g_GameState)
//	{
//	case READY:
//		if (CurTime - g_UpdateOldTime > 2000)  // 2��
//		{
//			g_GameState = RUNNING;
//			g_GameStartTime = CurTime;
//		}
//		break;
//	case RUNNING:
//		if (CurTime - g_GameStartTime > g_LimitTime) // Note: ���� �ð�
//		{
//			g_GameState = STOP;
//			return;
//		}
//		else {
//			// Note: ���
//			if (CurTime - g_sGoalDae.OldTime > g_sGoalDae.MoveTime)
//			{
//				g_sGoalDae.OldTime = CurTime;
//				if (g_sGoalDae.nMoveX + g_sGoalDae.nDist >= 2 && ((g_sGoalDae.nLineX[nLength - 1] + 3) + g_sGoalDae.nDist) <= 43)
//				{
//					g_sGoalDae.nMoveX += g_sGoalDae.nDist;
//					for (int i = 0; i < nLength; i++)
//					{
//						g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
//					}
//				}
//				else {
//					g_sGoalDae.nDist = g_sGoalDae.nDist * -1; // -1 �� ������ �ٲپ� ��.
//				}
//			}
//
//			if (g_sBall.nIsReady == 0) // �̵� ���� �� 
//			{	// �̵� �ð� ���ݿ� ���� �̵�
//				if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime)
//				{
//					if (g_sBall.nMoveY - 1 > 0)
//					{
//						g_sBall.nMoveY--;
//						g_sBall.OldTime = CurTime; // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
//						// ��� ���� �浹
//						if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // �� �ʱ�ȭ
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//								g_nBallCount++;  // ������ ���� ����										
//
//								if (g_nBallCount == g_nGoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS g_nGoal = 1
//								{
//									g_GameState = STOP;
//									g_nGoal = 1;
//									return;
//								}
//
//								// ȿ�� ���
//								if (g_nIsGoal == 0)
//								{
//									g_nIsGoal = 1;
//									g_sEffect.StratTime = CurTime;
//								}
//							}
//							// ��� �浹 
//						}
//						else if ((g_sBall.nMoveX >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength - 1] + 3) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 3))
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // �� �ʱ�ȭ
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//							}
//						}
//					}
//					else { // �� �ʱ�ȭ
//						g_sBall.nIsReady = 1;
//						g_sBall.nMoveX = g_sPlayer.nMoveX;
//						g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//					}
//				}
//			}
//			else {
//				g_sBall.nMoveX = g_sPlayer.nMoveX;
//			}
//
//			// ȿ�� 
//			if (g_nIsGoal == 1)
//			{
//				if (CurTime - g_sEffect.StratTime > g_sEffect.StayTime)
//					g_nIsGoal = 0;
//			}
//		}
//		break;
//	case STOP:
//		if (g_nGoal == 1)
//		{
//			g_GameState = SUCCESS;
//			g_UpdateOldTime = CurTime;
//		}
//		else {
//			g_GameState = FAILED;
//		}
//		break;
//	case SUCCESS:
//		if (CurTime - g_UpdateOldTime > 3000)
//		{
//			g_UpdateOldTime = CurTime;
//			++g_nStage;
//			Init();
//			g_GameState = READY;
//		}
//		break;
//	}
//}
//
//void Render()
//{
//	char string[100] = { 0, };
//	int nLength;
//
//	ScreenClear();
//
//	switch (g_GameState)
//	{
//	case INIT:
//		if (g_nStage == 0)
//			InitScreen();
//		break;
//	case READY:
//		ReadyScreen();
//		break;
//	case RUNNING:
//		BackScreen();
//		ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "��");
//		nLength = g_sGoalDae.nLength * 2 + 1;
//
//		for (int i = 0; i < nLength; i++)
//			ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "��");
//
//		ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.nMoveY, "��");
//
//		// Note: ȿ�� ���  	
//		if (g_nIsGoal == 1)
//		{
//			GoalMessage(10, 10);
//		}
//
//		// Note: 2 �÷��� Ŭ���� 
//		if (g_sPlayer.nX < 2)  //  ���� Ŭ���� ó��
//			ScreenPrint(2, g_sPlayer.nMoveY, &g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
//		else if (g_sPlayer.nMoveX + (g_nLength - g_sPlayer.nCenterX + 1) > 43) // ������ Ŭ���� ó��
//		{
//			strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 43));
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
//		}
//		else { // 1 �÷��� �̵�
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer);
//		}
//
//		ScreenPrint(g_sBall.nMoveX, g_sBall.nMoveY, "��");
//		break;
//	case SUCCESS:
//		SuccessScreen();
//		break;
//	case FAILED:
//		FailureScreen();
//		break;
//	case RESULT:
//		ResultScreen();
//		break;
//	}
//
//	// Note: ������ �� 
//	ScreenFlipping();
//}
//
//int main(void)
//{
//	int nKey, nRemain;
//
//	ScreenInit();
//	Init();        // �ʱ�ȭ
//
//	while (1)
//	{
//		if (_kbhit())
//		{
//			if (g_GameState == RESULT)
// 				break;
//
//			nKey = _getch();
//
//			switch (nKey)
//			{
//			case 'j':
//				if (g_sPlayer.nMoveX > 2) // ���� �浹 ��� ��ǥ üũ
//				{
//					g_sPlayer.nMoveX--;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
//																  // Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
//					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
//						g_sPlayer.nMoveX--;
//
//					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//				}
//				break;
//			case 'l':
//				if (g_sPlayer.nMoveX + 1 < 43) // ������ �浹 ��� ��ǥ üũ
//				{
//					g_sPlayer.nMoveX++;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
//																  // Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
//					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
//						g_sPlayer.nMoveX++;
//
//					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//				}
//				break;
//			case 'k':
//				if (g_sBall.nIsReady && g_GameState == RUNNING)
//				{
//					g_sBall.nMoveX = g_sPlayer.nMoveX;
//					g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//					g_sBall.OldTime = clock();
//					g_sBall.nIsReady = 0;
//				}
//				break;
//
//			case 'y':
//			case 'Y':
//				if (g_GameState == FAILED)
//				{
//					Init();
//					g_GameState = READY;
//				}
//				break;
//			case 'n':
//			case 'N':
//				if (g_GameState == FAILED)
//				{
//					g_GameState = RESULT;						
//				}
//				break;
//
//			case ' ':
//				if (g_GameState == INIT && g_nStage == 0)
//				{
//					g_GameState = READY;
//					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
//				}
//				break;
//			}
//		}
//
//
//
//		Update();    // ������ ����
//		Render();    // ȭ�� ���
//	}
//	ScreenRelease();
//	return 0;
//}
