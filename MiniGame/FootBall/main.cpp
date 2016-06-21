#include "ConsoleGame.h"
#include "FootBallGame.h"
#include "SnakeGame.h"
#include <iostream>
using std::cout;
using std::endl;

void selectScreen();

int main()
{
	char select;
	ConsoleGame *Game = nullptr;

	selectScreen();
	do 
	{
		select = getch();
	} while (select != '1' && select != '2');
	
	if (select == '1')
	{ 
		Game = new FootBallGame;
	}
	else if (select == '2')
	{ 
		Game = new SnakeGame;
	}

	Screen::GetInstance()->screenInit();
	Game->init();
	
	Game->run();

	return 0;
}

void selectScreen()
{
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	cout << "                                           1. FootBall" << endl;
	cout << "                      Select Game : " << endl;
	cout << "                                           2. Snake" << endl;

}
