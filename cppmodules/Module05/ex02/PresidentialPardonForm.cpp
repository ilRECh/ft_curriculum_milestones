#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():	Form("Default PresidentialPardonForm", 145, 137)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &P):	Form(P.getName(), 25, 5)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &P)
{
	if (this == &P)
		return (*this);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):	Form(target, 25, 5)
{
}

void PresidentialPardonForm::action() const
{
	std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
