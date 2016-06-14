#pragma once
#include <windows.h>

enum COLOR : char  //�������� ������ ���Ͽ� ����Ʈ�� �����Ҽ��ִ�.
{
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 9 : ���� */
	YELLOW,      /* 10 : ��� */
	WHITE,      /* 15 : �Ͼ� */
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
