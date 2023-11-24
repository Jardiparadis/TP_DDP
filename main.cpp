#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map(0, 0);

	map.createNewPoint(500, 500, FIELD_TYPE::WATER);
	map.createNewPoint(-6, -6, FIELD_TYPE::WATER);
	map.createNewPoint(5, 4, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 6, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(7, 6, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(7, 8, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 7, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 5, FIELD_TYPE::OBSTACLE);

	std::cout << "##########" << std::endl;
	//map.displayMap();

	map.searchForPath(1, 1, 450, 450);

	return 0;
}
