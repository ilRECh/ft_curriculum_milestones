#include "WrongCat.hpp"

WrongCat::WrongCat():	WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called! (WrongCat)" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called! (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &C):	WrongAnimal(C.type)
{
	std::cout << "Copy constructor called! (WrongCat)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &C)
{
	if (this == &C)
		return (*this);
	type = C.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "The WrongCat says: Meeeeeooow!" << std::endl;
}
