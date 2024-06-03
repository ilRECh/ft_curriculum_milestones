#include <string>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Intern someRandomIntern;
		{
			try
			{
				Bureaucrat bureaucrat("me", std::atoi(argv[1]));
				Form *form = someRandomIntern.makeForm("shrubbery creation", "home");
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
			catch(const Intern::WrongFormNameException &e)
			{
				std::cerr << e.m_sMessage << std::endl;
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
				Form *form = someRandomIntern.makeForm("robotomy request", "Mike Vazovsky");
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
			catch(const Intern::WrongFormNameException &e)
			{
				std::cerr << e.m_sMessage << std::endl;
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
				Form *form = someRandomIntern.makeForm("presidential pardon", "Bruce Wayne");
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
			catch(const Intern::WrongFormNameException &e)
			{
				std::cerr << e.m_sMessage << std::endl;
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
				Form *form = someRandomIntern.makeForm("presidental pardon", "Bruce Wayne");
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
			catch(const Intern::WrongFormNameException &e)
			{
				std::cerr << e.m_sMessage << std::endl;
			}
			catch(...)
			{
				std::cerr << "What the fun is this?" << std::endl;
			}
		}
	}
	return (0);
}
