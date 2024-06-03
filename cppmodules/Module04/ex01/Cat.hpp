#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *m_Brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &C);
	Cat& operator=(const Cat &C);
	virtual void makeSound() const;
	virtual void getBrainAddress() const;
};
