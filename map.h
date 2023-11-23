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
	void createNewColumn(COORDINATE_DIRECTION direction);
	void createNewLine(COORDINATE_DIRECTION direction);
	void createNewPoint(int x, int y);
private:
	int xSize;
	int ySize;
	std::deque<std::deque<Point>> board;

	void createLine(int lineSize, int y);
};
