#pragma once
#include "FootBallObject.h"
#include <ctime>

// 플레이어의 moveX
#define MOVE_X getInfo().m_PlayerPos.movePos.getX()
// 플레이어의 moveY
#define MOVE_Y getInfo().m_PlayerPos.movePos.getY()
// 플레이어의 centerX
#define CENTER_X getInfo().m_PlayerPos.centerPos.getX()
// 플레이어의 posX
#define POS_X getInfo().m_PlayerPos.pos.getX()

struct PLAYERPOS
{
	Vector2D centerPos;
	Vector2D movePos;
	Vector2D pos;
};

const char g_strPlayer[] = "┗━●━┛";

class Ball final : public FootBallObject
{
public:
	explicit Ball();
	virtual ~Ball() = default;
	explicit Ball(const Ball&) = delete;
	Ball& operator = (const Ball&) = delete;

public:
	void init() override;
	void update() override;
	void render() override;

private:
	struct BallInfo
	{
		int nIsReady;        // 준비 상태(1), 슛상태(0)
		clock_t MoveTime;    // 이동 시간 간격
		clock_t OldTime;     // 이전 이동 시각
		PLAYERPOS m_PlayerPos;
	};
	BallInfo m_info;

public:
	const BallInfo& getInfo() const { return m_info; }

	void setisReady(const int &_isReady) { m_info.nIsReady = _isReady; }

	void setOldTime(const clock_t &_oldTime) { m_info.OldTime = _oldTime; }
	
	void setPlayerX(const int &_x) { m_info.m_PlayerPos.pos.setX(_x); }

	void subPlayerMoveX() { m_info.m_PlayerPos.movePos.subX(); }
	void addPlayerMoveX() { m_info.m_PlayerPos.movePos.addX(); }
};