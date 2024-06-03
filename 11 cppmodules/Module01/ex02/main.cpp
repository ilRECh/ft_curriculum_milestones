#include <iostream>
#include <string>

int	main()
{
	std::string	hi = "HI THIS IS BRAIN";
	std::string	&stringREF = hi;
	std::string	*stringPTR = &hi;

	std::cout	<< &hi << "\n"
				<< stringPTR << "\n"
				<< &stringREF << "\n"
				<< *stringPTR << "\n"
				<< stringREF << std::endl;
	return (0);
}
