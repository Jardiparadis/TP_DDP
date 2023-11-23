#include "point.h"

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

Point::~Point()
{
}

const int& Point::getX() const
{
	return x;
}

const int& Point::getY() const
{
	return y;
}

void Point::setX(int _x)
{
	x = _x;
}

void Point::setY(int _y)
{
	y = _y;
}
