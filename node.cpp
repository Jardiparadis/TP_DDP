#include "node.h"

std::shared_ptr<Node> Node::getParent() const
{
	return parent;
}

Point* Node::getPoint() const
{
	return point;
}

int Node::getFCost() const
{
	return fCost;
}

int Node::getDistanceWithStart() const
{
	return distanceWithStart;
}

void Node::setParent(std::shared_ptr<Node> _parent)
{
	parent = _parent;
}

void Node::setPoint(Point* _point)
{
	point = _point;
}

void Node::setFCost(int _fCost)
{
	fCost = _fCost;
}

void Node::setDistanceWithStart(int _distanceWithStart)
{
	distanceWithStart = _distanceWithStart;
}
