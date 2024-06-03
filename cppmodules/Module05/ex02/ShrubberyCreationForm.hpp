#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &S);
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &S);
	ShrubberyCreationForm(std::string target);
	virtual void action() const;
};
