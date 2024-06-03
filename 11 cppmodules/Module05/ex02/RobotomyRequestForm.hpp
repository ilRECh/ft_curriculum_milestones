#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm& operator=(const RobotomyRequestForm &R);
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &S);
	RobotomyRequestForm(std::string target);
	virtual void action() const;
};
