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
				int yCoordinate = board[i].back().getY();
				board[i].push_back(Point(backXCoordinate + 1, yCoordinate));
			}
		}
		if (direction == COORDINATE_DIRECTION::NEGATIVE)
		{
			for (int i = 0; i != ySize; ++i)
			{
				int frontXCoordinate = board[i].front().getX();
				int yCoordinate = board[i].front().getY();
				board[i].push_front(Point(frontXCoordinate - 1, yCoordinate));
			}
		}
		xSize += 1;
	}

	void createNewLine(COORDINATE_DIRECTION direction)
	{
		std::deque<Point> line;

		int xCoordinate = board[0].front().getX();
		int backYCoordinate = board[0].back().getY();
		int frontYCoordinate = board[0].front().getY();

		if (direction == COORDINATE_DIRECTION::POSITIVE)
		{
			for (int i = 0; i != xSize; ++i)
			{
				line.push_back(Point(xCoordinate++, frontYCoordinate + 1));
			}
			board.push_back(line);
		}
		else if (direction == COORDINATE_DIRECTION::NEGATIVE)
		{
			for (int i = 0; i != xSize; ++i)
			{
				line.push_back(Point(xCoordinate++, backYCoordinate - 1));
			}
			board.push_front(line);
		}
		ySize += 1;
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
	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::POSITIVE);
	map.displayMap();
	std::cout << "-----" << std::endl;
	map.createNewLine(COORDINATE_DIRECTION::NEGATIVE);
	map.displayMap();

	return 0;
}
