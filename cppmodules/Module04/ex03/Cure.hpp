#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	~Cure();
	Cure(const Cure &C);
	Cure& operator=(const Cure &C);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
