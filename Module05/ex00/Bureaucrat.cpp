#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():	m_sName(),
							m_nGrade()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &B):	m_sName(B.m_sName),
												m_nGrade(B.m_nGrade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &B)
{
	if (this == &B)
		return (*this);
	m_sName = B.m_sName;
	m_nGrade = B.m_nGrade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade):	m_sName(name),
														m_nGrade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return (m_sName);
}

int Bureaucrat::getGrade() const
{
	return (m_nGrade);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &message):
m_sMessage(message)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &message):
m_sMessage(message)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{
}
