#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called! (WrongAnimal)" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called! (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &A):	type(A.type)
{
	std::cout << "Copy constructor called! (WrongAnimal)" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &A)
{
	if (this == &A)
		return (*this);
	type = A.type;
	return (*this);
}

WrongAnimal::WrongAnimal(std::string sType):	type(sType)
{
	std::cout << "Constructor with a name called! (WrongAnimal)" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "And the lone silence answered..." << std::endl;
}
