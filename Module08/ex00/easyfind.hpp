#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
bool easyfind(T& container, int value)
{
	if (std::find(container.begin(), container.end(), value) != container.end())
	{
		std::cout << "value: " << value << " was found in the container" << std::endl;
		return (false);
	}
	std::cout << "value: " << value << " was not found." << std::endl;
	return (true);
}
