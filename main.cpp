#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map(0, 0);

	map.createNewPoint(12, 12, FIELD_TYPE::WATER);
	map.createNewPoint(5, 4, FIELD_TYPE::TEMPEST);
	map.createNewPoint(6, 6, FIELD_TYPE::REEF);
	map.createNewPoint(7, 6, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(7, 8, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 7, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 5, FIELD_TYPE::REEF);

	//map.displayMap();

	std::cout << "##########" << std::endl;

	map.searchForPath(0, 6, 7, 7);

	std::cout << "##########" << std::endl;

	//map.displayMap();

	return 0;
}
