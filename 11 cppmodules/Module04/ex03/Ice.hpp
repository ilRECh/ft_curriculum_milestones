#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	~Ice();
	Ice(const Ice &I);
	Ice& operator=(const Ice &I);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
