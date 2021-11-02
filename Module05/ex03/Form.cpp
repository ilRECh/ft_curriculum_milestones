#include "Form.hpp"

Form::Form():	m_sName(),
				m_bIsSigned(false),
				m_nGradeRequiredToSign(150),
				m_nGradeRequiredToExecute(150)
{
}

Form::~Form()
{
}

Form::Form(const Form &F):	m_sName(F.m_sName),
							m_bIsSigned(F.m_bIsSigned),
							m_nGradeRequiredToSign(F.m_nGradeRequiredToSign),
							m_nGradeRequiredToExecute(F.m_nGradeRequiredToExecute)
{
}

Form& Form::operator=(const Form &F)
{
	if (this == &F)
		return (*this);
	m_bIsSigned = F.m_bIsSigned;
	return (*this);
}

Form::Form(	std::string name,
			int gradeRequiredToSign,
			int gradeRequiredToExecute):	m_sName(name),
											m_bIsSigned(false),
											m_nGradeRequiredToSign(gradeRequiredToSign),
											m_nGradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1)
		throw GradeTooHighException(gradeRequiredToSign);
	else if (gradeRequiredToSign > 150)
		throw GradeTooLowException(gradeRequiredToSign);
	else if (gradeRequiredToExecute < 1)
		throw GradeTooHighException(gradeRequiredToExecute);
	else if (gradeRequiredToExecute > 150)
		throw GradeTooLowException(gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > m_nGradeRequiredToSign)
		throw GradeTooLowException(B.getGrade());
	m_bIsSigned = true;
}

std::string Form::getName() const
{
	return (m_sName);
}

bool Form::getIsSigned() const
{
	return (m_bIsSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (m_nGradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (m_nGradeRequiredToExecute);
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeRequiredToExecute())
	{
		std::cout << "action on " << m_sName << " with " << executor.getName() << " it's a failure ";
		throw GradeTooLowException(executor.getGrade());
	}
	if (!m_bIsSigned)
	{
		std::cout << "action on " << m_sName << " with " << executor.getName() << " it's a failure" << std::endl;
		throw FormIsNotSignedException();
	}
	action();
}

Form::GradeTooHighException::GradeTooHighException(int grade, std::string const &message):
m_sMessage(message),
m_nGrade(grade)
{
}

Form::GradeTooHighException::~GradeTooHighException()
{
}

Form::GradeTooLowException::GradeTooLowException(int grade, std::string const &message):
m_sMessage(message),
m_nGrade(grade)
{
}

Form::GradeTooLowException::~GradeTooLowException()
{
}

Form::FormIsNotSignedException::FormIsNotSignedException(std::string const &message):
m_sMessage(message)
{
}

Form::FormIsNotSignedException::~FormIsNotSignedException()
{
}

std::ostream& operator<<(std::ostream &out, const Form &F)
{
	out <<	"Form: " <<
			F.getName() << ", " <<
			(F.getIsSigned() ? ("is signed") : ("is not signed")) << ", " <<
			"with required grade to sign: " << F.getGradeRequiredToSign() << ", " <<
			"and required grade to execute: " << F.getGradeRequiredToExecute();
	return (out);
}
