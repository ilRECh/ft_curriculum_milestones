#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	~Point();
	Point(const Point& p);
	Point(const float x, const float y);
	Point& operator=(const Point& p);
	bool operator==(const Point& A) const;
	Fixed getX() const;
	Fixed getY() const;
};
