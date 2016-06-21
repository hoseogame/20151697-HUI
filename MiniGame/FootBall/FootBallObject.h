#pragma once
#include "Vector2D.h"

//x ��ġ��
#define GET_X getVec2().getX()
//y ��ġ��
#define GET_Y getVec2().getY()

class FootBallObject abstract //��Ŭ������ �����ӿ� ������Ʈ���� �θ𰡵ȴ�.
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
