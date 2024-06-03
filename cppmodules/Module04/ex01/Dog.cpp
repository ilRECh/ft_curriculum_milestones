#include "Dog.hpp"

Dog::Dog():	Animal("Dog"), m_Brain(new Brain())
{
	std::cout << "Default constructor called! (Dog)" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called! (Dog)" << std::endl;
	delete m_Brain;
}

Dog::Dog(const Dog &D):	Animal(D.type), m_Brain(new Brain(*D.m_Brain))
{
	std::cout << "Copy constructor called! (Dog)" << std::endl;
}

Dog& Dog::operator=(const Dog &D)
{
	if (this == &D)
		return (*this);
	type = D.type;
	m_Brain = new Brain(*D.m_Brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "The Dog says: Woof-woof!" << std::endl;
}

void Dog::getBrainAddress() const
{
	std::cout << m_Brain << std::endl;
}
