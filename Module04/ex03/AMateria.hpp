#pragma once
#include <iostream>
#include <string>

class AMateria
{
protected:
	std::string m_Type;
public:
	AMateria();
	~AMateria();
	AMateria(const AMateria &AM);
	AMateria& operator=(const AMateria &AM);
	AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
