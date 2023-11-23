#pragma once

#include <deque>
#include <iostream>
#include <cstdlib>
#include <vector>

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
	void getPathToPoint(int startingX, int startingY, int destinationX, int destinationY);
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
	std::shared_ptr<Point> getPoint(int x, int y);
};

class Node
{
public:
	Node(std::shared_ptr<Point> _point)
	{
		_point = point;
	}
	std::shared_ptr<Point> getPoint()
	{
		return point;
	}
private:
	std::shared_ptr<Point> point;
};