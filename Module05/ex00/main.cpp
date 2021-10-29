#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			Bureaucrat bureaucrat("me", std::stoi(argv[1]));
			std::cout <<	bureaucrat.getName() <<
							" with grade " << bureaucrat.getGrade() <<
							" is fine." << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.m_sMessage << " : " << std::stoi(argv[1]) << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.m_sMessage << " : " << std::stoi(argv[1]) << std::endl;
		}
		catch(...)
		{
			std::cerr << "What the fun is this?" << std::endl;
		}
	}
	return (0);
}
