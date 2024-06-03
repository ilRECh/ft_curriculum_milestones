#include <iostream>
#include "whatever.hpp"

int	main()
{
	char a = 'a', b = 'b';
	int c = 42, d = 21;
	float y = 3.14f, z = 2.1896f;

	std::cout << "def:  " << a << ' ' << b << '\n';
	swap(a, b);
	std::cout << "swap: " << a << ' ' << b << '\n';
	std::cout << "max: " << max(a, b) << '\n';
	std::cout << "min: " << min(a, b) << std::endl;

	std::cout << "def:  " << c << ' ' << d << '\n';
	swap(c, d);
	std::cout << "swap: " << c << ' ' << d << '\n';
	std::cout << "max: " << max(c, d) << '\n';
	std::cout << "min: " << min(c, d) << std::endl;

	std::cout << "def:  " << y << ' ' << z << '\n';
	swap(y, z);
	std::cout << "swap: " << y << ' ' << z << '\n';
	std::cout << "max: " << max(y, z) << '\n';
	std::cout << "min: " << min(y, z) << std::endl;
	return (0);
}
