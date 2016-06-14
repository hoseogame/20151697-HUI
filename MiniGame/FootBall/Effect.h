#pragma once
#include "FootBallObject.h"
#include <ctime>
#include "Screen.h"

class Effect final : public FootBallObject
{
public:
	explicit Effect();
	virtual ~Effect() = default;
	explicit Effect(const Effect&) = delete;
	Effect& operator = (const Effect&) = delete;

public:
	void init() override;
	void update() override;
	void render() override;

public:
	void GoalMessage();

private:
	clock_t stratTime; // 효과 발생 시각
	clock_t stayTime;  // 효과 지속 시간	

public:
	const clock_t& getStayTime() const { return stayTime; }

	const clock_t& getStartTime() const { return stratTime; }
	void setStartTime(clock_t _startTime) { stratTime = _startTime; }

};