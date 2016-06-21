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
//	// °¡»óÀÇ ÄÜ¼ÖÃ¢ 2°³·ê ¸¸µç´Ù.
//	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	// Ä¿¼­ ¼û±â±â
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
//// 1 ~ 15 ±îÁö »ö»ó ¼³Á¤ °¡´É
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
//	int nIsReady;        // ÁØºñ »óÅÂ(1), ½¸»óÅÂ(0)
//	int nMoveX, nMoveY;  // ÀÌµ¿ ÁÂÇ¥
//	clock_t MoveTime;    // ÀÌµ¿ ½Ã°£ °£°Ý
//	clock_t OldTime;     // ÀÌÀü ÀÌµ¿ ½Ã°¢
//} BALL;
//
//typedef struct _GOAL_DAE
//{
//	int nMoveX, nMoveY;     // ÀÌµ¿ ÁÂÇ¥ 
//	int nLength;			// °ñ´ë ±æÀÌ	
//	int nLineX[7];			// °ñÀÎ ¶óÀÎ x ÁÂÇ¥ (7°³)
//	clock_t	MoveTime;		// ÀÌµ¿ ½Ã°£ °£°Ý
//	clock_t	OldTime;	    // ÀÌÀü ÀÌµ¿ ½Ã°£
//	int	nDist;				// ÀÌµ¿ °Å¸®
//} GOAL_DAE;
//
//typedef struct _EFFECT
//{
//	clock_t StratTime; // È¿°ú ¹ß»ý ½Ã°¢
//	clock_t StayTime;  // È¿°ú Áö¼Ó ½Ã°£	
//} EFFECT;
//
//typedef struct _STAGE_INFO
//{
//	int nGoalBall;			// °ñÀÎÇØ¾ß ÇÒ º¼ÀÇ °³¼ö 
//	clock_t LimitTime;      // Á¦ÇÑ ½Ã°£ 
//	int nGoalDaeLength;		// °ñ´ë ±æÀÌ 
//	int nGoalDaeX;			// °ñ´ë ÀÌµ¿ X ÁÂÇ¥
//	int nGoalDaeY;			// °ñ´ë ÀÌµ¿ Y ÁÂÇ¥ 
//	clock_t MoveTime;		// °ñ´ë ÀÌµ¿ ½Ã°£ °£°Ý
//	int nDist;				// °ñ´ë ÀÌµ¿ °Å¸®
//} STAGE_INFO;
//
//GOAL_DAE g_sGoalDae;
//BALL g_sBall;
//PLAYER g_sPlayer;
//EFFECT g_sEffect;
//
//char g_strPlayer[] = "¦±¦¬¡Ü¦¬¦°";
//STAGE_INFO g_sStageInfo[] = { { 3, 1000 * 20, 1, 20, 3, 300, 1 },{ 10, 1000 * 30, 2, 20, 5, 300, 1 } };
//int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
//clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;
//
//GAME_STATE g_GameState = INIT;
//
//void InitScreen()
//{
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­                                          ¦­");
//	ScreenPrint(0, 2, "¦­             ¡à¦¬¦¬¦¬¡à                   ¦­");
//	ScreenPrint(0, 3, "¦­                                          ¦­");
//	ScreenPrint(0, 4, "¦­                        ///.   ½¸~~~      ¦­");
//	ScreenPrint(0, 5, "¦­                       (^.^)              ¦­");
//	ScreenPrint(0, 6, "¦­                      ¦±¦´ ¦²¦¯           ¦­");
//	ScreenPrint(0, 7, "¦­                         ¦®¦°             ¦­");
//	ScreenPrint(0, 8, "¦­                     ¢Á  ¦°¡¬             ¦­");
//	ScreenPrint(0, 9, "¦­                                          ¦­");
//	ScreenPrint(0, 10, "¦­                                          ¦­");
//	ScreenPrint(0, 11, "¦­       ½¸ °ñÀÎ °ÔÀÓ  Go! Go!              ¦­");
//	ScreenPrint(0, 12, "¦­                                          ¦­");
//	ScreenPrint(0, 13, "¦­                                          ¦­");
//	ScreenPrint(0, 14, "¦­       j :¿ÞÂÊ l : ¿À¸¥ÂÊ k :½¸           ¦­");
//	ScreenPrint(0, 15, "¦­                                          ¦­");
//	ScreenPrint(0, 16, "¦­                                          ¦­");
//	ScreenPrint(0, 17, "¦­                                          ¦­");
//	ScreenPrint(0, 18, "¦­        ¦±¡Ü¦°  space Å°¸¦ ´­·¯ÁÖ¼¼¿ä     ¦­");
//	ScreenPrint(0, 19, "¦­                                          ¦­");
//	ScreenPrint(0, 20, "¦­                                          ¦­");
//	ScreenPrint(0, 21, "¦­                                          ¦­");
//	ScreenPrint(0, 22, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
//}
//
//void ReadyScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 2, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 3, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 4, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 5, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 6, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 7, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 8, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 9, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 10, "¦­¡á¡á¡á¡á¡á                    ¡á¡á¡á¡á¡á¡á¦­");
//	sprintf_s(string, "¦­¡á¡á¡á¡á¡á     %d   ½ºÅ×ÀÌÁö   ¡á¡á¡á¡á¡á¡á¦­", g_nStage + 1);
//	ScreenPrint(0, 11, string);
//	ScreenPrint(0, 12, "¦­¡á¡á¡á¡á¡á                    ¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 13, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 14, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 15, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 16, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 17, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 18, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 19, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 20, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 21, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 22, "¦­¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¦­");
//	ScreenPrint(0, 23, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
//}
//
//void BackScreen()
//{
//	char string[100];
//
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­                                          ¦­");
//	ScreenPrint(0, 2, "¦­                                          ¦­");
//	ScreenPrint(0, 3, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­½ºÅ×ÀÌÁö: %d", g_nStage + 1);
//	ScreenPrint(0, 4, string);
//	ScreenPrint(0, 5, "¦­                                          ¦­");
//	sprintf_s(string, "¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´Á¦ÇÑ ½Ã°£: %d", g_sStageInfo[g_nStage].LimitTime / 1000);
//	ScreenPrint(0, 6, string);
//	ScreenPrint(0, 7, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­ÇöÀç ½Ã°£: %d", (clock() - g_GameStartTime) / 1000);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­¸ñÇ¥ °ñÀÎ: %d ", g_sStageInfo[g_nStage].nGoalBall);
//	ScreenPrint(0, 10, string);
//	ScreenPrint(0, 11, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­°ñÀÎ °ø °³¼ö: %d ", g_nBallCount);
//	ScreenPrint(0, 12, string);
//
//	ScreenPrint(0, 13, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­");
//	ScreenPrint(0, 14, string);
//	ScreenPrint(0, 15, "¦­                                          ¦­");
//	sprintf_s(string, "¦­                                          ¦­");
//	ScreenPrint(0, 16, string);
//	ScreenPrint(0, 17, "¦­                                          ¦­");
//	ScreenPrint(0, 18, "¦­                                          ¦­");
//	ScreenPrint(0, 19, "¦­                                          ¦­");
//	ScreenPrint(0, 20, "¦­                                          ¦­");
//	ScreenPrint(0, 21, "¦­                                          ¦­");
//	ScreenPrint(0, 22, "¦­                                          ¦­");
//	ScreenPrint(0, 23, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
//}
//
//void GoalMessage(int nX, int nY)
//{
//	ScreenPrint(nX, nY, "¡Ù )) °ñÀÎ (( ¡Ú");
//	ScreenPrint(nX, nY + 1, "¡¬(^^')/ ¡¬(\"*')/");
//	ScreenPrint(nX, nY + 2, "   ¡á       ¡á");
//	ScreenPrint(nX, nY + 3, "  ¦¥¦¤    ¦£¦¦");
//}
//
//void SuccessScreen()
//{
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­                                          ¦­");
//	ScreenPrint(0, 2, "¦­                                          ¦­");
//	ScreenPrint(0, 3, "¦­                                          ¦­");
//	ScreenPrint(0, 4, "¦­                                          ¦­");
//	ScreenPrint(0, 5, "¦­                                          ¦­");
//	ScreenPrint(0, 6, "¦­                ////¡¬¡¬                  ¦­");
//	ScreenPrint(0, 7, "¦­               q ¡ü  ¡ü p                 ¦­");
//	ScreenPrint(0, 8, "¦­               (¦¦¦¡¦¡¦¥)                 ¦­");
//	ScreenPrint(0, 9, "¦­             ¢Ý ¹Ì¼Ç ¼º°ø ¢Ü              ¦­");
//	ScreenPrint(0, 10, "¦­                                          ¦­");
//	ScreenPrint(0, 11, "¦­                                          ¦­");
//	ScreenPrint(0, 12, "¦­                                          ¦­");
//	ScreenPrint(0, 13, "¦­                                          ¦­");
//	ScreenPrint(0, 14, "¦­                                          ¦­");
//	ScreenPrint(0, 15, "¦­                                          ¦­");
//	ScreenPrint(0, 16, "¦­                                          ¦­");
//	ScreenPrint(0, 17, "¦­                                          ¦­");
//	ScreenPrint(0, 18, "¦­                                          ¦­");
//	ScreenPrint(0, 19, "¦­                                          ¦­");
//	ScreenPrint(0, 20, "¦­                                          ¦­");
//	ScreenPrint(0, 21, "¦­                                          ¦­");
//	ScreenPrint(0, 22, "¦­                                          ¦­");
//	ScreenPrint(0, 23, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
//}
//
//void FailureScreen()
//{
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­                                          ¦­");
//	ScreenPrint(0, 2, "¦­                                          ¦­");
//	ScreenPrint(0, 3, "¦­                                          ¦­");
//	ScreenPrint(0, 4, "¦­                                          ¦­");
//	ScreenPrint(0, 5, "¦­                                          ¦­");
//	ScreenPrint(0, 6, "¦­                                          ¦­");
//	ScreenPrint(0, 7, "¦­                                          ¦­");
//	ScreenPrint(0, 8, "¦­                                          ¦­");
//	ScreenPrint(0, 9, "¦­                                          ¦­");
//	ScreenPrint(0, 10, "¦­                                          ¦­");
//	ScreenPrint(0, 11, "¦­                    ¹Ì¼Ç ½ÇÆÐ !!!!        ¦­");
//	ScreenPrint(0, 12, "¦­                                          ¦­");
//	ScreenPrint(0, 13, "¦­                                          ¦­");
//	ScreenPrint(0, 14, "¦­                 ¡Ü¦³¦¬¦¯                 ¦­");
//	ScreenPrint(0, 15, "¦­                   ¦°  ¦±                 ¦­");
//	ScreenPrint(0, 16, "¦­                  ¡á¡á¡á¡á                ¦­");
//	ScreenPrint(0, 17, "¦­                                          ¦­");
//	ScreenPrint(0, 18, "¦­        ´Ù½Ã ÇÏ½Ã°Ú½À´Ï±î? (y/n)          ¦­");
//	ScreenPrint(0, 19, "¦­                                          ¦­");
//	ScreenPrint(0, 20, "¦­                                          ¦­");
//	ScreenPrint(0, 21, "¦­                                          ¦­");
//	ScreenPrint(0, 22, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
//}
//
//void ResultScreen()
//{
//	char string[100];
//	ScreenPrint(0, 0, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
//	ScreenPrint(0, 1, "¦­                                          ¦­");
//	ScreenPrint(0, 2, "¦­                                          ¦­");
//	ScreenPrint(0, 3, "¦­             ¡à¦¬¦¬¦¬¡à                   ¦­");
//	ScreenPrint(0, 4, "¦­                                          ¦­");
//	ScreenPrint(0, 5, "¦­                                          ¦­");
//	ScreenPrint(0, 6, "¦­                                          ¦­");
//	ScreenPrint(0, 7, "¦­                                          ¦­");
//	sprintf_s(string, "¦­      ¼º°øÇÑ ½ºÅ×ÀÌÁö :  %2d               ¦­", g_nStage + 1);
//	ScreenPrint(0, 8, string);
//	ScreenPrint(0, 9, "¦­                                          ¦­");
//	ScreenPrint(0, 10, "¦­                                          ¦­");
//	ScreenPrint(0, 11, "¦­   ___¢Æ¢Æ¢Æ___                           ¦­");
//	ScreenPrint(0, 12, "¦­     (*^  ^*)                             ¦­");
//	ScreenPrint(0, 13, "¦­ =====¡Û==¡Û=====                         ¦­");
//	ScreenPrint(0, 14, "¦­                                          ¦­");
//	ScreenPrint(0, 15, "¦­                                          ¦­");
//	ScreenPrint(0, 16, "¦­                                          ¦­");
//	ScreenPrint(0, 17, "¦­                                          ¦­");
//	ScreenPrint(0, 18, "¦­                      ¦±¡Ü¦°              ¦­");
//	ScreenPrint(0, 19, "¦­                                          ¦­");
//	ScreenPrint(0, 20, "¦­                                          ¦­");
//	ScreenPrint(0, 21, "¦­                                          ¦­");
//	ScreenPrint(0, 22, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
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
//	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;  // Á¦ÇÑ ½Ã°£ ¼³Á¤
//	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall; // ¸ñÇ¥ °ñÀÎ °³¼ö
//
//	g_sPlayer.nCenterX = 4;
//	g_sPlayer.nCenterY = 0;
//	g_sPlayer.nMoveX = 20;
//	g_sPlayer.nMoveY = 22;
//	g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//	g_nLength = strlen(g_strPlayer);
//
//	// °øÀÇ ÃÊ±âÈ­
//	g_sBall.nIsReady = 1;
//	g_sBall.nMoveX = g_sPlayer.nMoveX;
//	g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//	g_sBall.MoveTime = 100;
//
//	// °ñ´ë ÃÊ±âÈ­
//	g_sGoalDae.nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;
//	g_sGoalDae.nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
//	g_sGoalDae.nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
//	g_sGoalDae.MoveTime = g_sStageInfo[g_nStage].MoveTime;
//	g_sGoalDae.OldTime = clock();
//	g_sGoalDae.nDist = g_sStageInfo[g_nStage].nDist;
//	nLength = g_sGoalDae.nLength * 2 + 1; // Note: ¹è¿­ÀÇ ÃÖ´ë ±æÀÌ
//
//	for (int i = 0; i < nLength; i++)
//	{
//		g_sGoalDae.nLineX[i] = g_sGoalDae.nMoveX + 2 * (i + 1);
//	}
//
//	// È¿°ú 
//	g_sEffect.StayTime = 2000; // 2ÃÊ ¼³Á¤
//	g_nGoal = 0;      // ½ºÅ×ÀÌÁö ¿Ï·á º¯¼ö
//	g_UpdateOldTime = clock();
//	g_nBallCount = 0;  // °ñÀÎÇÑ °øÀÇ °³¼ö
//}
//
//void Update()
//{
//	clock_t CurTime = clock();
//	int nLength = g_sGoalDae.nLength * 2 + 1; // Note: ¹è¿­ÀÇ ÃÖ´ë ±æÀÌ
//
//	switch (g_GameState)
//	{
//	case READY:
//		if (CurTime - g_UpdateOldTime > 2000)  // 2ÃÊ
//		{
//			g_GameState = RUNNING;
//			g_GameStartTime = CurTime;
//		}
//		break;
//	case RUNNING:
//		if (CurTime - g_GameStartTime > g_LimitTime) // Note: Á¦ÇÑ ½Ã°£
//		{
//			g_GameState = STOP;
//			return;
//		}
//		else {
//			// Note: °ñ´ë
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
//					g_sGoalDae.nDist = g_sGoalDae.nDist * -1; // -1 ÀÌ ¹æÇâÀ» ¹Ù²Ù¾î ÁÜ.
//				}
//			}
//
//			if (g_sBall.nIsReady == 0) // ÀÌµ¿ ÁßÀÏ ¶§ 
//			{	// ÀÌµ¿ ½Ã°£ °£°Ý¿¡ ÀÇÇÑ ÀÌµ¿
//				if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime)
//				{
//					if (g_sBall.nMoveY - 1 > 0)
//					{
//						g_sBall.nMoveY--;
//						g_sBall.OldTime = CurTime; // ´ÙÀ½ ÀÌµ¿ ½Ã°¢°ú ºñ±³ÇÏ±â À§ÇØ ÇöÀç ½Ã°£À» ÀÌÀü ½Ã°£ º¯¼ö¿¡ ÀúÀå
//						// °ñ´ë ¶óÀÎ Ãæµ¹
//						if (g_sBall.nMoveX >= g_sGoalDae.nLineX[0] && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // °ø ÃÊ±âÈ­
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//								g_nBallCount++;  // °ñÀÎÇÑ °øÀÇ °³¼ö										
//
//								if (g_nBallCount == g_nGoalBallCount) // °ø°ú ¸ñÇ¥ °ø°úÀÇ °³¼ö°¡ °°À¸¸é SUCCESS g_nGoal = 1
//								{
//									g_GameState = STOP;
//									g_nGoal = 1;
//									return;
//								}
//
//								// È¿°ú Ãâ·Â
//								if (g_nIsGoal == 0)
//								{
//									g_nIsGoal = 1;
//									g_sEffect.StratTime = CurTime;
//								}
//							}
//							// °ñ´ë Ãæµ¹ 
//						}
//						else if ((g_sBall.nMoveX >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[0] - 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[0] - 1) ||
//							(g_sBall.nMoveX >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX <= g_sGoalDae.nLineX[nLength - 1] + 3) ||
//							(g_sBall.nMoveX + 1 >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.nMoveX + 1 <= g_sGoalDae.nLineX[nLength - 1] + 3))
//						{
//							if (g_sBall.nMoveY <= g_sGoalDae.nMoveY)
//							{   // °ø ÃÊ±âÈ­
//								g_sBall.nIsReady = 1;
//								g_sBall.nMoveX = g_sPlayer.nMoveX;
//								g_sBall.nMoveY = g_sPlayer.nMoveY - 1;
//							}
//						}
//					}
//					else { // °ø ÃÊ±âÈ­
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
//			// È¿°ú 
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
//		ScreenPrint(g_sGoalDae.nMoveX, g_sGoalDae.nMoveY, "¡à");
//		nLength = g_sGoalDae.nLength * 2 + 1;
//
//		for (int i = 0; i < nLength; i++)
//			ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.nMoveY, "¦¬");
//
//		ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.nMoveY, "¡à");
//
//		// Note: È¿°ú Ãâ·Â  	
//		if (g_nIsGoal == 1)
//		{
//			GoalMessage(10, 10);
//		}
//
//		// Note: 2 ÄÃ·³¾¿ Å¬¸®ÇÎ 
//		if (g_sPlayer.nX < 2)  //  ¿ÞÂÊ Å¬¸®ÇÎ Ã³¸®
//			ScreenPrint(2, g_sPlayer.nMoveY, &g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // ÁÂÇ¥¸¦ ¹è¿­ ÀÎµ¦½º 
//		else if (g_sPlayer.nMoveX + (g_nLength - g_sPlayer.nCenterX + 1) > 43) // ¿À¸¥ÂÊ Å¬¸®ÇÎ Ã³¸®
//		{
//			strncat(string, g_strPlayer, g_nLength - ((g_sPlayer.nMoveX + g_sPlayer.nCenterX + 1) - 43));
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, string);
//		}
//		else { // 1 ÄÃ·³¾¿ ÀÌµ¿
//			ScreenPrint(g_sPlayer.nX, g_sPlayer.nMoveY, g_strPlayer);
//		}
//
//		ScreenPrint(g_sBall.nMoveX, g_sBall.nMoveY, "¢Á");
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
//	// Note: ·»´õ¸µ ³¡ 
//	ScreenFlipping();
//}
//
//int main(void)
//{
//	int nKey, nRemain;
//
//	ScreenInit();
//	Init();        // ÃÊ±âÈ­
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
//				if (g_sPlayer.nMoveX > 2) // ¿ÞÂÊ Ãæµ¹ °æ°è ÁÂÇ¥ Ã¼Å©
//				{
//					g_sPlayer.nMoveX--;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // ÀüÃ¼ ±æÀÌ - ( Áß½É ÁÂÇ¥ + 1 )Àº ³²Àº ±æÀÌ
//																  // Note: 2ÄÃ·³¾¿ ÀÌµ¿ÇÏ±â À§ÇÑ ºÎºÐ ( ÆÈÀÌ °ÉÄ£ °æ¿ì ) 
//					if (g_sPlayer.nMoveX - g_sPlayer.nCenterX < 2 || g_sPlayer.nMoveX + nRemain > 43)
//						g_sPlayer.nMoveX--;
//
//					g_sPlayer.nX = g_sPlayer.nMoveX - g_sPlayer.nCenterX;
//				}
//				break;
//			case 'l':
//				if (g_sPlayer.nMoveX + 1 < 43) // ¿À¸¥ÂÊ Ãæµ¹ °æ°è ÁÂÇ¥ Ã¼Å©
//				{
//					g_sPlayer.nMoveX++;
//					nRemain = g_nLength - g_sPlayer.nCenterX + 1; // ÀüÃ¼ ±æÀÌ - ( Áß½É ÁÂÇ¥ + 1 )Àº ³²Àº ±æÀÌ
//																  // Note: 2ÄÃ·³¾¿ ÀÌµ¿ÇÏ±â À§ÇÑ ºÎºÐ ( ÆÈÀÌ °ÉÄ£ °æ¿ì )
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
//					g_UpdateOldTime = clock();  // ready¸¦ ÀÏÁ¤½Ã°£ Áö¼ÓÇØ ÁÖ±â À§ÇØ 							
//				}
//				break;
//			}
//		}
//
//
//
//		Update();    // µ¥ÀÌÅÍ °»½Å
//		Render();    // È­¸é Ãâ·Â
//	}
//	ScreenRelease();
//	return 0;
//}
