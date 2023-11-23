#pragma once

#include <deque>
#include <iostream>
#include <cstdlib>

#include "point.h"

enum class COORDINATE_DIRECTION
{
	POSITIVE,
	NEGATIVE
};

class Map
{
public:
	Map(int _xSize, int _ySize);
	~Map();

	void displayMap();
	void createNewPoint(int x, int y, FIELD_TYPE fieldType);
private:
	int xSize;
	int ySize;
	int smallestX;
	int greatestX;
	int smallestY;
	int greatestY;
	std::deque<std::deque<Point>> board;

	void createNewColumn(COORDINATE_DIRECTION direction);
	void createNewLine(COORDINATE_DIRECTION direction);
	Point& getPoint(int x, int y);
};
