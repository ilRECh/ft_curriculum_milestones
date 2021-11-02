#include <string>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		{
			try
			{
				Bureaucrat bureaucrat("me", std::atoi(argv[1]));
				Form *form = new ShrubberyCreationForm("home");
				std::cout << bureaucrat << '\n' << *form << '\n';
				bureaucrat.signForm(*form);
				bureaucrat.executeForm(*form);
				delete form;
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

		{
			try
			{
				Bureaucrat bureaucrat("me", std::atoi(argv[1]));
				Form *form = new RobotomyRequestForm("Mike Vazovsky");
				std::cout << bureaucrat << '\n' << *form << '\n';
				bureaucrat.signForm(*form);
				bureaucrat.executeForm(*form);
				delete form;
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

		{
			try
			{
				Bureaucrat bureaucrat("me", std::atoi(argv[1]));
				Form *form = new PresidentialPardonForm("Bruce Wayne");
				std::cout << bureaucrat << '\n' << *form << '\n';
				bureaucrat.signForm(*form);
				bureaucrat.executeForm(*form);
				delete form;
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

		{
			try
			{
				Bureaucrat bureaucrat("me", std::atoi(argv[1]));
				Form *form = new PresidentialPardonForm("Bruce Wayne");
				std::cout << bureaucrat << '\n' << *form << '\n';
				bureaucrat.executeForm(*form);
				delete form;
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
	}
	return (0);
}
