#include <iostream>
#include "Array.hpp"

int	main()
{
	Array<int> ar1;
	Array<int> ar2(10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ar2[i] << ' ';
		ar2[i] = i;
		std::cout << ar2[i] << '\n';
	}
	std::cout << std::endl;
	Array<int> ar3 = ar2;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ar3[i] << ' ';
		ar3[i] -= 1;
		std::cout << ar3[i] << ' ';
		std::cout << ar2[i] << '\n';
	}
	std::cout << std::endl;
	try
	{
		ar1[42];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
