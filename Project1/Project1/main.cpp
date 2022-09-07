#include <iostream>



class Coordinate
{
private:
	int x, y;
public:
	Coordinate()
	{
		x = 0;
		y = 0;
	}

	Coordinate(int x1, int y1)
	{
		x = x1;
		y = y1;
	}

	void print()
	{
		std::cout << "\nCoordX = " << x << "\tCoordY = " << y << "\n";
	}

	Coordinate& operator=(const Coordinate& right)
	{
		if (this == &right)
		{
			return *this;
		}
		x = right.x;
		y = right.y;
		return *this;
	}

	Coordinate& operator+(const Coordinate& right)
	{
		Coordinate result;
		result.x = this->x + right.x;
		result.y = this->y + right.y;

		return result;
	}

	Coordinate& operator-(const Coordinate& right)
	{
		Coordinate result;
		result.x = this->x - right.x;
		result.y = this->y - right.y;

		return result;
	}

	bool operator==(const Coordinate& right)
	{
		if ((this->x = right.x) && (this->y = right.y)) return true;
		else return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);
};

std::ostream& operator<<(std::ostream& os, const Coordinate& c)
{
	std::cout << "\nCoordX = " << c.x << "\tCoordY = " << c.y << "\n";
	return os;
}


int main()
{
	Coordinate Check(1, 2);
	Check.print();
	Coordinate Check2(2, 2);
	Check = Check2;
	Check.print();
	Coordinate Check3 = Check + Check2;
	Check3.print();
	std::cout << "\n" << Check;
	return 0;
}