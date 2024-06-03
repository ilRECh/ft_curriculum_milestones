#pragma once
#include <iostream>

template <typename T>
void iter(T *array, unsigned int len, void (*func)(T&))
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << array[i] << ' ';
		(*func)(array[i]);
		std::cout << array[i] << '\n';
	}
	std::cout << std::endl;
}
