#pragma once

#include <deque>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <forward_list>

#include "point.h"
#include "node.h"

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
	void searchForPath(int startingX, int startingY, int destinationX, int destinationY);
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
	Point* getPoint(int x, int y);
	double getDistanceBetweenTwoPoint(int x1, int y1, int x2, int y2);
	std::shared_ptr<Node> getLowestFCostIndex(const std::unordered_map<std::string, std::shared_ptr<Node>>& list);
	void drawSolution(std::shared_ptr<Node> finalNode);
	bool isInPath(std::shared_ptr<Node> finalNode, const Point& cell) const;
	std::shared_ptr<Node> getFirstNode(std::shared_ptr<Node> finalNode) const;
};
