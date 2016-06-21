#include "Screen.h"

Screen::Screen()
{
	nScreenIndex = 0;
}

Screen::~Screen()
{
	CloseHandle(hScreen[0]);
	CloseHandle(hScreen[1]);
}

void Screen::screenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(hScreen[0], &cci);
	SetConsoleCursorInfo(hScreen[1], &cci);
}

void Screen::screenFlipping()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(hScreen[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}

void Screen::screenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(hScreen[nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void Screen::screenPrint(const SHORT &_x, const SHORT &_y, const char *_string)
{
	DWORD dw;
	LPDWORD pdw = &dw;
	COORD CursorPosition = { _x, _y };

	SetConsoleCursorPosition(hScreen[nScreenIndex], CursorPosition);
	WriteFile(hScreen[nScreenIndex], _string, strlen(_string), pdw, NULL);
}

// 1 ~ 15 까지 색상 설정 가능
void Screen::setColor(const unsigned short &_color)
{
	SetConsoleTextAttribute(hScreen[nScreenIndex], _color);
}