#include "Cure.hpp"

Cure::Cure():	AMateria("Cure")
{
	std::cout << "Default constructor called! (Cure)" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor called! (Cure)" << std::endl;
}

Cure::Cure(const Cure &C):	AMateria("Cure")
{
	std::cout << "Copy constructor called! (Cure)" << std::endl;
}

Cure& Cure::operator=(const Cure &C)
{
	if (this == &C)
		return (*this);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout <<	"* heals " << target.getName() <<
					"'s wounds *" << std::endl;
}
