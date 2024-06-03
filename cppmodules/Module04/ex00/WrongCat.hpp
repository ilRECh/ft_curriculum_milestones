#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &C);
	WrongCat& operator=(const WrongCat &C);
	void makeSound() const;
};
