#pragma once
#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	WrongAnimal(std::string sType);
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &A);
	WrongAnimal& operator=(const WrongAnimal &A);
	const std::string getType() const;
	void makeSound() const;
};
