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
		if (!cin.fail()) //cin������ 1�� ��ȯ�Ѵ�. ex) int ������ cin���� *char�� �����
		{
			return _keytemp;
		}
		cin.clear(); //cin ��ü�� "���� ���� �÷���"�� �ʱ�ȭ���Ѽ� cin ���� ����� �����۵��ϵ�����
		cin.ignore(100, '\n'); //�Է� ���ۿ� �ִ� ��� ������ �����ؼ� ����
		return 0;
	}
	const T& getKey() const { return _keytemp; }
	const T& getch() { _keytemp = _getch(); return _keytemp; }

private:
	T _keytemp;

};

template <> class Player <char> final  //���ø� Ư��ȭ
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