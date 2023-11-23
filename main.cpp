#include <deque>
#include <iostream>
#include <cstdlib>

#include "map.h"

int main()
{
	Map map(0, 0);

	map.createNewPoint(12, 12);
	map.createNewPoint(-12, 12);
	map.createNewPoint(12, -12);
	map.createNewPoint(-12, -12);

	std::cout << "##########" << std::endl;
	map.displayMap();

	return 0;
}
