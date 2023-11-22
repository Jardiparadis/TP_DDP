#include <deque>
#include <iostream>

// 1 comprendre deque
// 2 créer double deque

enum class COORDINATE_DIRECTION
{
	POSITIVE,
	NEGATIVE
};

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

	void createNewColumn(COORDINATE_DIRECTION direction)
	{
		if (direction == COORDINATE_DIRECTION::POSITIVE)
		{
			for (int i = 0; i != ySize; ++i)
			{
				int backXCoordinate = board[i].back().getX();
				board[i].push_back(Point(backXCoordinate + 1, i));
			}
		}
		if (direction == COORDINATE_DIRECTION::NEGATIVE)
		{
			for (int i = 0; i != ySize; ++i)
			{
				int frontXCoordinate = board[i].front().getX();
				board[i].push_front(Point(frontXCoordinate - 1, i));
			}
		}
		xSize += 1;
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

	// extend x
	

	// extend y


};

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
	return 0;
}