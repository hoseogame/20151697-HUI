#pragma once
#include "SnakeObject.h"
#include "SnakeDefault.h"
#include <random>
#include <cstdlib>
#include <ctime>

class Enemy final : public SnakeObject
{
public:
	explicit Enemy();
	virtual  ~Enemy();
	Enemy(const Enemy&) = delete;
	Enemy& operator = (const Enemy&) = delete;

public:
	// Life
	bool is_life()
	{
		if (nLife == 1)
			return true;
		else
			return false;
	}
	void death() { nLife = 0; }

	// Direct
	//DIRECT getDirect() { return eDirect; }
	void setDirect(DIRECT _direct) { eDirect = _direct; }

	// Movetime
	clock_t getMoveTime() const { return MoveTime; }

	// Oldtime
	clock_t getOldTime() const { return OldTime; }
	void setOldTime(clock_t _time) { OldTime = _time; }

public:
	void init(SNAKESTAGE_INFO&) override;
	void update(SNAKESTAGE_INFO&) override;
	void render(int(*&)[29]) override;

private:
	int nLife;
	DIRECT eDirect;
	clock_t MoveTime;
	clock_t OldTime;

};