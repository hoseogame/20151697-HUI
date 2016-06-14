//#include <iostream>
//#include <conio.h>
//#include <ctime>
//#include <cstdlib>
//#include "Screen.h"
//
//using namespace std;
//
//#define MAP_COL  29
//#define MAP_ROW  22
//
//typedef enum _GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT } GAME_STATE;
//typedef enum _DIRECT { LEFT, RIGHT, UP, DOWN, LAST } DIRECT;
//
//typedef struct _POS
//{
//	int nX, nY;
//	int nOldX, nOldY;
//} POS;
//
//typedef struct _STAGE_INFO
//{
//	int nEnemyCount;                // Note: �� ĳ������ ����
//	clock_t LimitTime;              // Note: ���������� ���� �ð�
//	int nEatCount;                  // Note: ���� ����
//	int nMap[MAP_ROW][MAP_COL];		// Note: �� ���� 
//} STAGE_INFO;
//
//typedef struct _SNAKE
//{
//	int	nLife;
//	DIRECT nDirect;
//	clock_t	MoveTime;
//	clock_t	OldTime;
//	POS	sHead;
//	POS	sTail[20];
//} SNAKE;
//
//typedef struct _ENEMY
//{
//	int nLife;
//	int nX, nY;
//	DIRECT nDirect;
//	clock_t MoveTime;
//	clock_t OldTime;
//} ENEMY;
//
//SNAKE g_sSnake;
//ENEMY* g_pEnemy = NULL;
//STAGE_INFO g_StageInfo;
//
//char *g_strFileName[3] = { "map1.bin", "map1.bin", "map1.bin" };
//char g_StateShape[5][3] = { "��", "��", "��", "��", "��" };
//int g_nEatCount;
//clock_t g_nLimitTime;
//GAME_STATE		g_nGameState = INIT;
//int				g_nStage = -1;
//int				g_nGrade = 0; // ���� 
//int				g_nTotalGrade = 0; // ����
//clock_t			g_GameStartTime, g_UpdateOldTime, g_RemainTime;
//
//void InitScreen() // ���� �Ұ� ȭ��
//{
//	ScreenPrint(0, 0, "��������������������������������������������������������������");
//	ScreenPrint(0, 1, "�������������������������������᦭");
//	ScreenPrint(0, 2, "����                                                      �᦭");
//	ScreenPrint(0, 3, "����                                                      �᦭");
//	ScreenPrint(0, 4, "����           ��  ������          ��                 �᦭");
//	ScreenPrint(0, 5, "����         ��  ���                     ��              �᦭");
//	ScreenPrint(0, 6, "����           ��   ��������������������                  �᦭");
//	ScreenPrint(0, 7, "����       ����   ����   Snake    �ڦ�                  �᦭");
//	ScreenPrint(0, 8, "����                ��������������������                  �᦭");
//	ScreenPrint(0, 9, "����     ��               /)/)  �� ��     ���������᦭");
//	ScreenPrint(0, 10, "����                 ��(*'')/                             �᦭");
//	ScreenPrint(0, 11, "����                                       ��   ��        �᦭");
//	ScreenPrint(0, 12, "����                 ��                                   �᦭");
//	ScreenPrint(0, 13, "����    �������                                      �᦭");
//	ScreenPrint(0, 14, "����              ��               �ܡߡ�                 �᦭");
//	ScreenPrint(0, 15, "����      ����    ��                   ��                 �᦭");
//	ScreenPrint(0, 16, "����              ��  Press Space Key !! �ߡߡߡߡߡ�     �᦭");
//	ScreenPrint(0, 17, "����              ��                                      �᦭");
//	ScreenPrint(0, 18, "����              ������     ��  �� ������        �᦭");
//	ScreenPrint(0, 19, "����                                    ��                �᦭");
//	ScreenPrint(0, 20, "����                                    ��     ��  ��     �᦭");
//	ScreenPrint(0, 21, "����                                    ��                �᦭");
//	ScreenPrint(0, 22, "�������������������������������᦭");
//	ScreenPrint(0, 23, "��������������������������������������������������������������");
//}
//
//void ReadyScreen()
//{
//	ScreenPrint(0, 0, "��������������������������������������������������������������");
//	ScreenPrint(0, 1, "��                                                          ��");
//	ScreenPrint(0, 2, "��                                                          ��");
//	ScreenPrint(0, 3, "��                                                          ��");
//	ScreenPrint(0, 4, "��                                                          ��");
//	ScreenPrint(0, 5, "��                                                          ��");
//	ScreenPrint(0, 6, "��                                                          ��");
//	ScreenPrint(0, 7, "��                                                          ��");
//	ScreenPrint(0, 8, "��                                          ��              ��");
//	ScreenPrint(0, 9, "��                                    �С리����            ��");
//	ScreenPrint(0, 10, "��                                        �С린            ��");
//	ScreenPrint(0, 11, "��                                        ������            ��");
//	ScreenPrint(0, 12, "��                                                          ��");
//	ScreenPrint(0, 13, "��                                                          ��");
//	ScreenPrint(0, 14, "��                                                          ��");
//	ScreenPrint(0, 15, "��                                                          ��");
//	ScreenPrint(0, 16, "��                                                          ��");
//	ScreenPrint(0, 17, "��                                                          ��");
//	ScreenPrint(0, 18, "��                                                          ��");
//	ScreenPrint(0, 19, "��                                                          ��");
//	ScreenPrint(0, 20, "��                                                          ��");
//	ScreenPrint(0, 21, "��                                                          ��");
//	ScreenPrint(0, 22, "��                                                          ��");
//	ScreenPrint(0, 23, "��������������������������������������������������������������");
//}
//
//void SuccessScreen()
//{
//	ScreenPrint(0, 0, "��������������������������������������������������������������");
//	ScreenPrint(0, 1, "��                                                          ��");
//	ScreenPrint(0, 2, "��                                                          ��");
//	ScreenPrint(0, 3, "��                                                          ��");
//	ScreenPrint(0, 4, "��                                                          ��");
//	ScreenPrint(0, 5, "��                                                          ��");
//	ScreenPrint(0, 6, "��                       *.   .*                            ��");
//	ScreenPrint(0, 7, "��                    *.��������.*��                        ��");
//	ScreenPrint(0, 8, "��                    ��������������                        ��");
//	ScreenPrint(0, 9, "��                    ��������������                        ��");
//	ScreenPrint(0, 10, "��                    ��������������~                       ��");
//	ScreenPrint(0, 11, "��                    ������������                          ��");
//	ScreenPrint(0, 12, "��                                                          ��");
//	ScreenPrint(0, 13, "��                                                          ��");
//	ScreenPrint(0, 14, "��                      You Win!!                           ��");
//	ScreenPrint(0, 15, "��                                                          ��");
//	ScreenPrint(0, 16, "��                                                          ��");
//	ScreenPrint(0, 17, "��                                                          ��");
//	ScreenPrint(0, 18, "��                                                          ��");
//	ScreenPrint(0, 19, "��                                                          ��");
//	ScreenPrint(0, 20, "��                                                          ��");
//	ScreenPrint(0, 21, "��                                                          ��");
//	ScreenPrint(0, 22, "��                                                          ��");
//	ScreenPrint(0, 23, "��������������������������������������������������������������");
//}
//
//void FailureScreen()
//{
//	ScreenPrint(0, 0, "��������������������������������������������������������������");
//	ScreenPrint(0, 1, "��                                                          ��");
//	ScreenPrint(0, 2, "��                                                          ��");
//	ScreenPrint(0, 3, "��                                                          ��");
//	ScreenPrint(0, 4, "��                                                          ��");
//	ScreenPrint(0, 5, "��                                                          ��");
//	ScreenPrint(0, 6, "��                                                          ��");
//	ScreenPrint(0, 7, "��                     *�Ѧ�  �Ѧ�*                         ��");
//	ScreenPrint(0, 8, "��                  *.  �Ӥӡ�Ӥ�   .*                     ��");
//	ScreenPrint(0, 9, "��               ���ѤѤѤѤѤѤѤѤѤѦ�                   ��");
//	ScreenPrint(0, 10, "��               ��     �̼� ����      ��                   ��");
//	ScreenPrint(0, 11, "��               ���ѤѤѤѤѤѤѤѤѤѦ�                   ��");
//	ScreenPrint(0, 12, "��                                                          ��");
//	ScreenPrint(0, 13, "��                                                          ��");
//	ScreenPrint(0, 14, "��                   (*�ҡ�*)                               ��");
//	ScreenPrint(0, 15, "��                  ��O������O����������������������        ��");
//	ScreenPrint(0, 16, "��                  ������Ͻðڽ��ϱ�? <y/n>     ��        ��");
//	ScreenPrint(0, 17, "��                  ��������������������������������        ��");
//	ScreenPrint(0, 18, "��                                                          ��");
//	ScreenPrint(0, 19, "��                                                          ��");
//	ScreenPrint(0, 20, "��                                                          ��");
//	ScreenPrint(0, 21, "��                                                          ��");
//	ScreenPrint(0, 22, "��                                                          ��");
//	ScreenPrint(0, 23, "��������������������������������������������������������������");
//}
//
//void ResultScreen()
//{
//	ScreenPrint(0, 0, "��������������������������������������������������������������");
//	ScreenPrint(0, 1, "�������������������������������᦭");
//	ScreenPrint(0, 2, "����                  ��                                  �᦭");
//	ScreenPrint(0, 3, "����                  ��                                  �᦭");
//	ScreenPrint(0, 4, "����                  ��                                  �᦭");
//	ScreenPrint(0, 5, "����          �����������                        �᦭");
//	ScreenPrint(0, 6, "����                                                      �᦭");
//	ScreenPrint(0, 7, "����                                                      �᦭");
//	ScreenPrint(0, 8, "����                  ��������������������                �᦭");
//	ScreenPrint(0, 9, "����                  ����   Sanke    �ڦ�                �᦭");
//	ScreenPrint(0, 10, "����                  ��������������������                �᦭");
//	ScreenPrint(0, 11, "����                      /)/)    �� ��                   �᦭");
//	ScreenPrint(0, 12, "����                   ��(*'')/                           �᦭");
//	ScreenPrint(0, 13, "����                                    ���� :            �᦭");
//	ScreenPrint(0, 14, "����                                                      �᦭");
//	ScreenPrint(0, 15, "����        �¢¢¢¢¢¢�  Game Over  �¢¢¢¢¢¢�     �᦭");
//	ScreenPrint(0, 16, "����                                                      �᦭");
//	ScreenPrint(0, 17, "����                          ���������            �᦭");
//	ScreenPrint(0, 18, "����                          ��                          �᦭");
//	ScreenPrint(0, 19, "����                          ��                          �᦭");
//	ScreenPrint(0, 20, "����                          ��                          �᦭");
//	ScreenPrint(0, 21, "����                          ��                          �᦭");
//	ScreenPrint(0, 22, "�������������������������������᦭");
//	ScreenPrint(0, 23, "��������������������������������������������������������������");
//}
//
//void Move()
//{
//	// Note: Step 1 . ��� ���� ��ǥ�� ���� ��ǥ�� ����
//	g_sSnake.sHead.nOldX = g_sSnake.sHead.nX;
//	g_sSnake.sHead.nOldY = g_sSnake.sHead.nY;
//
//	for (int i = 0; i < g_sSnake.nLife - 1; i++)
//	{
//		g_sSnake.sTail[i].nOldX = g_sSnake.sTail[i].nX;
//		g_sSnake.sTail[i].nOldY = g_sSnake.sTail[i].nY;
//	}
//
//	// Note: Step 2. ���� ��ǥ�� ���� ��ǥ�� ����
//	g_sSnake.sTail[0].nX = g_sSnake.sHead.nOldX;
//	g_sSnake.sTail[0].nY = g_sSnake.sHead.nOldY;
//
//	for (int i = 1; i < g_sSnake.nLife - 1; i++)
//	{
//		g_sSnake.sTail[i].nX = g_sSnake.sTail[i - 1].nOldX;
//		g_sSnake.sTail[i].nY = g_sSnake.sTail[i - 1].nOldY;
//	}
//}
//
//void Init()
//{
//	int nIndex;
//	FILE *fp;
//
//	if (g_nStage == -1) // 1���� �ʱ�ȭ�� �Ǵ� �κп� ���� ó�� ����
//	{
//		g_nStage = 0;
//	}
//
//	fopen_s(&fp, g_strFileName[g_nStage], "r");
//	fscanf_s(fp, "%d %d %d\n", &g_StageInfo.LimitTime, &g_StageInfo.nEatCount, &g_StageInfo.nEnemyCount);
//	fread(g_StageInfo.nMap, sizeof(int), MAP_COL*MAP_ROW, fp);
//	fclose(fp);
//
//	// �� ĳ���� ����
//	if (g_pEnemy != NULL)
//		free(g_pEnemy);
//
//	g_pEnemy = (ENEMY*)malloc(sizeof(ENEMY) * g_StageInfo.nEnemyCount);
//	srand((unsigned int)time(NULL)); // ���� �߻��� �ʱ�ȭ	
//	nIndex = 0;
//
//	// Note: �� ĳ���� ���� ����
//	for (int i = 0; i < MAP_ROW; i++)
//	{
//		for (int j = 0; j < MAP_COL; j++)
//		{
//			if (g_StageInfo.nMap[i][j] == 2)
//			{
//				g_pEnemy[nIndex].nLife = 1;
//				g_pEnemy[nIndex].nX = j;
//				g_pEnemy[nIndex].nY = i;
//				g_pEnemy[nIndex].nDirect = static_cast<DIRECT>(rand() % LAST);
//				g_pEnemy[nIndex].OldTime = clock();
//				g_pEnemy[nIndex].MoveTime = rand() % 100 + 100; // �ּ� 100���� 299����
//
//				g_StageInfo.nMap[i][j] = -1; // ���� ���·� ��ȯ
//				nIndex++;
//			}
//		}
//	}
//
//	// Note: ���ΰ� ���� ����
//	for (int i = 0; i < MAP_ROW; i++)
//	{
//		for (int j = 0; j < MAP_COL; j++)
//		{
//			if (g_StageInfo.nMap[i][j] == 3)
//			{
//				g_sSnake.sHead.nX = j;
//				g_sSnake.sHead.nY = i;
//				g_StageInfo.nMap[i][j] = -1; // ���� ���·� ��ȯ
//
//											 // for�� 2�� Ż�� ����
//				i = MAP_ROW;
//				j = MAP_COL;
//			}
//		}
//	}
//
//	g_sSnake.sHead.nOldX = g_sSnake.sHead.nX;
//	g_sSnake.sHead.nOldY = g_sSnake.sHead.nY;
//	g_sSnake.MoveTime = 100;
//	g_sSnake.OldTime = clock();
//	g_sSnake.nDirect = LEFT;
//	g_sSnake.nLife = 4;
//
//	// Note: Snake ���� �ʱ�ȭ, �⺻ 3��
//	for (int i = 0; i < 3; i++)
//	{
//		g_sSnake.sTail[i].nX = g_sSnake.sHead.nX + i + 1;
//		g_sSnake.sTail[i].nY = g_sSnake.sHead.nY;
//	}
//
//	g_nEatCount = 0; // ���� ���� ����
//	g_nGrade = 0;
//}
//
//// Note: �� ĳ���Ϳ� �浹 üũ 
//int IsCollision(int nX, int nY)
//{
//	for (int i = 0; i < g_StageInfo.nEnemyCount; i++)
//	{
//		if (g_pEnemy[i].nLife == 1)
//		{
//			if (g_pEnemy[i].nX == nX && g_pEnemy[i].nY == nY)
//			{
//				g_pEnemy[i].nLife = 0;
//				return 1; ///�浹
//			}
//		}
//	}
//
//	return 0;
//}
//
//void Update()
//{
//	int i, j;
//	clock_t CurTime = clock();
//	DIRECT nDirect;
//
//	switch (g_nGameState)
//	{
//	case READY:
//		if (CurTime - g_UpdateOldTime > 3000)  // 2��
//		{
//			g_nGameState = RUNNING;
//			g_GameStartTime = CurTime;
//		}
//		break;
//
//	case RUNNING:
//		g_RemainTime = (g_StageInfo.LimitTime - (CurTime - g_GameStartTime)) / 1000; // ���� ���� ���� �ð�
//
//		if ((CurTime - g_GameStartTime) > g_StageInfo.LimitTime || g_nEatCount == g_StageInfo.nEatCount)
//		{
//			g_nGameState = STOP;
//			return;
//		}
//
//		// Note: ���ΰ� �̵�
//		if (CurTime - g_sSnake.OldTime > g_sSnake.MoveTime)
//		{
//			g_sSnake.OldTime = CurTime;
//			switch (g_sSnake.nDirect)
//			{
//			case LEFT:
//				if (g_sSnake.sHead.nX - 1 >= 0)
//				{
//					// �浹 üũ 
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] == 0) // ���� �浹 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] == 1) // ���̸� ���� ��찡 �ȴ�.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] = -1; // ���̴� �������� ó��
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX - 1, g_sSnake.sHead.nY))// ��ĳ���Ϳ� �浹�� ���
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // ������ �ִ� ���̴�.
//						Move();
//
//					g_sSnake.sHead.nX--;
//				}
//				break;
//
//			case RIGHT:
//				if (g_sSnake.sHead.nX + 1 < MAP_COL)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] == 0) // ���� �浹 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] == 1) // ���̸� ���� ��찡 �ȴ�.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] = -1; // �������� ó��
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX + 1, g_sSnake.sHead.nY))// ��ĳ���Ϳ� �浹�� ���
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // ������ �ִ� ���̴�.
//						Move();
//
//					g_sSnake.sHead.nX++;
//				}
//				break;
//
//			case UP:
//				if (g_sSnake.sHead.nY - 1 >= 0)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] == 0) // ���� �浹 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] == 1) // ���̸� ���� ��찡 �ȴ�.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] = -1; // �������� ó��
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX, g_sSnake.sHead.nY - 1))// ��ĳ���Ϳ� �浹�� ���
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // ������ �ִ� ���̴�.
//						Move();
//					g_sSnake.sHead.nY--;
//				}
//				break;
//
//			case DOWN:
//				if (g_sSnake.sHead.nY + 1 < MAP_ROW)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] == 0) // ���� �浹 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] == 1) // ���̸� ���� ��찡 �ȴ�.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] = -1; // �������� ó��
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX, g_sSnake.sHead.nY + 1))// ��ĳ���Ϳ� �浹�� ���
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // ������ �ִ� ���̴�.
//						Move();
//					g_sSnake.sHead.nY++;
//				}
//				break;
//			}
//		}
//
//		// �� ĳ���� �̵�
//		for (i = 0; i < g_StageInfo.nEnemyCount; i++)
//		{
//			if (g_pEnemy[i].nLife == 1)
//			{
//				// �� ĳ������ ���� ��ȯ�� �̵��� ���Ѱ�
//				if (CurTime - g_pEnemy[i].OldTime > g_pEnemy[i].MoveTime)
//				{
//					g_pEnemy[i].OldTime = CurTime;
//
//					switch (g_pEnemy[i].nDirect)
//					{
//					case LEFT:
//						if (g_pEnemy[i].nX - 1 >= 0)
//						{
//							// ���� �ε��� ���
//							if (g_StageInfo.nMap[g_pEnemy[i].nY][g_pEnemy[i].nX - 1] == 0)
//							{
//								// ���� ��ȯ�� ���� ���� �κ�
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != LEFT)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // ���ο� ������ �����Ѵ�
//							}
//							else {
//								g_pEnemy[i].nX--;
//							}
//						}
//						break;
//					case RIGHT:
//						if (g_pEnemy[i].nX + 1 < MAP_COL)
//						{
//							// ���� �ε��� ���
//							if (g_StageInfo.nMap[g_pEnemy[i].nY][g_pEnemy[i].nX + 1] == 0)
//							{
//								// ���� ��ȯ�� ���� ���� �κ�
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != RIGHT)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // ���ο� ������ �����Ѵ�
//							}
//							else {
//								g_pEnemy[i].nX++;
//							}
//						}
//						break;
//					case UP:
//						if (g_pEnemy[i].nY - 1 >= 0)
//						{
//							// ���� �ε��� ���
//							if (g_StageInfo.nMap[g_pEnemy[i].nY - 1][g_pEnemy[i].nX] == 0)
//							{
//								// ���� ��ȯ�� ���� ���� �κ�
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != UP)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // ���ο� ������ �����Ѵ�
//							}
//							else {
//								g_pEnemy[i].nY--;
//							}
//						}
//						break;
//					case DOWN:
//						// ���� �ε��� ���
//						if (g_pEnemy[i].nY + 1 < MAP_ROW)
//						{
//
//							if (g_StageInfo.nMap[g_pEnemy[i].nY + 1][g_pEnemy[i].nX] == 0)
//							{
//								// ���� ��ȯ�� ���� ���� �κ�
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != DOWN)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // ���ο� ������ �����Ѵ�
//							}
//							else {
//								g_pEnemy[i].nY++;
//							}
//						}
//						break;
//					}
//				}
//
//				// �� �Ӹ��� �� ĳ������ �浹
//				if (g_sSnake.sHead.nX == g_pEnemy[i].nX && g_sSnake.sHead.nY == g_pEnemy[i].nY)
//				{
//					g_pEnemy[i].nLife = 0;
//					g_sSnake.nLife--;
//
//					if (g_sSnake.nLife < 1) // �Ӹ��� ������ ������ �����Ѵ�.
//					{
//						g_nGameState = STOP;
//						return;
//					}
//				}
//
//				// �� ������ �� ĳ������ �浹
//				for (j = 0; j < g_sSnake.nLife - 1; j++)
//				{
//					if (g_pEnemy[i].nX == g_sSnake.sTail[j].nX && g_pEnemy[i].nY == g_sSnake.sTail[j].nY)
//					{
//						g_pEnemy[i].nLife = 0;
//						g_sSnake.nLife--;
//					}
//				}
//			}
//		}
//
//		break;
//	case STOP:
//		//// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.  
//		if (g_nEatCount >= g_StageInfo.nEatCount)
//		{
//			g_UpdateOldTime = CurTime;
//			g_nGameState = SUCCESS;
//			g_nTotalGrade += g_nGrade;
//		}
//		else {
//			g_nGameState = FAILED;
//		}
//		break;
//
//	case SUCCESS:
//		if (CurTime - g_UpdateOldTime > 3000)
//		{
//			g_UpdateOldTime = CurTime;
//			++g_nStage;
//			Init();
//			g_nGameState = READY;
//		}
//		break;
//	}
//}
//
//
//void Render()
//{
//	int i, j;
//	char string[100];
//	static int nMap[MAP_ROW][MAP_COL]; // ��¿�
//
//	ScreenClear();
//
//	switch (g_nGameState)
//	{
//	case INIT:
//		if (g_nStage == 0)
//			InitScreen();
//		break;
//
//	case READY:
//		ReadyScreen();
//		sprintf(string, "%d Stage", g_nStage + 1);
//		ScreenPrint(23, 9, string);
//		break;
//
//	case RUNNING:
//		//��¿� �ʿ� ���� 
//		memcpy(nMap, g_StageInfo.nMap, sizeof(int)*MAP_ROW*MAP_COL);
//
//		//// �� ĳ���� �׸���
//		for (i = 0; i < g_StageInfo.nEnemyCount; i++)
//		{
//			if (g_pEnemy[i].nLife == 1)
//			{
//				nMap[g_pEnemy[i].nY][g_pEnemy[i].nX] = 2;
//			}
//		}
//
//		// ���ΰ� �Ӹ�
//		nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX] = 3;
//
//		// ����
//		for (i = 0; i < g_sSnake.nLife - 1; i++)
//			nMap[g_sSnake.sTail[i].nY][g_sSnake.sTail[i].nX] = 4;
//
//		for (i = 0; i < MAP_ROW; i++)
//		{
//			for (j = 0; j < MAP_COL; j++)
//			{
//				if (nMap[i][j] == -1)
//					ScreenPrint((j * 2) + 2, i + 1, "  ");
//				else
//					ScreenPrint((j * 2) + 2, i + 1, g_StateShape[nMap[i][j]]);
//			}
//		}
//
//		// Note: �������� ���� ���
//		sprintf(string, "%d Stage", g_nStage + 1);
//		ScreenPrint(61, 5, string);
//		sprintf(string, "�����ð�: %d�� %d��", g_RemainTime / 60, g_RemainTime % 60);
//		ScreenPrint(61, 7, string);
//		sprintf(string, "���̼�: %d", g_nEatCount);
//		ScreenPrint(61, 9, string);
//		sprintf(string, "����: %d", g_nGrade);
//		ScreenPrint(61, 11, string);
//		break;
//	case SUCCESS:
//		SuccessScreen();
//		sprintf(string, "%d", g_nStage + 1);
//		ScreenPrint(19, 7, string);
//		sprintf(string, "����: %d", g_nTotalGrade);
//		ScreenPrint(18, 17, string);
//		break;
//	case FAILED:
//		FailureScreen();
//		break;
//
//	case RESULT:
//		ResultScreen();
//		sprintf(string, "%d", g_nTotalGrade);
//		ScreenPrint(48, 13, string);
//		break;
//	}
//
//	ScreenFlipping();
//}
//
//void Release()
//{
//	if (g_pEnemy != NULL)
//		free(g_pEnemy);
//}
//
//
//int main(void)
//{
//	int nKey;
//	clock_t CurTime;
//
//	ScreenInit();
//	Init();
//
//	while (1)
//	{
//		CurTime = clock();
//		if (_kbhit())
//		{
//			if (g_nGameState == RESULT)
//				break;
//
//			nKey = _getch();
//
//			switch (nKey)
//			{
//			case ' ':
//				if (g_nGameState == INIT && g_nStage == 0)
//				{
//					g_nGameState = READY;
//					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
//				}
//				break;
//			case 75:
//				g_sSnake.nDirect = LEFT;
//				break;
//
//			case 77:
//				g_sSnake.nDirect = RIGHT;
//				break;
//
//			case 72:
//				g_sSnake.nDirect = UP;
//				break;
//
//			case 80:
//				g_sSnake.nDirect = DOWN;
//				break;
//
//			case 'y':
//			case 'Y':
//				if (g_nGameState == FAILED)
//				{
//					Init();
//					g_nGameState = READY;
//					g_UpdateOldTime = clock();
//				}
//				break;
//			case 'n':
//			case 'N':
//				if (g_nGameState == FAILED)
//				{
//					g_nGameState = RESULT;
//				}
//				break;
//			}
//		}
//
//		Update();
//		Render();
//	}
//
//	Release();
//	ScreenRelease();
//
//	return 0;
//}