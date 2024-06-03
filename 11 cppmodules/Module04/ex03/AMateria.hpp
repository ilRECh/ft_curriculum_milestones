#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	AMateria();
	AMateria& operator=(const AMateria &AM);
	AMateria(std::string const & type);
	std::string m_Type;
	bool m_Equiped;
public:
	AMateria(const AMateria &AM);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
	void setEquiped(bool state = false);
	bool getEquiped() const;
};
