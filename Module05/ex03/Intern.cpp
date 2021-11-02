#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &I)
{
	(void)&I;
}

Intern& Intern::operator=(const Intern &I)
{
	if (this == &I)
		return (*this);
	return (*this);
}

Form* Intern::makeForm(std::string formName, std::string target)
{
	std::pair<std::string, Form*> pairNameForm[] =
	{
		std::make_pair("shrubbery creation", new ShrubberyCreationForm(target)),
		std::make_pair("robotomy request", new RobotomyRequestForm(target)),
		std::make_pair("presidential pardon", new PresidentialPardonForm(target))
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == pairNameForm[i].first)
		{
			for (int j = i + 1; j < 3; ++j)
			{
				delete pairNameForm[j].second;
			}
			std::cout << "Intern creates " << formName << std::endl;
			return (pairNameForm[i].second);
		}
		delete pairNameForm[i].second;
	}
	throw WrongFormNameException(formName);
	return (NULL);
}

Intern::WrongFormNameException::WrongFormNameException(std::string const &message):	m_sMessage("WrongFormNameException: " + message)
{
}

Intern::WrongFormNameException::~WrongFormNameException()
{
}
