#pragma once
#include "FootBallObject.h"
#include <ctime>

// �÷��̾��� moveX
#define MOVE_X getInfo().m_PlayerPos.movePos.getX()
// �÷��̾��� moveY
#define MOVE_Y getInfo().m_PlayerPos.movePos.getY()
// �÷��̾��� centerX
#define CENTER_X getInfo().m_PlayerPos.centerPos.getX()
// �÷��̾��� posX
#define POS_X getInfo().m_PlayerPos.pos.getX()

struct PLAYERPOS
{
	Vector2D centerPos;
	Vector2D movePos;
	Vector2D pos;
};

const char g_strPlayer[] = "�����ܦ���";

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
		int nIsReady;        // �غ� ����(1), ������(0)
		clock_t MoveTime;    // �̵� �ð� ����
		clock_t OldTime;     // ���� �̵� �ð�
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