#include <deque>
#include <iostream>
#include <cstdlib>
#include <chrono>

#include "map.h"

int main()
{
	Map map(0, 0);

	map.createNewPoint(1000, 1000, FIELD_TYPE::WATER);
	map.createNewPoint(5, 4, FIELD_TYPE::TEMPEST);
	map.createNewPoint(6, 6, FIELD_TYPE::REEF);
	map.createNewPoint(7, 5, FIELD_TYPE::REEF);
	map.createNewPoint(7, 6, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(7, 8, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 7, FIELD_TYPE::OBSTACLE);
	map.createNewPoint(6, 5, FIELD_TYPE::REEF);

	//map.displayMap();

	std::cout << "##########" << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();

	map.searchForPath(0, 6, 875, 775);

	std::cout << "OH NO!" << std::endl;

	auto t2 = std::chrono::high_resolution_clock::now();

	std::cout << "##########" << std::endl;

	std::chrono::duration<double, std::milli> ms_double = t2 - t1;
	std::cout << ms_double.count() << "ms\n";

	//map.displayMap();

	return 0;
}
