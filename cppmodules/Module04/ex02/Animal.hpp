#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	Animal();
	Animal(const Animal &A);
	Animal(std::string sType);
	Animal& operator=(const Animal &A);
	std::string type;
public:
	virtual ~Animal();
	const std::string getType() const;
	virtual void makeSound() const = 0;
	virtual void getBrainAddress() const = 0;
};
