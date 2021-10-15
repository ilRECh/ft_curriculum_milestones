#include "Point.hpp"

Point::Point():	x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point& p):	x(p.x), y(p.y)
{
}

Point::Point(const float x, const float y):	x(x), y(y)
{
}

Point& Point::operator=(const Point& p)
{
	if (this == &p)
		return (*this);
	*this = Point(p);
	return (*this);
}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}
