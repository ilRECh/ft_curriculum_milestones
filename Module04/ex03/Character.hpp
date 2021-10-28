#pragma once
#include <string>
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
private:
	std::string m_sName;
	AMateria *m_Inventory[4];
public:
	Character();
	~Character();
	Character(const Character &C);
	Character& operator=(const Character &C);
	Character(std::string name);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};
