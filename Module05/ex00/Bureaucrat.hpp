#pragma once
#include <string>

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

	class GradeTooHighException
	{
	private:

	public:
		const std::string m_sMessage;
		GradeTooHighException(std::string const &message = "GradeTooHighException");
		~GradeTooHighException();
	};

	class GradeTooLowException
	{
	private:

	public:
		const std::string m_sMessage;
		GradeTooLowException(std::string const &message = "GradeTooLowException");
		~GradeTooLowException();
	};
};
