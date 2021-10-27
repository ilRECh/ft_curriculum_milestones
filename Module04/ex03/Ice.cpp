#include "Ice.hpp"

Ice::Ice():	AMateria("ice")
{
	std::cout << "Default constructor called! (Ice)" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor called! (Ice)" << std::endl;
}

Ice::Ice(const Ice &I):	AMateria("ice")
{
	std::cout << "Copy constructor called! (Ice)" << std::endl;
}

Ice& Ice::operator=(const Ice &I)
{
	if (this == &I)
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout <<	"* shoots an ice bolt at " << target.getName() <<
					" *" << std::endl;
}
