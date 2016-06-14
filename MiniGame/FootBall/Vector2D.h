#pragma once
class Vector2D final
{
private:
	int x;
	int y;

public:
	explicit Vector2D(int _x, int _y);	//explicit ������ ����ȯ�� ���ϰ� ���� ����� ����ȯ�� �����ϰ� �Ѵ�.
	explicit Vector2D() = default;		//default C++11���� ���� �������� ����Ʈ�����ڸ� �������ش�.
	~Vector2D() = default;
	//�Ҹ��ڸ� ���� �Լ��� �������� ������ �ٸ� ��ü�� ����Ű�� ��� �ּҰ� ����Ű�� Ŭ������ �Ҹ��ڴ� ȣ����� �ʴ´�.
	//���ݰ�����쿣 ���𰡾����� �Ἥ ���غ����� ���⋚���� ����ó�� ���̴°� ���� �� �˾�����
	//����Ƽ�� C++���� �����ʿ䰡���°�쿣 �������ʴ°� ���ٰ� �����ִ�.
public:

	const int& getX() const { return x; }
	const int& getY() const { return y; }
	void setX(const int& _x) { x = _x; } //�Ű������� _ ���̱�
	void setY(const int& _y) { y = _y; }
	void addX() { x++; }
	void subX() { x--; }
	void addY() { y++; }
	void subY() { y--; }

};
