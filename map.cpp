#include "map.h"

Map::Map(int _xSize, int _ySize)
{
	std::deque<Point> initialPoint;
	initialPoint.push_back(Point(0, 0));
	board.push_back(initialPoint);

	smallestX = 0;
	greatestX = 0;
	smallestY = 0;
	greatestY = 0;

	for (int i = 0; i != _ySize; ++i)
	{
		createNewLine(COORDINATE_DIRECTION::POSITIVE);
	}
	for (int i = 0; i != _xSize; ++i)
	{
		createNewColumn(COORDINATE_DIRECTION::POSITIVE);
	}
}

Map::~Map()
{
}

void Map::displayMap()
{
	for (auto& line : board)
	{
		for (auto& cell : line)
		{
			if (cell.getFieldType() == FIELD_TYPE::OBSTACLE)
			{
				std::cout << "X";
			}
			else if (cell.getFieldType() == FIELD_TYPE::PATH)
			{
				std::cout << "#";
			}
			else if (cell.getFieldType() == FIELD_TYPE::WATER)
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}

void Map::createNewColumn(COORDINATE_DIRECTION direction)
{
	int yCoordinate = smallestY;
	int totalYSize = greatestY + abs(smallestY);
	if (direction == COORDINATE_DIRECTION::POSITIVE)
	{
		greatestX += 1;
		for (int i = 0; i != totalYSize + 1; ++i)
		{
			board[i].push_back(Point(greatestX, yCoordinate++));
		}

	}
	if (direction == COORDINATE_DIRECTION::NEGATIVE)
	{
		smallestX -= 1;
		for (int i = 0; i != totalYSize + 1; ++i)
		{
			board[i].push_front(Point(smallestX, yCoordinate++));
		}
	}
}

void Map::createNewLine(COORDINATE_DIRECTION direction)
{
	std::deque<Point> line;
	int xCoordinate = smallestX;
	int totalXSize = greatestX + abs(smallestX);

	if (direction == COORDINATE_DIRECTION::POSITIVE)
	{
		greatestY += 1;
		for (int i = 0; i != totalXSize + 1; ++i)
		{
			line.push_back(Point(xCoordinate++, greatestY));
		}
		board.push_back(line);
	}
	else if (direction == COORDINATE_DIRECTION::NEGATIVE)
	{
		smallestY -= 1;
		for (int i = 0; i != totalXSize + 1; ++i)
		{
			line.push_back(Point(xCoordinate++, smallestY));
		}
		board.push_front(line);
	}
}

Point* Map::getPoint(int x, int y)
{
	for (int i = 0; i != board.size(); ++i)
	{
		if (board[i][0].getY() == y)
		{
			for (int j = 0; j != board[i].size(); ++j)
			{
				if (board[i][j].getX() == x)
				{
					return &board[i][j];
				}
			}
		}
	}
	return NULL;
}

void Map::createNewPoint(int x, int y, FIELD_TYPE fieldType)
{
	// If point already exists, only update type
	if (y <= greatestY && y >= smallestY && x <= greatestX && x >= smallestX)
	{
		getPoint(x, y)->setFieldType(fieldType);
		return;
	}

	// extend map on x negative coordinates
	if (x < 0)
	{
		for (int i = abs(smallestX); i < abs(x); ++i)
		{
			createNewColumn(COORDINATE_DIRECTION::NEGATIVE);
		}
	}
	// extend map on x positive coordinates
	else
	{
		for (int i = greatestX; i < x; ++i)
		{
			createNewColumn(COORDINATE_DIRECTION::POSITIVE);
		}
	}

	// extend map on y negative coordinates
	if (y < 0)
	{
		for (int i = abs(smallestY); i < abs(y); ++i)
		{
			createNewLine(COORDINATE_DIRECTION::NEGATIVE);
		}
	}
	// extend map on y positive coordinates
	else
	{
		for (int i = greatestY; i < y; ++i)
		{
			createNewLine(COORDINATE_DIRECTION::POSITIVE);
		}
	}

	// Set field type to the right cell
	getPoint(x, y)->setFieldType(fieldType);
}

std::shared_ptr<Node> Map::getLowestFCostIndex(const std::unordered_map<std::string, std::shared_ptr<Node>>& list)
{
	std::shared_ptr<Node> smallestCost = list.begin()->second;

	for (auto it = list.begin(); it != list.end(); it++) {
		if (smallestCost->getFCost() > it->second->getFCost())
		{
			smallestCost = it->second;
		}
	}
	return smallestCost;
}

int Map::getDistanceBetweenTwoPoint(int x1, int y1, int x2, int y2)
{
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

bool Map::isInPath(std::shared_ptr<Node> finalNode, const Point &cell) const
{
	while (finalNode != NULL)
	{
		if (finalNode->getPoint()->getX() == cell.getX() && finalNode->getPoint()->getY() == cell.getY())
		{
			return true;
		}
		finalNode = finalNode->getParent();
	}
	return false;
}

std::shared_ptr<Node> Map::getFirstNode(std::shared_ptr<Node> finalNode) const
{
	while (finalNode != NULL)
	{
		if (finalNode->getParent() == NULL)
		{
			return finalNode;
		}
		finalNode = finalNode->getParent();
	}
	return NULL;
}

void Map::drawSolution(std::shared_ptr<Node> finalNode)
{	
	std::shared_ptr<Node> firstNode = getFirstNode(finalNode);
	for (const auto& line : board)
	{
		for (const auto& cell : line)
		{
			// If it is the first node, display it as the end of the path (node path is reversed)
			if (finalNode->getPoint()->getX() == cell.getX() && finalNode->getPoint()->getY() == cell.getY())
			{
				std::cout << "E";
				continue;
			}

			// If it is the last node, display it as the start of the path (node path is reversed)
			if (firstNode->getPoint()->getX() == cell.getX() && firstNode->getPoint()->getY() == cell.getY())
			{
				std::cout << "S";
				continue;
			}

			if (isInPath(finalNode, cell))
			{
				std::cout << "#";
				continue;
			}

			if (cell.getFieldType() == FIELD_TYPE::OBSTACLE)
			{
				std::cout << "X";
			}
			else if (cell.getFieldType() == FIELD_TYPE::WATER)
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}

void Map::searchForPath(int startingX, int startingY, int destinationX, int destinationY)
{
	// We choose unordered map for fast access to elements, easy insert / delete anywhere in the list, as theya re not contiguous in memory
	// Open list store node to inspect
	std::unordered_map<std::string, std::shared_ptr<Node>> openList;
	// Close list store explored nodes
	std::unordered_map<std::string, std::shared_ptr<Node>> closeList;
	// Key in these map are formated like : "x-coordinate;y-coordinate"

	//Add start node to openList
	std::shared_ptr<Node> startNode(new Node(getPoint(startingX, startingY)));
	openList.insert({ std::to_string(startNode->getPoint()->getX()) + ';' + std::to_string(startNode->getPoint()->getY()) , startNode });

	while (openList.size() > 0)
	{
		// Move lowest cost from open to close list
		std::shared_ptr<Node> currentNode = getLowestFCostIndex(openList);
		std::string currentNodeKey = std::to_string(currentNode->getPoint()->getX()) + ';' + std::to_string(currentNode->getPoint()->getY());
		closeList.insert({ currentNodeKey, currentNode });
		openList.erase(currentNodeKey);

		// Win condition
		if (currentNode->getPoint()->getX() == destinationX && currentNode->getPoint()->getY() == destinationY)
		{
			return drawSolution(currentNode);
		}

		// Get all the 8 adjacentes nodes
		std::vector<Node> adjacentNodes = {
			Node(getPoint(currentNode->getPoint()->getX() + 1, currentNode->getPoint()->getY())),
			Node(getPoint(currentNode->getPoint()->getX()    , currentNode->getPoint()->getY() + 1)),
			Node(getPoint(currentNode->getPoint()->getX() - 1, currentNode->getPoint()->getY())),
			Node(getPoint(currentNode->getPoint()->getX()    , currentNode->getPoint()->getY() - 1)),
			Node(getPoint(currentNode->getPoint()->getX() + 1, currentNode->getPoint()->getY() + 1)),
			Node(getPoint(currentNode->getPoint()->getX() - 1, currentNode->getPoint()->getY() - 1)),
			Node(getPoint(currentNode->getPoint()->getX() + 1, currentNode->getPoint()->getY() - 1)),
			Node(getPoint(currentNode->getPoint()->getX() - 1, currentNode->getPoint()->getY() + 1))
		};

		// explore adjacentes nodes
		for (const auto& adjacentNode : adjacentNodes)
		{
			// Node does not exists on the map
			if (adjacentNode.getPoint() == NULL)
			{
				continue;
			}
			std::string nodeKey = std::to_string(adjacentNode.getPoint()->getX()) + ';' + std::to_string(adjacentNode.getPoint()->getY());
			// If is is an obstacle or if node exists in the close or open list
			const auto &nodeInOpenList = openList.find(nodeKey);
			if (
				adjacentNode.getPoint()->getFieldType() == FIELD_TYPE::OBSTACLE || // If it is an obstacle
				closeList.find(nodeKey) != closeList.end() || // If it exists in the close list
				(nodeInOpenList != openList.end() && nodeInOpenList->second->getFCost() < adjacentNode.getFCost()) //If it exists in the open list with a smaller fCost value
			)
			{
				continue;
			}

			// Create a new node and insert it in the open list
			std::shared_ptr<Node> node(new Node(adjacentNode.getPoint()));
			int distanceBetweenAdjacenteNodeAndCurrentNode = getDistanceBetweenTwoPoint(adjacentNode.getPoint()->getX(), adjacentNode.getPoint()->getY(), currentNode->getPoint()->getX(), currentNode->getPoint()->getY());
			node->setDistanceWithStart(currentNode->getDistanceWithStart() + distanceBetweenAdjacenteNodeAndCurrentNode);
			node->setFCost(node->getDistanceWithStart() + getDistanceBetweenTwoPoint(adjacentNode.getPoint()->getX(), adjacentNode.getPoint()->getY(), destinationX, destinationY));
			node->setParent(currentNode);
			openList.insert({ std::to_string(node->getPoint()->getX()) + ';' + std::to_string(node->getPoint()->getY()) , node });
		}
	}
}
