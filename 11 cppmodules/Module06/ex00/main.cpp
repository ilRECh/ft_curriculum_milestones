#include "Converter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			Converter converter(argv[1]);
			converter.printCharValue();
			converter.printIntValue();
			converter.printFloatValue();
			converter.printDoubleValue();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "sh*t" << std::endl;
		}
	}
	return (0);
}
