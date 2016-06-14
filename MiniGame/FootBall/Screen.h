#pragma once
#include <windows.h>

enum COLOR : char  //데이터의 범위를 정하여 바이트를 절약할수있다.
{
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 9 : 보라 */
	YELLOW,      /* 10 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

class Screen
{
private:
	explicit Screen();
	virtual  ~Screen();

public:
	static Screen* GetInstance()
	{
		static Screen ins;
		return &ins;
	}
	Screen(const Screen&) = delete;
	Screen& operator = (const Screen&) = delete;

public:
	void screenInit();
	void screenFlipping();
	void screenClear();
	void screenPrint(const SHORT &_x, const SHORT &_y, const char *_string);
	void setColor(const unsigned short &_color);

private:
	int nScreenIndex;
	HANDLE hScreen[2];

};
