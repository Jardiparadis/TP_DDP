#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map("map.txt");
	//map.createNewPoint(12, 12, FIELD_TYPE::OBSTACLE);
	//map.createNewPoint(-12, 12, FIELD_TYPE::OBSTACLE);
	//map.createNewPoint(12, -12, FIELD_TYPE::OBSTACLE);
	//map.createNewPoint(-12, -12, FIELD_TYPE::OBSTACLE);

	std::cout << "##########" << std::endl;
	map.displayMap();

	return 0;
}
