#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm& operator=(const PresidentialPardonForm &P);
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &P);
	PresidentialPardonForm(std::string target);
	virtual void action() const;
};
