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
//	// 陛鼻曖 夔樂璽 2偃瑙 虜萇棻.
//	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	// 醴憮 獗晦晦
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
//// 1 ~ 15 梱雖 儀鼻 撲薑 陛棟
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
//	int nIsReady;        // 遽綠 鼻鷓(1), 螂鼻鷓(0)
//	int nMoveX, nMoveY;  // 檜翕 謝ル
//	clock_t MoveTime;    // 檜翕 衛除 除問
//	clock_t OldTime;     // 檜瞪 檜翕 衛陝
//} BALL;
//
//typedef struct _GOAL_DAE
//{
//	int nMoveX, nMoveY;     // 檜翕 謝ル 
//	int nLength;			// 埤渠 望檜	
//	int nLineX[7];			// 埤檣 塭檣 x 謝ル (7偃)
//	clock_t	MoveTime;		// 檜翕 衛除 除問
//	clock_t	OldTime;	    // 檜瞪 檜翕 衛除
//	int	nDist;				// 檜翕 剪葬
//} GOAL_DAE;
//
//typedef struct _EFFECT
//{
//	clock_t StratTime; // �膩� 嫦儅 衛陝
//	clock_t StayTime;  // �膩� 雖樓 衛除	
//} EFFECT;
//
//typedef struct _STAGE_INFO
//{
//	int nGoalBall;			// 埤檣п撿 й 獐曖 偃熱 
//	clock_t LimitTime;      // 薯и 衛除 
//	int nGoalDaeLength;		// 埤渠 望檜 
//	int nGoalDaeX;			// 埤渠 檜翕 X 謝ル
//	int nGoalDaeY;			// 埤渠 檜翕 Y 謝ル 
//	clock_t MoveTime;		// 埤渠 檜翕 衛除 除問
//	int nDist;				// 埤渠 檜翕 剪葬
//} STAGE_INFO;
//
//GOAL_DAE g_sGoalDae;
//BALL g_sBall;
//PLAYER g_sPlayer;
//EFFECT g_sEffect;
//
//char g_strPlayer[] = "曲收≒收旭";
//STAGE_INFO g_sStageInfo[] = { { 3, 1000 * 20, 1, 20, 3, 300, 1 },{ 10, 1000 * 30, 2, 20, 5, 300, 1 } };
//int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
//clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;
//
//GAME_STATE g_GameState = INIT;
//
//void InitScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                          早");
//	ScreenPrint(0, 2, "早             ﹤收收收﹤                   早");
//	ScreenPrint(0, 3, "早                                          早");
//	ScreenPrint(0, 4, "早                        ///.   螂~~~      早");
//	ScreenPrint(0, 5, "早                       (^.^)              早");
//	ScreenPrint(0, 6, "早                      曲朽 曳旬           早");
//	ScreenPrint(0, 7, "早                         旨旭             早");
//	ScreenPrint(0, 8, "早                     Ⅸ  旭′             早");
//	ScreenPrint(0, 9, "早                                          早");
//	ScreenPrint(0, 10, "早                                          早");
//	ScreenPrint(0, 11, "早       螂 埤檣 啪歜  Go! Go!              早");
//	ScreenPrint(0, 12, "早                                          早");
//	ScreenPrint(0, 13, "早                                          早");
//	ScreenPrint(0, 14, "早       j :豭薹 l : 螃艇薹 k :螂           早");
//	ScreenPrint(0, 15, "早                                          早");
//	ScreenPrint(0, 16, "早                                          早");
//	ScreenPrint(0, 17, "早                                          早");
//	ScreenPrint(0, 18, "早        曲≒旭  space 酈蒂 揚楝輿撮蹂     早");
//	ScreenPrint(0, 19, "早                                          早");
//	ScreenPrint(0, 20, "早                                          早");
//	ScreenPrint(0, 21, "早                                          早");
//	ScreenPrint(0, 22, "曲收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void ReadyScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 2, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 3, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 4, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 5, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 6, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 7, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 8, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 9, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 10, "早﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥早");
//	sprintf_s(string, "早﹥﹥﹥﹥﹥     %d   蝶纔檜雖   ﹥﹥﹥﹥﹥﹥早", g_nStage + 1);
//	ScreenPrint(0, 11, string);
//	ScreenPrint(0, 12, "早﹥﹥﹥﹥﹥                    ﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 13, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 14, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 15, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 16, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 17, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 18, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 19, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 20, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 21, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 22, "早﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void BackScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                          早");
//	ScreenPrint(0, 2, "早                                          早");
//	ScreenPrint(0, 3, "早                                          早");
//	sprintf_s(string, "早                                          早蝶纔檜雖: %d", g_nStage + 1);
//	ScreenPrint(0, 4, string);
//	ScreenPrint(0, 5, "早                                          早");
//	sprintf_s(string, "曳收收收收收收收收收收收收收收收收收收收收收朽薯и 衛除: %d", g_sStageInfo[g_nStage].LimitTime / 1000);
//	ScreenPrint(0, 6, string);
//	ScreenPrint(0, 7, "早                                          早");
//	sprintf_s(string, "早                                          早⑷營 衛除: %d", (clock() - g_GameStartTime) / 1000);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "早                                          早");
//	sprintf_s(string, "早                                          早跡ル 埤檣: %d ", g_sStageInfo[g_nStage].nGoalBall);
//	ScreenPrint(0, 10, string);
//	ScreenPrint(0, 11, "早                                          早");
//	sprintf_s(string, "早                                          早埤檣 奢 偃熱: %d ", g_nBallCount);
//	ScreenPrint(0, 12, string);
//
//	ScreenPrint(0, 13, "早                                          早");
//	sprintf_s(string, "早                                          早");
//	ScreenPrint(0, 14, string);
//	ScreenPrint(0, 15, "早                                          早");
//	sprintf_s(string, "早                                          早");
//	ScreenPrint(0, 16, string);
//	ScreenPrint(0, 17, "早                                          早");
//	ScreenPrint(0, 18, "早                                          早");
//	ScreenPrint(0, 19, "早                                          早");
//	ScreenPrint(0, 20, "早                                          早");
//	ScreenPrint(0, 21, "早                                          早");
//	ScreenPrint(0, 22, "早                                          早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void GoalMessage(int nX, int nY)
//{
//	ScreenPrint(nX, nY, "≧ )) 埤檣 (( ≠");
//	ScreenPrint(nX, nY + 1, "′(^^')/ ′(\"*')/");
//	ScreenPrint(nX, nY + 2, "   ﹥       ﹥");
//	ScreenPrint(nX, nY + 3, "  戎忖    忙戌");
//}
//
//void SuccessScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                          早");
//	ScreenPrint(0, 2, "早                                          早");
//	ScreenPrint(0, 3, "早                                          早");
//	ScreenPrint(0, 4, "早                                          早");
//	ScreenPrint(0, 5, "早                                          早");
//	ScreenPrint(0, 6, "早                ////′′                  早");
//	ScreenPrint(0, 7, "早               q ∥  ∥ p                 早");
//	ScreenPrint(0, 8, "早               (戌式式戎)                 早");
//	ScreenPrint(0, 9, "早             Ｏ 嘐暮 撩奢 Ｎ              早");
//	ScreenPrint(0, 10, "早                                          早");
//	ScreenPrint(0, 11, "早                                          早");
//	ScreenPrint(0, 12, "早                                          早");
//	ScreenPrint(0, 13, "早                                          早");
//	ScreenPrint(0, 14, "早                                          早");
//	ScreenPrint(0, 15, "早                                          早");
//	ScreenPrint(0, 16, "早                                          早");
//	ScreenPrint(0, 17, "早                                          早");
//	ScreenPrint(0, 18, "早                                          早");
//	ScreenPrint(0, 19, "早                                          早");
//	ScreenPrint(0, 20, "早                                          早");
//	ScreenPrint(0, 21, "早                                          早");
//	ScreenPrint(0, 22, "早                                          早");
//	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void FailureScreen()
//{
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                          早");
//	ScreenPrint(0, 2, "早                                          早");
//	ScreenPrint(0, 3, "早                                          早");
//	ScreenPrint(0, 4, "早                                          早");
//	ScreenPrint(0, 5, "早                                          早");
//	ScreenPrint(0, 6, "早                                          早");
//	ScreenPrint(0, 7, "早                                          早");
//	ScreenPrint(0, 8, "早                                          早");
//	ScreenPrint(0, 9, "早                                          早");
//	ScreenPrint(0, 10, "早                                          早");
//	ScreenPrint(0, 11, "早                    嘐暮 褒ぬ !!!!        早");
//	ScreenPrint(0, 12, "早                                          早");
//	ScreenPrint(0, 13, "早                                          早");
//	ScreenPrint(0, 14, "早                 ≒有收旬                 早");
//	ScreenPrint(0, 15, "早                   旭  曲                 早");
//	ScreenPrint(0, 16, "早                  ﹥﹥﹥﹥                早");
//	ScreenPrint(0, 17, "早                                          早");
//	ScreenPrint(0, 18, "早        棻衛 ж衛啊蝗棲梱? (y/n)          早");
//	ScreenPrint(0, 19, "早                                          早");
//	ScreenPrint(0, 20, "早                                          早");
//	ScreenPrint(0, 21, "早                                          早");
//	ScreenPrint(0, 22, "曲收收收收收收收收收收收收收收收收收收收收收旭");
//}
//
//void ResultScreen()
//{
//	char string[100];
//	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收收旬");
//	ScreenPrint(0, 1, "早                                          早");
//	ScreenPrint(0, 2, "早                                          早");
//	ScreenPrint(0, 3, "早             ﹤收收收﹤                   早");
//	ScreenPrint(0, 4, "早                                          早");
//	ScreenPrint(0, 5, "早                                          早");
//	ScreenPrint(0, 6, "早                                          早");
//	ScreenPrint(0, 7, "早                                          早");
//	sprintf_s(string, "早      撩奢и 蝶纔檜雖 :  %2d               早", g_nStage + 1);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "早                                          早");
//	ScreenPrint(0, 10, "早                                          早");
//	ScreenPrint(0, 11, "早   ___〤〤〤___                           早");
//	ScreenPrint(0, 12, "早     (*^  ^*)                             早");
//	ScreenPrint(0, 13, "早 =====∞==∞=====                         早");
//	ScreenPrint(0, 14, "早                                          早");
//	ScreenPrint(0, 15, "早                                          早");
//	ScreenPrint(0, 16, "早                                          早");
//	ScreenPrint(0, 17, "早                                          早");
//	ScreenPrint(0, 18, "早                      曲≒旭              早");
//	ScreenPrint(0, 19, "早                                          早");
//	ScreenPrint(0, 20, "早                                          早");
//	ScreenPrint(0, 21, "早                                          早");
//	ScreenPrint(0, 22, "曲收收收收收收收收收收收收收收收收收收收收收旭");
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
//	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;  // 薯и 衛除 撲薑
//	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall; // 跡ル 埤檣 偃熱
//
//	g_sPlayer.nCenterX = 4;
//	g_sPlayer.nCenterY = 0;
//	g_sPlayer.nMoveX = 20;
//	g_sPlayer.nMoveY = 22;
//	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//	g_nLength = strlen(g_strPlayer);
//
//	// 奢曖 蟾晦��
//	g_sBall.nIsReady = 1;
//	g_sBall.nMoveX = g_sPlayer.nMoveX;
//	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//	g_sBall.MoveTime = 100;
//
//	// 埤渠 蟾晦��
//	g_sGoalDae.nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;
//	g_sGoalDae.nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
//	g_sGoalDae.nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
//	g_sGoalDae.MoveTime = g_sStageInfo[g_nStage].MoveTime;
//	g_sGoalDae.OldTime = clock();
//	g_sGoalDae.nDist = g_sStageInfo[g_nStage].nDist;
//	nLength = g_sGoalDae.nLength * 2 + 1; // Note: 寡翮曖 譆渠 望檜
//
//	for (int i = 0; i < nLength; i++)
//	{
//		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
//	}
//
//	// �膩� 
//	g_sEffect.StayTime = 2000; // 2蟾 撲薑
//	g_nGoal = 0;      // 蝶纔檜雖 諫猿 滲熱
//	g_UpdateOldTime = clock();
//	g_nBallCount = 0;  // 埤檣и 奢曖 偃熱
//}
//
//void Update()
//{
//	clock_t CurTime = clock();
//	int nLength = g_sGoalDae.nLength * 2 + 1; // Note: 寡翮曖 譆渠 望檜
//
//	switch (g_GameState)
//	{
//	case READY:
//		if (CurTime - g_UpdateOldTime > 2000)  // 2蟾
//		{
//			g_GameState = RUNNING;
//			g_GameStartTime = CurTime;
//		}
//		break;
//	case RUNNING:
//		if (CurTime - g_GameStartTime > g_LimitTime) // Note: 薯и 衛除
//		{
//			g_GameState = STOP;
//			return;
//		}
//		else {
//			// Note: 埤渠
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
//					g_sGoalDae.nDist = g_sGoalDae.nDist * -1; // -1 檜 寞щ擊 夥紱橫 邀.
//				}
//			}
//
//			if (g_sBall.nIsReady == 0) // 檜翕 醞橾 陽 
//			{	// 檜翕 衛除 除問縑 曖и 檜翕
//				if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime)
//				{
//					if (g_sBall.nMoveY - 1 > 0)
//					{
//						g_sBall.nMoveY--;
//						g_sBall.OldTime = CurTime; // 棻擠 檜翕 衛陝婁 綠掖ж晦 嬪п ⑷營 衛除擊 檜瞪 衛除 滲熱縑 盪濰
//						// 埤渠 塭檣 醱給
//						if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // 奢 蟾晦��
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//								g_nBallCount++;  // 埤檣и 奢曖 偃熱										
//
//								if (g_nBallCount == g_nGoalBallCount) // 奢婁 跡ル 奢婁曖 偃熱陛 偽戲賊 SUCCESS g_nGoal = 1
//								{
//									g_GameState = STOP;
//									g_nGoal = 1;
//									return;
//								}
//
//								// �膩� 轎溘
//								if (g_nIsGoal == 0)
//								{
//									g_nIsGoal = 1;
//									g_sEffect.StratTime = CurTime;
//								}
//							}
//							// 埤渠 醱給 
//						}
//						else if ((g_sBall.nMoveX >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength - 1] + 3) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 3))
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // 奢 蟾晦��
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//							}
//						}
//					}
//					else { // 奢 蟾晦��
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
//			// �膩� 
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
//		ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "﹤");
//		nLength = g_sGoalDae.nLength * 2 + 1;
//
//		for (int i = 0; i < nLength; i++)
//			ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "收");
//
//		ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.nMoveY, "﹤");
//
//		// Note: �膩� 轎溘  	
//		if (g_nIsGoal == 1)
//		{
//			GoalMessage(10, 10);
//		}
//
//		// Note: 2 鏽歲噶 贗葬ё 
//		if (g_sPlayer.nX < 2)  //  豭薹 贗葬ё 籀葬
//			ScreenPrint(2, g_sPlayer.nMoveY, &g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // 謝ル蒂 寡翮 檣策蝶 
//		else if (g_sPlayer.nMoveX + (g_nLength - g_sPlayer.nCenterX + 1) > 43) // 螃艇薹 贗葬ё 籀葬
//		{
//			strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 43));
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
//		}
//		else { // 1 鏽歲噶 檜翕
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer);
//		}
//
//		ScreenPrint(g_sBall.nMoveX, g_sBall.nMoveY, "Ⅸ");
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
//	// Note: 溶渦葭 部 
//	ScreenFlipping();
//}
//
//int main(void)
//{
//	int nKey, nRemain;
//
//	ScreenInit();
//	Init();        // 蟾晦��
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
//				if (g_sPlayer.nMoveX > 2) // 豭薹 醱給 唳啗 謝ル 羹觼
//				{
//					g_sPlayer.nMoveX--;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // 瞪羹 望檜 - ( 醞褕 謝ル + 1 )擎 陴擎 望檜
//																  // Note: 2鏽歲噶 檜翕ж晦 嬪и 睡碟 ( つ檜 勘耀 唳辦 ) 
//					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
//						g_sPlayer.nMoveX--;
//
//					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//				}
//				break;
//			case 'l':
//				if (g_sPlayer.nMoveX + 1 < 43) // 螃艇薹 醱給 唳啗 謝ル 羹觼
//				{
//					g_sPlayer.nMoveX++;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // 瞪羹 望檜 - ( 醞褕 謝ル + 1 )擎 陴擎 望檜
//																  // Note: 2鏽歲噶 檜翕ж晦 嬪и 睡碟 ( つ檜 勘耀 唳辦 )
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
//					g_UpdateOldTime = clock();  // ready蒂 橾薑衛除 雖樓п 輿晦 嬪п 							
//				}
//				break;
//			}
//		}
//
//
//
//		Update();    // 等檜攪 偵褐
//		Render();    // �飛� 轎溘
//	}
//	ScreenRelease();
//	return 0;
//}
