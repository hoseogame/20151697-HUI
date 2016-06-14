#pragma once
#include "Vector2D.h"
#include "SnakeDefault.h"

//x 위치값
#define GET_X getVec2().getX()
//y 위치값
#define GET_Y getVec2().getY()

class SnakeObject abstract 
{
public:
	explicit SnakeObject() = default;
	virtual ~SnakeObject() = default;
	SnakeObject(const SnakeObject&) = delete;
	SnakeObject& operator = (const SnakeObject&) = delete;

public:
	const Vector2D& getVec2() const
	{
		return pos;
	}
	void setVec2X(const int _x) { pos.setX(_x); }
	void setVec2Y(const int _y) { pos.setY(_y); }
	void addVec2X() { pos.addX(); }
	void addVec2Y() { pos.addY(); }
	void subVec2X() { pos.subX(); }
	void subVec2Y() { pos.subY(); }

	virtual void init(SNAKESTAGE_INFO&) = 0;
	virtual void update(SNAKESTAGE_INFO&) = 0;
	virtual void render(int(*&)[29]) = 0;

private:
	Vector2D pos;

};
