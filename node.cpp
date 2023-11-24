#include "node.h"

Node *Node::getParent() const
{
	return parent;
}

Point* Node::getPoint() const
{
	return point;
}

double Node::getFCost() const
{
	return fCost;
}

double Node::getDistanceWithStart() const
{
	return distanceWithStart;
}

void Node::setParent(Node *_parent)
{
	parent = _parent;
}

void Node::setPoint(Point* _point)
{
	point = _point;
}

void Node::setFCost(double _fCost)
{
	fCost = _fCost;
}

void Node::setDistanceWithStart(double _distanceWithStart)
{
	distanceWithStart = _distanceWithStart;
}
