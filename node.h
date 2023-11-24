#pragma once

#include <iostream>
#include <cstdlib>

#include "point.h"

class Node
{
public:
	Node(Point* _point, std::shared_ptr<Node> _parent = NULL, int _fCost = 0, int _distanceWithStart = 0)
	{
		point = _point;
		parent = _parent;
		fCost = _fCost;
		distanceWithStart = _distanceWithStart;
	}
	std::shared_ptr<Node> getParent() const;
	Point* getPoint() const;
	int getFCost() const;
	int getDistanceWithStart() const;
	void setParent(std::shared_ptr<Node> _parent);
	void setPoint(Point* _point);
	void setFCost(int _fCost);
	void setDistanceWithStart(int _distanceWithStart);


private:
	std::shared_ptr<Node> parent;
	Point* point;
	int fCost;
	int distanceWithStart;
};