#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	Animal(std::string sType);
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &A);
	Animal& operator=(const Animal &A);
	const std::string getType() const;
	virtual void makeSound() const;
};
