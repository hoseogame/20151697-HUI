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
//	int nEnemyCount;                // Note: 瞳 議葛攪曖 偃熱
//	clock_t LimitTime;              // Note: 蝶纔檜雖曖 薯и 衛除
//	int nEatCount;                  // Note: 詳檜 偃熱
//	int nMap[MAP_ROW][MAP_COL];		// Note: 裘 薑爾 
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
//char g_StateShape[5][3] = { "﹥", "Ⅵ", "Ⅸ", "≒", "﹣" };
//int g_nEatCount;
//clock_t g_nLimitTime;
//GAME_STATE		g_nGameState = INIT;
//int				g_nStage = -1;
//int				g_nGrade = 0; // 薄熱 
//int				g_nTotalGrade = 0; // 識薄
//clock_t			g_GameStartTime, g_UpdateOldTime, g_RemainTime;
//
//void InitScreen() // 啪歜 模偃 �飛�
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 2, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 3, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 4, "早﹥           ≡  ﹥﹥﹥﹥﹥          ≡                 ﹥早");
//	ScreenPrint(0, 5, "早﹥         Ⅵ  ﹥﹥                     Ⅵ              ﹥早");
//	ScreenPrint(0, 6, "早﹥           ﹥   旨收收收收收收收收旬                  ﹥早");
//	ScreenPrint(0, 7, "早﹥       ﹥﹥﹥   早≠   Snake    ≠早                  ﹥早");
//	ScreenPrint(0, 8, "早﹥                曲收收收收收有收收旭                  ﹥早");
//	ScreenPrint(0, 9, "早﹥     ≡               /)/)  早 ≧     ﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 10, "早﹥                 ≠(*'')/                             ﹥早");
//	ScreenPrint(0, 11, "早﹥                                       ≡   Ⅵ        ﹥早");
//	ScreenPrint(0, 12, "早﹥                 ≡                                   ﹥早");
//	ScreenPrint(0, 13, "早﹥    ﹥﹥﹥﹥﹥﹥                                      ﹥早");
//	ScreenPrint(0, 14, "早﹥              ﹥               ≒﹣﹣                 ﹥早");
//	ScreenPrint(0, 15, "早﹥      Ⅵ≡    ﹥                   ﹣                 ﹥早");
//	ScreenPrint(0, 16, "早﹥              ﹥  Press Space Key !! ﹣﹣﹣﹣﹣﹣     ﹥早");
//	ScreenPrint(0, 17, "早﹥              ﹥                                      ﹥早");
//	ScreenPrint(0, 18, "早﹥              ﹥﹥﹥﹥﹥     ≡  Ⅵ ﹥﹥﹥﹥﹥        ﹥早");
//	ScreenPrint(0, 19, "早﹥                                    ﹥                ﹥早");
//	ScreenPrint(0, 20, "早﹥                                    ﹥     ≡  Ⅵ     ﹥早");
//	ScreenPrint(0, 21, "早﹥                                    ﹥                ﹥早");
//	ScreenPrint(0, 22, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void ReadyScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                                          早");
//	ScreenPrint(0, 2, "早                                                          早");
//	ScreenPrint(0, 3, "早                                                          早");
//	ScreenPrint(0, 4, "早                                                          早");
//	ScreenPrint(0, 5, "早                                                          早");
//	ScreenPrint(0, 6, "早                                                          早");
//	ScreenPrint(0, 7, "早                                                          早");
//	ScreenPrint(0, 8, "早                                          ≒              早");
//	ScreenPrint(0, 9, "早                                    Ｂ㏑收早汕            早");
//	ScreenPrint(0, 10, "早                                        Ｂ㏑旭            早");
//	ScreenPrint(0, 11, "早                                        旨朴旬            早");
//	ScreenPrint(0, 12, "早                                                          早");
//	ScreenPrint(0, 13, "早                                                          早");
//	ScreenPrint(0, 14, "早                                                          早");
//	ScreenPrint(0, 15, "早                                                          早");
//	ScreenPrint(0, 16, "早                                                          早");
//	ScreenPrint(0, 17, "早                                                          早");
//	ScreenPrint(0, 18, "早                                                          早");
//	ScreenPrint(0, 19, "早                                                          早");
//	ScreenPrint(0, 20, "早                                                          早");
//	ScreenPrint(0, 21, "早                                                          早");
//	ScreenPrint(0, 22, "早                                                          早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void SuccessScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                                          早");
//	ScreenPrint(0, 2, "早                                                          早");
//	ScreenPrint(0, 3, "早                                                          早");
//	ScreenPrint(0, 4, "早                                                          早");
//	ScreenPrint(0, 5, "早                                                          早");
//	ScreenPrint(0, 6, "早                       *.   .*                            早");
//	ScreenPrint(0, 7, "早                    *.旨旬旨旬.*渠                        早");
//	ScreenPrint(0, 8, "早                    旨朴朽曳朴旬欽                        早");
//	ScreenPrint(0, 9, "早                    早收朽曳收早п                        早");
//	ScreenPrint(0, 10, "早                    早收朽曳收早蹂~                       早");
//	ScreenPrint(0, 11, "早                    曲收旭曲收旭                          早");
//	ScreenPrint(0, 12, "早                                                          早");
//	ScreenPrint(0, 13, "早                                                          早");
//	ScreenPrint(0, 14, "早                      You Win!!                           早");
//	ScreenPrint(0, 15, "早                                                          早");
//	ScreenPrint(0, 16, "早                                                          早");
//	ScreenPrint(0, 17, "早                                                          早");
//	ScreenPrint(0, 18, "早                                                          早");
//	ScreenPrint(0, 19, "早                                                          早");
//	ScreenPrint(0, 20, "早                                                          早");
//	ScreenPrint(0, 21, "早                                                          早");
//	ScreenPrint(0, 22, "早                                                          早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void FailureScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                                          早");
//	ScreenPrint(0, 2, "早                                                          早");
//	ScreenPrint(0, 3, "早                                                          早");
//	ScreenPrint(0, 4, "早                                                          早");
//	ScreenPrint(0, 5, "早                                                          早");
//	ScreenPrint(0, 6, "早                                                          早");
//	ScreenPrint(0, 7, "早                     *老考  老考*                         早");
//	ScreenPrint(0, 8, "早                  *.  太太∩太太   .*                     早");
//	ScreenPrint(0, 9, "早               旨天天天天天天天天天天旬                   早");
//	ScreenPrint(0, 10, "早               早     嘐暮 褒ぬ      早                   早");
//	ScreenPrint(0, 11, "早               曲天天天天天天天天天天旭                   早");
//	ScreenPrint(0, 12, "早                                                          早");
//	ScreenPrint(0, 13, "早                                                          早");
//	ScreenPrint(0, 14, "早                   (*÷÷*)                               早");
//	ScreenPrint(0, 15, "早                  旨O收收收O收收收收收收收收收收旬        早");
//	ScreenPrint(0, 16, "早                  早啗樓ж衛啊蝗棲梱? <y/n>     早        早");
//	ScreenPrint(0, 17, "早                  曲收收收收收收收收收收收收收收旭        早");
//	ScreenPrint(0, 18, "早                                                          早");
//	ScreenPrint(0, 19, "早                                                          早");
//	ScreenPrint(0, 20, "早                                                          早");
//	ScreenPrint(0, 21, "早                                                          早");
//	ScreenPrint(0, 22, "早                                                          早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void ResultScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 2, "早﹥                  ﹥                                  ﹥早");
//	ScreenPrint(0, 3, "早﹥                  ﹥                                  ﹥早");
//	ScreenPrint(0, 4, "早﹥                  ﹥                                  ﹥早");
//	ScreenPrint(0, 5, "早﹥          ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥                        ﹥早");
//	ScreenPrint(0, 6, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 7, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 8, "早﹥                  旨收收收收收收收收旬                ﹥早");
//	ScreenPrint(0, 9, "早﹥                  早≠   Sanke    ≠早                ﹥早");
//	ScreenPrint(0, 10, "早﹥                  曲收收收收收有收收旭                ﹥早");
//	ScreenPrint(0, 11, "早﹥                      /)/)    早 ≧                   ﹥早");
//	ScreenPrint(0, 12, "早﹥                   ≠(*'')/                           ﹥早");
//	ScreenPrint(0, 13, "早﹥                                    識薄 :            ﹥早");
//	ScreenPrint(0, 14, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 15, "早﹥        ⅩⅩⅩⅩⅩⅩⅩ  Game Over  ⅩⅩⅩⅩⅩⅩⅩ     ﹥早");
//	ScreenPrint(0, 16, "早﹥                                                      ﹥早");
//	ScreenPrint(0, 17, "早﹥                          ﹥﹥﹥﹥﹥﹥﹥﹥            ﹥早");
//	ScreenPrint(0, 18, "早﹥                          ﹥                          ﹥早");
//	ScreenPrint(0, 19, "早﹥                          ﹥                          ﹥早");
//	ScreenPrint(0, 20, "早﹥                          ﹥                          ﹥早");
//	ScreenPrint(0, 21, "早﹥                          ﹥                          ﹥早");
//	ScreenPrint(0, 22, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void Move()
//{
//	// Note: Step 1 . 賅萇 ⑷營 謝ル蒂 檜瞪 謝ル煎 犒餌
//	g_sSnake.sHead.nOldX = g_sSnake.sHead.nX;
//	g_sSnake.sHead.nOldY = g_sSnake.sHead.nY;
//
//	for (int i = 0; i < g_sSnake.nLife - 1; i++)
//	{
//		g_sSnake.sTail[i].nOldX = g_sSnake.sTail[i].nX;
//		g_sSnake.sTail[i].nOldY = g_sSnake.sTail[i].nY;
//	}
//
//	// Note: Step 2. 檜瞪 謝ル蒂 ⑷營 謝ル煎 犒餌
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
//	if (g_nStage == -1) // 1廓虜 蟾晦�降� 腎朝 睡碟縑 渠и 籀葬 餌о
//	{
//		g_nStage = 0;
//	}
//
//	fopen_s(&fp, g_strFileName[g_nStage], "r");
//	fscanf_s(fp, "%d %d %d\n", &g_StageInfo.LimitTime, &g_StageInfo.nEatCount, &g_StageInfo.nEnemyCount);
//	fread(g_StageInfo.nMap, sizeof(int), MAP_COL*MAP_ROW, fp);
//	fclose(fp);
//
//	// 瞳 議葛攪 撲薑
//	if (g_pEnemy != NULL)
//		free(g_pEnemy);
//
//	g_pEnemy = (ENEMY*)malloc(sizeof(ENEMY) * g_StageInfo.nEnemyCount);
//	srand((unsigned int)time(NULL)); // 陪熱 嫦儅擊 蟾晦��	
//	nIndex = 0;
//
//	// Note: 瞳 議葛攪 蹺轎 婁薑
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
//				g_pEnemy[nIndex].MoveTime = rand() % 100 + 100; // 譆模 100縑憮 299梱雖
//
//				g_StageInfo.nMap[i][j] = -1; // 奢寥 鼻鷓煎 瞪��
//				nIndex++;
//			}
//		}
//	}
//
//	// Note: 輿檣奢 蹺轎 婁薑
//	for (int i = 0; i < MAP_ROW; i++)
//	{
//		for (int j = 0; j < MAP_COL; j++)
//		{
//			if (g_StageInfo.nMap[i][j] == 3)
//			{
//				g_sSnake.sHead.nX = j;
//				g_sSnake.sHead.nY = i;
//				g_StageInfo.nMap[i][j] = -1; // 奢寥 鼻鷓煎 瞪��
//
//											 // for僥 2偃 驍轎 褻勒
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
//	// Note: Snake 窒葬 蟾晦��, 晦獄 3偃
//	for (int i = 0; i < 3; i++)
//	{
//		g_sSnake.sTail[i].nX = g_sSnake.sHead.nX + i + 1;
//		g_sSnake.sTail[i].nY = g_sSnake.sHead.nY;
//	}
//
//	g_nEatCount = 0; // 詳檜 詳擎 偃熱
//	g_nGrade = 0;
//}
//
//// Note: 瞳 議葛攪諦 醱給 羹觼 
//int IsCollision(int nX, int nY)
//{
//	for (int i = 0; i < g_StageInfo.nEnemyCount; i++)
//	{
//		if (g_pEnemy[i].nLife == 1)
//		{
//			if (g_pEnemy[i].nX == nX && g_pEnemy[i].nY == nY)
//			{
//				g_pEnemy[i].nLife = 0;
//				return 1; ///醱給
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
//		if (CurTime - g_UpdateOldTime > 3000)  // 2蟾
//		{
//			g_nGameState = RUNNING;
//			g_GameStartTime = CurTime;
//		}
//		break;
//
//	case RUNNING:
//		g_RemainTime = (g_StageInfo.LimitTime - (CurTime - g_GameStartTime)) / 1000; // 啪歜 霞ч 陴擎 衛除
//
//		if ((CurTime - g_GameStartTime) > g_StageInfo.LimitTime || g_nEatCount == g_StageInfo.nEatCount)
//		{
//			g_nGameState = STOP;
//			return;
//		}
//
//		// Note: 輿檣奢 檜翕
//		if (CurTime - g_sSnake.OldTime > g_sSnake.MoveTime)
//		{
//			g_sSnake.OldTime = CurTime;
//			switch (g_sSnake.nDirect)
//			{
//			case LEFT:
//				if (g_sSnake.sHead.nX - 1 >= 0)
//				{
//					// 醱給 羹觼 
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] == 0) // 綰楣婁 醱給 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] == 1) // 詳檜蒂 詳擎 唳辦陛 脹棻.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX - 1] = -1; // 詳檜朝 奢寥戲煎 籀葬
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX - 1, g_sSnake.sHead.nY))// 瞳議葛攪諦 醱給и 唳辦
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // 窒葬陛 氈朝 匙檜棻.
//						Move();
//
//					g_sSnake.sHead.nX--;
//				}
//				break;
//
//			case RIGHT:
//				if (g_sSnake.sHead.nX + 1 < MAP_COL)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] == 0) // 綰楣婁 醱給 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] == 1) // 詳檜蒂 詳擎 唳辦陛 脹棻.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX + 1] = -1; // 奢寥戲煎 籀葬
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX + 1, g_sSnake.sHead.nY))// 瞳議葛攪諦 醱給и 唳辦
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // 窒葬陛 氈朝 匙檜棻.
//						Move();
//
//					g_sSnake.sHead.nX++;
//				}
//				break;
//
//			case UP:
//				if (g_sSnake.sHead.nY - 1 >= 0)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] == 0) // 綰楣婁 醱給 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] == 1) // 詳檜蒂 詳擎 唳辦陛 脹棻.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY - 1][g_sSnake.sHead.nX] = -1; // 奢寥戲煎 籀葬
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX, g_sSnake.sHead.nY - 1))// 瞳議葛攪諦 醱給и 唳辦
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // 窒葬陛 氈朝 匙檜棻.
//						Move();
//					g_sSnake.sHead.nY--;
//				}
//				break;
//
//			case DOWN:
//				if (g_sSnake.sHead.nY + 1 < MAP_ROW)
//				{
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] == 0) // 綰楣婁 醱給 
//						break;
//
//					if (g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] == 1) // 詳檜蒂 詳擎 唳辦陛 脹棻.
//					{
//						g_sSnake.nLife++;
//						g_StageInfo.nMap[g_sSnake.sHead.nY + 1][g_sSnake.sHead.nX] = -1; // 奢寥戲煎 籀葬
//						g_nEatCount++;
//						g_nGrade += 10;
//					}
//
//					if (IsCollision(g_sSnake.sHead.nX, g_sSnake.sHead.nY + 1))// 瞳議葛攪諦 醱給и 唳辦
//					{
//						g_sSnake.nLife--;
//						if (g_sSnake.nLife < 1)
//						{
//							g_nGameState = STOP;
//							return;
//						}
//					}
//
//					if (g_sSnake.nLife > 1) // 窒葬陛 氈朝 匙檜棻.
//						Move();
//					g_sSnake.sHead.nY++;
//				}
//				break;
//			}
//		}
//
//		// 瞳 議葛攪 檜翕
//		for (i = 0; i < g_StageInfo.nEnemyCount; i++)
//		{
//			if (g_pEnemy[i].nLife == 1)
//			{
//				// 瞳 議葛攪曖 寞щ 瞪�秣� 檜翕縑 婦и匙
//				if (CurTime - g_pEnemy[i].OldTime > g_pEnemy[i].MoveTime)
//				{
//					g_pEnemy[i].OldTime = CurTime;
//
//					switch (g_pEnemy[i].nDirect)
//					{
//					case LEFT:
//						if (g_pEnemy[i].nX - 1 >= 0)
//						{
//							// 漁縑 睡詠�� 唳辦
//							if (g_StageInfo.nMap[g_pEnemy[i].nY][g_pEnemy[i].nX - 1] == 0)
//							{
//								// 寞щ 瞪�素� 嬪и 楠渾 睡碟
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != LEFT)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // 億煎遴 寞щ擊 薯衛и棻
//							}
//							else {
//								g_pEnemy[i].nX--;
//							}
//						}
//						break;
//					case RIGHT:
//						if (g_pEnemy[i].nX + 1 < MAP_COL)
//						{
//							// 漁縑 睡詠�� 唳辦
//							if (g_StageInfo.nMap[g_pEnemy[i].nY][g_pEnemy[i].nX + 1] == 0)
//							{
//								// 寞щ 瞪�素� 嬪и 楠渾 睡碟
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != RIGHT)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // 億煎遴 寞щ擊 薯衛и棻
//							}
//							else {
//								g_pEnemy[i].nX++;
//							}
//						}
//						break;
//					case UP:
//						if (g_pEnemy[i].nY - 1 >= 0)
//						{
//							// 漁縑 睡詠�� 唳辦
//							if (g_StageInfo.nMap[g_pEnemy[i].nY - 1][g_pEnemy[i].nX] == 0)
//							{
//								// 寞щ 瞪�素� 嬪и 楠渾 睡碟
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != UP)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // 億煎遴 寞щ擊 薯衛и棻
//							}
//							else {
//								g_pEnemy[i].nY--;
//							}
//						}
//						break;
//					case DOWN:
//						// 漁縑 睡詠�� 唳辦
//						if (g_pEnemy[i].nY + 1 < MAP_ROW)
//						{
//
//							if (g_StageInfo.nMap[g_pEnemy[i].nY + 1][g_pEnemy[i].nX] == 0)
//							{
//								// 寞щ 瞪�素� 嬪и 楠渾 睡碟
//								srand((unsigned int)time(NULL));
//								while (1)
//								{
//									nDirect = static_cast<DIRECT>(rand() % LAST);
//									if (nDirect != DOWN)
//										break;
//								}
//								g_pEnemy[i].nDirect = nDirect; // 億煎遴 寞щ擊 薯衛и棻
//							}
//							else {
//								g_pEnemy[i].nY++;
//							}
//						}
//						break;
//					}
//				}
//
//				// 寢 該葬諦 瞳 議葛攪曖 醱給
//				if (g_sSnake.sHead.nX == g_pEnemy[i].nX && g_sSnake.sHead.nY == g_pEnemy[i].nY)
//				{
//					g_pEnemy[i].nLife = 0;
//					g_sSnake.nLife--;
//
//					if (g_sSnake.nLife < 1) // 該葬陛 避戲賊 啪歜擊 謙猿и棻.
//					{
//						g_nGameState = STOP;
//						return;
//					}
//				}
//
//				// 寢 窒葬諦 瞳 議葛攪曖 醱給
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
//		//// 撩奢檜傍 褒ぬ蒂 っ欽п輿橫憮 轎溘擊 п輿朝 睡碟檜 諦撿 и棻.  
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
//	static int nMap[MAP_ROW][MAP_COL]; // 轎溘辨
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
//		//轎溘辨 裘縑 犒餌 
//		memcpy(nMap, g_StageInfo.nMap, sizeof(int)*MAP_ROW*MAP_COL);
//
//		//// 瞳 議葛攪 斜葬晦
//		for (i = 0; i < g_StageInfo.nEnemyCount; i++)
//		{
//			if (g_pEnemy[i].nLife == 1)
//			{
//				nMap[g_pEnemy[i].nY][g_pEnemy[i].nX] = 2;
//			}
//		}
//
//		// 輿檣奢 該葬
//		nMap[g_sSnake.sHead.nY][g_sSnake.sHead.nX] = 3;
//
//		// 窒葬
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
//		// Note: 蝶纔檜雖 薑爾 轎溘
//		sprintf(string, "%d Stage", g_nStage + 1);
//		ScreenPrint(61, 5, string);
//		sprintf(string, "陴擎衛除: %d碟 %d蟾", g_RemainTime / 60, g_RemainTime % 60);
//		ScreenPrint(61, 7, string);
//		sprintf(string, "詳檜熱: %d", g_nEatCount);
//		ScreenPrint(61, 9, string);
//		sprintf(string, "菜薄: %d", g_nGrade);
//		ScreenPrint(61, 11, string);
//		break;
//	case SUCCESS:
//		SuccessScreen();
//		sprintf(string, "%d", g_nStage + 1);
//		ScreenPrint(19, 7, string);
//		sprintf(string, "識薄: %d", g_nTotalGrade);
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
//					g_UpdateOldTime = clock();  // ready蒂 橾薑衛除 雖樓п 輿晦 嬪п 							
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