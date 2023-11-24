#pragma once

#include <iostream>
#include <cstdlib>

#include "point.h"

class Node
{
public:
	Node(Point* _point, std::shared_ptr<Node> _parent = NULL, double _fCost = 0, double _distanceWithStart = 0)
	{
		point = _point;
		parent = _parent;
		fCost = _fCost;
		distanceWithStart = _distanceWithStart;
	}
	std::shared_ptr<Node> getParent() const;
	Point* getPoint() const;
	double getFCost() const;
	double getDistanceWithStart() const;
	void setParent(std::shared_ptr<Node> _parent);
	void setPoint(Point* _point);
	void setFCost(double _fCost);
	void setDistanceWithStart(double _distanceWithStart);


private:
	std::shared_ptr<Node> parent;
	Point* point;
	double fCost;
	double distanceWithStart;
};