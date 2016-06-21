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
		int m_nLength;			// ��� ����	
		int nLineX[7];			// ���� ���� x ��ǥ (7��)
		clock_t	MoveTime;		// �̵� �ð� ����
		clock_t	OldTime;	    // ���� �̵� �ð�
		int	nDist;				// �̵� �Ÿ�
	};
	GoaldaeInfo m_info;

public:
	const GoaldaeInfo& getInfo() const { return m_info; }

	void setOldTime(const clock_t _oldTime) { m_info.OldTime = _oldTime; }
	void setLineX(int _num, int _val) { m_info.nLineX[_num] = _val; }
	void setDist(int _dist) { m_info.nDist = _dist; }
};