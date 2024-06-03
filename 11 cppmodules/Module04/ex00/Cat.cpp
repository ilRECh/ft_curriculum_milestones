#include "Cat.hpp"

Cat::Cat():	Animal("Cat")
{
	std::cout << "Default constructor called! (Cat)" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called! (Cat)" << std::endl;
}

Cat::Cat(const Cat &C):	Animal(C.type)
{
	std::cout << "Copy constructor called! (Cat)" << std::endl;
}

Cat& Cat::operator=(const Cat &C)
{
	if (this == &C)
		return (*this);
	type = C.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "The Cat says: Meeeeeooow!" << std::endl;
}
