#pragma once
#include <iostream>
#include <conio.h>

using std::cin;

template <class T> class Player final
{
public:
	explicit Player() : _keytemp(NULL) { ; }
	virtual ~Player() = default;
	explicit Player(const Player&) = delete;
	Player& operator = (const Player&) = delete;

public:
	const T& keyInput()
	{
		cin >> _keytemp;
		if (!cin.fail()) //cin오류시 1을 반환한다. ex) int 변수에 cin으로 *char이 들어간경우
		{
			return _keytemp;
		}
		cin.clear(); //cin 객체의 "내부 상태 플래그"를 초기화시켜서 cin 관련 기능을 정상작동하도록함
		cin.ignore(100, '\n'); //입력 버퍼에 있는 모든 내용을 추출해서 버림
		return 0;
	}
	const T& getKey() const { return _keytemp; }
	const T& getch() { _keytemp = _getch(); return _keytemp; }

private:
	T _keytemp;

};

template <> class Player <char> final  //템플릿 특수화
{
public:
	explicit Player() : _keytemp(NULL) { ; }
	virtual ~Player() = default;
	explicit Player(const Player&) = delete;
	Player& operator = (const Player&) = delete;

public:
	const char& keyInput()
	{
		_keytemp = _getche();
		return _keytemp;
	}
	const char& getKey() const { return _keytemp; }

private:
	char _keytemp;

};