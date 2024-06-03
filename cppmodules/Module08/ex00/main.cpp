#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include "easyfind.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::vector<int> vect;
		std::array<int, 10> arr;
		std::deque<int> deq(10);
		for (int i = 0; i < 10; ++i)
		{
			vect.push_back(i);
			arr[i] = i;
			deq[i] = i;
		}
		easyfind(vect, std::atoi(argv[1]));
		easyfind(arr, std::atoi(argv[1]));
		easyfind(deq, std::atoi(argv[1]));
	}
	return (0);
}
