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
	Fixed a(2.5f);
	printBits(a.getRawBits());
	return (0);
}
