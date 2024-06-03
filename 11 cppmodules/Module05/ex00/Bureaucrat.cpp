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
		throw GradeTooHighException(m_nGrade);
	else if (grade > 150)
		throw GradeTooLowException(m_nGrade);
}

std::string Bureaucrat::getName() const
{
	return (m_sName);
}

int Bureaucrat::getGrade() const
{
	return (m_nGrade);
}

void Bureaucrat::incrementGrade()
{
	if (m_nGrade == 1)
		throw GradeTooHighException(m_nGrade);
	m_nGrade--;
}

void Bureaucrat::decrementGrade()
{
	if (m_nGrade == 150)
		throw GradeTooLowException(m_nGrade);
	m_nGrade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade, std::string const &message):
m_sMessage(message),
m_nGrade(grade)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade, std::string const &message):
m_sMessage(message),
m_nGrade(grade)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &B)
{
	out << B.getName() << ", bureaucrat grade " << B.getGrade();
	return (out);
}
