#pragma once

class Point
{
public:
	Point(int _x, int _y);
	~Point();
	const int& getX() const;
	const int& getY() const;
	void setX(int _x);
	void setY(int _y);
private:
	int x;
	int y;
};
