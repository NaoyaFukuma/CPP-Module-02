#include "Point.hpp"

Point::Point(void)
	: _x(0), _y(0)
{
	// std::cout << "Point created" << std::endl;
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
	// std::cout << "Point created" << std::endl;
}

Point::Point(const Point &src)
	: _x(src._x), _y(src._y)
{
	// std::cout << "Point created" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destroyed" << std::endl;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed &>(_x) = rhs.getX();
		const_cast<Fixed &>(_y) = rhs.getY();
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

Point	Point::sub_point(Point &a, Point &b) const
{
	return (Point(a.getX().toFloat() - b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat()));
}

Point	Point::sub_point(const Point &a, const Point &b) const
{
	return (Point(a.getX().toFloat() - b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat()));
}

Point Point::operator-(Point &rhs) const
{
	return (sub_point(const_cast<const Point&>(*this), rhs));
}

Point Point::operator-(const Point &rhs) const
{
	return (sub_point(*this, rhs));
}

Point	Point::add_point(Point &a, Point &b) const
{
	return (Point(a.getX().toFloat() + b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat()));
}

Point	Point::add_point(const Point &a, const Point &b) const
{
	return (Point(a.getX().toFloat() + b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat()));

}

Point Point::operator+(Point &rhs) const
{
	return (sub_point(*this, rhs));
}

Point Point::operator+(const Point &rhs) const
{
	return (sub_point(*this, rhs));
}

static void	input(int &num)
{
	bool	valid = false;

	do
	{
		std::cin >> num;
		if (std::cin.eof() || std::cin.bad())
			std::exit(EXIT_FAILURE);
		if (std::cin.good())
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please try again." << std::endl;
		}
	} while (!valid);
}

Point Point::input_point()
{
	int	x, y;
	std::cout << "Please enter the XY coordinate" << std::endl;
	std::cout << "x value = " << std::flush;
	input(x);
	std::cout << "y value = " << std::flush;
	input(y);
	Point reslut(x, y);
	std::cout << "\e[3;2mresult : " << reslut << "\e[m" << std::endl;
	return (reslut);
}

std::ostream &operator<<(std::ostream &ostream, Point const &Point)
{
	ostream << "x=" << Point.getX() << " y=" << Point.getY() << std::flush;
	return (ostream);
}

