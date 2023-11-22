#include <deque>
#include <iostream>

// 1 comprendre deque
// 2 créer double deque

class Point
{
public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	~Point()
	{
	}
	const int& getX() const
	{
		return x;
	}
	const int& getY() const
	{
		return y;
	}
	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}
private:
	int x;
	int y;
};

class Map
{
public:
	Map(int _xSize, int _ySize)
	{
		xSize = _xSize;
		ySize = _ySize;

		for (int i = 0; i != ySize; ++i)
		{
			createLine(_xSize, i);
		}
	}
	~Map()
	{
	}
	
	const std::deque<std::deque<Point>> &getBoard() const
	{
		return board;
	}

	void displayMap()
	{
		for (auto line : board)
		{
			for (auto cell : line)
			{
				std::cout << "{" << cell.getY() << "," << cell.getX() << "},";
			}
			std::cout << std::endl;
		}
	}

private:
	int xSize;
	int ySize;
	std::deque<std::deque<Point>> board;

	void createLine(int lineSize, int y)
	{
		std::deque<Point> line;

		for (int i = 0; i != lineSize; ++i)
		{
			line.push_back(Point(i, y));
		}
			
		board.push_back(line);
	}
};

int main()
{
	Map map(5, 5);
	map.displayMap();
	return 0;
}