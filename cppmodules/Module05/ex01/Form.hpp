#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string m_sName;
	bool m_bIsSigned;
	const int m_nGradeRequiredToSign;
	const int m_nGradeRequiredToExecute;
public:
	Form();
	~Form();
	Form(const Form &F);
	Form& operator=(const Form &F);
	Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
	void beSigned(const Bureaucrat &B);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	
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

std::ostream& operator<<(std::ostream &out, const Form &F);
