#include "Ball.h"

Ball::Ball()
{
	m_info.m_PlayerPos.centerPos.setX(4);
	m_info.m_PlayerPos.centerPos.setY(0);
	m_info.m_PlayerPos.movePos.setX(20);
	m_info.m_PlayerPos.movePos.setY(22);
	m_info.m_PlayerPos.pos.setX(MOVE_X - CENTER_X);

	m_info.nIsReady = 1;

	setVec2X(MOVE_X);
	setVec2Y(MOVE_Y -1);
	m_info.MoveTime = 100;

}

void Ball::init()
{
}

void Ball::update()
{
}

void Ball::render()
{
}
