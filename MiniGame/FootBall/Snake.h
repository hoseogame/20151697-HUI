#pragma once
#include "SnakeObject.h"
#include "Vector2D.h"
#include <ctime>

class Snake final : public SnakeObject
{
public:
	explicit Snake();
	virtual  ~Snake() = default;
	Snake(const Snake&) = delete;
	Snake& operator = (const Snake&) = delete;

public:
	// pos
	void move();

public:
	// Life
	int getLife() const { return nLife; }
	void setLife(int _life) { nLife = _life; }
	void addLife() { nLife++; }
	void subLife() { nLife--; }
	// Direct
	DIRECT getDirect() const { return eDirect; }
	void setDirect(DIRECT _direct) { eDirect = _direct; }
	// Movetime
	clock_t getMoveTime() const { return MoveTime; }
	// Oldtime
	clock_t getOldTime() const { return OldTime; }
	void setOldTime(clock_t _time) { OldTime = _time; }
	// Eatcount
	int getEatCount() const { return nEatCount; }
	// TailArray
	Vector2D getTailArray(int _num) { return sTail[_num]; }
	// Eat
	bool isEat() {
		if (eat == true)
		{
			eat = false;
			return true;
		}
		else return false;
	}

public:
	void init(SNAKESTAGE_INFO&) override;
	void update(SNAKESTAGE_INFO&) override;
	void render(int(*&)[29]) override;

private:
	bool eat;
	int	nLife;
	int nEatCount;
	DIRECT eDirect;
	clock_t	MoveTime;
	clock_t	OldTime;
	Vector2D sHeadold;
	Vector2D sTail[20], sTailOld[20];

};
