#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():	Form("Default RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &R):	Form(R.getName(), 72, 45)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &R)
{
	if (this == &R)
		return (*this);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):	Form(target, 72, 45)
{
}

void RobotomyRequestForm::action() const
{
	if (!getIsSigned())
	{
		std::cout << "action on " << getName() << " it's a failure" << std::endl;
		return ;
	}
	else
	{
		std::cout << getName() << " has been robotomized successfully 50% of the time" << std::endl;
	}
}
