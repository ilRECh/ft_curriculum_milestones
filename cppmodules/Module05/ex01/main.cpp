#include <string>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		try
		{
			Bureaucrat bureaucrat("me", std::atoi(argv[1]));
			Form form("some sh*t", std::atoi(argv[2]), std::atoi(argv[3]));
			std::cout << bureaucrat << '\n';
			std::cout << form << '\n';
			while (bureaucrat.signForm(form))
			{
				bureaucrat.incrementGrade();
				std::cout << bureaucrat << '\n';
			}
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
