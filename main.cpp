#include <deque>
#include <iostream>
#include <cstdlib>

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
		int backYCoordinate = board.back().back().getY();
		int frontYCoordinate = board.front().front().getY();

		if (direction == COORDINATE_DIRECTION::POSITIVE)
		{
			for (int i = 0; i != xSize; ++i)
			{
				line.push_back(Point(xCoordinate++, backYCoordinate + 1));
			}
			board.push_back(line);
		}
		else if (direction == COORDINATE_DIRECTION::NEGATIVE)
		{
			for (int i = 0; i != xSize; ++i)
			{
				line.push_back(Point(xCoordinate++, frontYCoordinate - 1));
			}
			board.push_front(line);
		}
		ySize += 1;
	}

	void createNewPoint(int x, int y)
	{
		int backYCoordinate = board.back().back().getY();
		int frontYCoordinate = board.front().front().getY();
		// Map is always a rectangle so it does not matter which line we are using
		int frontXCoordinate = board[0].front().getX();
		int backXCoordinate = board[0].back().getX();

		// If point already exists, do nothing
		if (y <= backYCoordinate && y >= frontYCoordinate && x <= backXCoordinate && x >= frontXCoordinate)
		{
			std::cout << "Point deja present" << std::endl;
			return;
		}

		// extend map on x negative coordinates
		if (x < 0)
		{			
			for (int i = 0; i != abs(x - frontXCoordinate); ++i)
			{
				createNewColumn(COORDINATE_DIRECTION::NEGATIVE);
			}
		}
		// extend map on x positive coordinates
		else
		{
			for (int i = 0; i != x - backXCoordinate; ++i)
			{
				createNewColumn(COORDINATE_DIRECTION::POSITIVE);
			}
		}

		// extend map on y negative coordinates
		if (y < 0)
		{
			for (int i = 0; i != abs(y - frontYCoordinate); ++i)
			{
				createNewLine(COORDINATE_DIRECTION::NEGATIVE);
			}
		}
		// extend map on y positive coordinates
		else
		{
			for (int i = 0; i != y - backYCoordinate; ++i)
			{
				createNewLine(COORDINATE_DIRECTION::POSITIVE);
			}
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
