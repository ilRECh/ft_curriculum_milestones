#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called! (Animal)" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called! (Animal)" << std::endl;
}

Animal::Animal(const Animal &A):	type(A.type)
{
	std::cout << "Copy constructor called! (Animal)" << std::endl;
}

Animal& Animal::operator=(const Animal &A)
{
	if (this == &A)
		return (*this);
	type = A.type;
	return (*this);
}

Animal::Animal(std::string sType):	type(sType)
{
	std::cout << "Constructor with a name called! (Animal)" << std::endl;
}

const std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "And the lone silence answered..." << std::endl;
}
