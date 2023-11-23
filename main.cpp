#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map(3, 2);
	map.createNewColumn(COORDINATE_DIRECTION::POSITIVE);
	map.createNewColumn(COORDINATE_DIRECTION::NEGATIVE);
	map.createNewColumn(COORDINATE_DIRECTION::POSITIVE);
	map.createNewColumn(COORDINATE_DIRECTION::NEGATIVE);
	map.createNewColumn(COORDINATE_DIRECTION::POSITIVE);
	map.createNewColumn(COORDINATE_DIRECTION::NEGATIVE);
	map.displayMap();
	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::POSITIVE);
	map.displayMap();
	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::NEGATIVE);
	map.displayMap();

	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::NEGATIVE);
	map.displayMap();

	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::POSITIVE);
	map.displayMap();


	map.createNewPoint(-7, 9);
	std::cout << "###-----###" << std::endl;
	map.displayMap();

	map.createNewPoint(-8, 10);
	std::cout << "##########" << std::endl;
	map.displayMap();

	map.createNewPoint(6, 11);
	std::cout << "##########" << std::endl;
	map.displayMap();

	map.createNewPoint(-9, -3);
	std::cout << "##########" << std::endl;
	map.displayMap();

	map.createNewPoint(7, -4);
	std::cout << "##########" << std::endl;
	map.displayMap();

	map.createNewPoint(7, -4);
	std::cout << "##########" << std::endl;
	//map.displayMap();

	map.createNewPoint(3, 3);
	std::cout << "##########" << std::endl;

	map.createNewPoint(20, 20);
	std::cout << "##########" << std::endl;

	return 0;
}
