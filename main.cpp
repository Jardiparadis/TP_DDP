#include <deque>
#include <iostream>

// 1 comprendre deque
// 2 créer double deque

class Map
{
public:
	Map()
	{
	}
	~Map()
	{
	}
	const std::deque<std::deque<int>> &getBoard() const
	{
		return board;
	}

private:
	std::deque<std::deque<int>> board;
};

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
	Map map();
	return 1;
}