#include "Point.hpp"

void	printBits(int x)
{
	for (int i = 31; i >= 0; --i)
	{
		std::cout << ((x >> i) & 1);
		if (i % 8 == 0)
			std::cout << " | ";
	}
	std::cout << std::endl;
}

inline bool bsp(	Point const A,
					Point const B,
					Point const C,
					Point const point)
{
	if (A == B || B == C || C == A)
	{
		return (false);
	}
	else if ((B.getX() - A.getX()) * (point.getY() - A.getY()) - (B.getY() - A.getY()) * (point.getX() - A.getX()) > 0
		&& (C.getX() - B.getX()) * (point.getY() - B.getY()) - (C.getY() - B.getY()) * (point.getX() - B.getX()) > 0
		&& (A.getX() - C.getX()) * (point.getY() - C.getY()) - (A.getY() - C.getY()) * (point.getX() - C.getX()) > 0)
	{
		return (true);
	}
	return (false);
}

int	main()
{
	Point A(1, 1);
	Point B(1.5, 4);
	Point C(1, 8);
	Point point(1.2, 4.1);

	std::cout << (bsp(A, B, C, point) ? "true" : "false") << std::endl;
	return 0;
}
