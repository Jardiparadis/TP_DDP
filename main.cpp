#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map(0, 0);

	map.createNewPoint(12, 12, FIELD_TYPE::WATER);
	map.createNewPoint(10, 10, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(9, 9, FIELD_TYPE::OBSTACLE);

	std::cout << "##########" << std::endl;
	map.displayMap();

	map.getPathToPoint(0, 0, 10, 10);

	return 0;
}
