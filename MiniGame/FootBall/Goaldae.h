#pragma once
#include "FootBallObject.h"
#include <ctime>
#include <string.h>
#include "Ball.h"
#include "FootBallDefault.h"

class Goaldae final : public FootBallObject
{
public:
	explicit Goaldae() = default;
	explicit Goaldae(const FOOTBALLSTAGE_INFO&);
	virtual ~Goaldae() = default;
	explicit Goaldae(const Goaldae&) = delete;
	Goaldae& operator = (const Goaldae&) = delete;

public:
	void init() override;
	void update() override;
	void render() override;

private:
	struct GoaldaeInfo
	{
		int m_nLength;			// 골대 길이	
		int nLineX[7];			// 골인 라인 x 좌표 (7개)
		clock_t	MoveTime;		// 이동 시간 간격
		clock_t	OldTime;	    // 이전 이동 시간
		int	nDist;				// 이동 거리
	};
	GoaldaeInfo m_info;

public:
	const GoaldaeInfo& getInfo() const { return m_info; }

	void setOldTime(const clock_t _oldTime) { m_info.OldTime = _oldTime; }
	void setLineX(int _num, int _val) { m_info.nLineX[_num] = _val; }
	void setDist(int _dist) { m_info.nDist = _dist; }
};