#include "Effect.h"

Effect::Effect() : stayTime(2000) //2ÃÊ ¼³Á¤
{
	setVec2X(10);
	setVec2Y(10);
}

void Effect::init()
{
}

void Effect::update()
{
	
}

void Effect::render()
{
}

void Effect::GoalMessage()
{
	Screen::GetInstance()->screenPrint(GET_X, GET_Y, "¡Ù )) °ñÀÎ (( ¡Ú");
	Screen::GetInstance()->screenPrint(GET_X, GET_Y + 1, "¡¬(^^')/ ¡¬(\"*')/");
	Screen::GetInstance()->screenPrint(GET_X, GET_Y + 2, "   ¡á       ¡á");
	Screen::GetInstance()->screenPrint(GET_X, GET_Y + 3, "  ¦¥¦¤    ¦£¦¦");
}
