#include <deque>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "map.h"
#include "noeud.h"

//calcule la distance entre les points(x1, y1) et(x2, y2)
float distance(int x1, int y1, int x2, int y2) {
	/* distance euclidienne */
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float calculCout(int x1, int y1, int x2, int y2)
{
	float coutPoint = distance(x1, y1, x2, y2);
	return coutPoint;
}

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


	float a = calculCout(0,0,5,6);
	float b = calculCout(-4, 2, -8, 6);

	if (a > b)
	{
		std::cout << "a>b" << std::endl;
	}
	else
	{
		std::cout << "a<b" << std::endl;
	}

	return 0;
}
