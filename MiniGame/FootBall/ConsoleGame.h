#pragma once

class ConsoleGame abstract
{
public:
	ConsoleGame();
	~ConsoleGame();

private:
	virtual void render() = 0;
	virtual void update() = 0;
	
public:
	virtual void init() = 0;
	virtual void run() = 0;

private:

};
