#pragma once
#include "Vector2D.h"

//x 위치값
#define GET_X getVec2().getX()
//y 위치값
#define GET_Y getVec2().getY()

class FootBallObject abstract //이클래스는 모든게임에 오브젝트들의 부모가된다.
{
public:
	explicit FootBallObject() = default;
	virtual ~FootBallObject() = default;
	FootBallObject(const FootBallObject&) = delete;
	FootBallObject& operator = (const FootBallObject&) = delete;

public:
	const Vector2D& getVec2() const
	{
		return pos;
	}
	void setVec2X(const int& _x) { pos.setX(_x); }
	void setVec2Y(const int& _y) { pos.setY(_y); }
	void addVec2X() { pos.addX(); }
	void addVec2Y() { pos.addY(); }
	void subVec2X() { pos.subX(); }
	void subVec2Y() { pos.subY(); }

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

private:
	Vector2D pos;

};
