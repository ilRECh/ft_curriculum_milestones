#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():	Form("Default ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &S):	Form(S.getName(), 145, 137)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &S)
{
	if (this == &S)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):	Form(target, 145, 137)
{
}

void ShrubberyCreationForm::action() const
{
	if (!getIsSigned())
	{
		std::cout << "action on " << getName() << " cannot be done, because form is not signed" << std::endl;
		return ;
	}
	std::ofstream OFS((getName() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
	if (!OFS.fail())
	{
		OFS <<	"           {{ }{\n" <<
				"          {{}}}{{\n" <<
				"        {{}}{}}\n" <<
				"           }}}}{\n" <<
				"          {{}}}\n" <<
				"         }{{}{}}\n" <<
				"           {{}{}}\n" <<
				"         }}{{}}\n" <<
				"          {{}}{{\n" <<
				"           \\  /\n" <<
				"        .-''| |``-.\n" <<
				"       '-._/_o_\\_.-'\n" <<
				"        `._     _.'\n" <<
				"         |:Shrub:|\n" <<
				"         `._    .'\n" <<
				"            `--'" << std::endl;
	}
	else
	{
		std::cout << "action on " << getName() << " cannot be done" << std::endl;
	}
	OFS.close();
}
