#include <string>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			Bureaucrat bureaucrat("me", std::atoi(argv[1]));
			std::cout << bureaucrat << '\n';
			std::cout << "incrementing: ";
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << '\n';
			std::cout << "decrementing: ";
			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.m_sMessage << " : " << e.m_nGrade << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.m_sMessage << " : " << e.m_nGrade << std::endl;
		}
		catch(...)
		{
			std::cerr << "What the fun is this?" << std::endl;
		}
	}
	return (0);
}
