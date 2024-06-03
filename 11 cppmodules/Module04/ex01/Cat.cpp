#include "Cat.hpp"

Cat::Cat():	Animal("Cat"), m_Brain(new Brain())
{
	std::cout << "Default constructor called! (Cat)" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called! (Cat)" << std::endl;
	delete m_Brain;
}

Cat::Cat(const Cat &C):	Animal(C.type), m_Brain(new Brain(*C.m_Brain))
{
	std::cout << "Copy constructor called! (Cat)" << std::endl;
}

Cat& Cat::operator=(const Cat &C)
{
	if (this == &C)
		return (*this);
	type = C.type;
	m_Brain = new Brain(*C.m_Brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "The Cat says: Meeeeeooow!" << std::endl;
}

void Cat::getBrainAddress() const
{
	std::cout << m_Brain << std::endl;
}
