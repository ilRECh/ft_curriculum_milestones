#include "Character.hpp"

Character::Character():	m_sName("Nobody"), m_Inventory()
{
	std::cout << "Default constructor called! (Character)" << std::endl;
}

Character::~Character()
{
	std::cout << "Destructor called! (Character)" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete m_Inventory[i];
	}
}

Character::Character(const Character &C):	m_sName(C.m_sName), m_Inventory()
{
	std::cout << "Copy constructor called! (Character)" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		m_Inventory[i] = C.m_Inventory[i]->clone();
	}
}

Character& Character::operator=(const Character &C)
{
	if (this == &C)
		return (*this);
	m_sName = C.m_sName;
	for (int i = 0; i < 4; ++i)
	{
		delete m_Inventory[i];
		m_Inventory[i] = C.m_Inventory[i]->clone();
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (m_sName);
}


void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
