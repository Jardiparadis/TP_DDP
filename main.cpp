#include <deque>
#include <iostream>

// 1 comprendre deque
// 2 créer double deque

void displayMap(const std::deque<std::deque<int>> &deque)
{
	for (auto line : deque)
	{
		for (auto cell : line)
		{
			std::cout << cell;
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::deque<std::deque<int>> deque;
	deque.push_back(std::deque<int>{ 1 });
	deque.push_front(std::deque<int>{ 2 });
	deque.push_back(std::deque<int>{ 3 });

	deque.insert(deque.end(), std::deque<int>{ 4 });

	displayMap(deque);
	return 1;
}