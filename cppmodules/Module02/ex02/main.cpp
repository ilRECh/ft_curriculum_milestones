#include "Fixed.hpp"

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

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
