#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	Bureaucrat();
	std::string m_sName;
	int m_nGrade;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &B);
	Bureaucrat& operator=(const Bureaucrat &B);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	bool signForm(Form &F);

	class GradeTooHighException
	{
	private:

	public:
		const std::string m_sMessage;
		const int m_nGrade;
		GradeTooHighException(int grade, std::string const &message = "GradeTooHighException");
		~GradeTooHighException();
	};

	class GradeTooLowException
	{
	private:

	public:
		const std::string m_sMessage;
		const int m_nGrade;
		GradeTooLowException(int grade, std::string const &message = "GradeTooLowException");
		~GradeTooLowException();
	};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &B);
