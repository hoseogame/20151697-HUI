#pragma once
class Vector2D final
{
private:
	int x;
	int y;

public:
	explicit Vector2D(int _x, int _y);	//explicit 묵시적 형변환을 못하게 막아 명시적 형변환만 가능하게 한다.
	explicit Vector2D() = default;		//default C++11부터 나온 문법으로 디폴트생성자를 생성해준다.
	~Vector2D() = default;
	//소멸자를 가상 함수로 선언하지 않으면 다른 객체를 가르키는 경우 주소가 가르키는 클래스의 소멸자는 호출되지 않는다.
	//지금같은경우엔 쓸모가없지만 써서 손해볼것은 없기떄문에 버릇처럼 붙이는게 좋은 줄 알았지만
	//이펙티브 C++에서 붙일필요가없는경우엔 붙이지않는게 좋다고 써져있다.
public:

	const int& getX() const { return x; }
	const int& getY() const { return y; }
	void setX(const int& _x) { x = _x; } //매개변수는 _ 붙이기
	void setY(const int& _y) { y = _y; }
	void addX() { x++; }
	void subX() { x--; }
	void addY() { y++; }
	void subY() { y--; }

};
