#pragma once
#include <string>

class Bureaucrat
{
private:
	std::string m_sName;
	int grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &B);
	Bureaucrat& operator=(const Bureaucrat &B);
};
