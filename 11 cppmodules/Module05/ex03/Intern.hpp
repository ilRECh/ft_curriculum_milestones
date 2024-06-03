#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

public:
	Intern();
	~Intern();
	Intern(const Intern &I);
	Intern& operator=(const Intern &I);
	Form* makeForm(std::string formName, std::string target);

	class WrongFormNameException
	{
	private:

	public:
		const std::string m_sMessage;
		WrongFormNameException(std::string const &message);
		~WrongFormNameException();
	};
};
