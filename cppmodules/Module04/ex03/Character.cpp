#include "Character.hpp"

Character::Character():	m_sName("Nobody"),
						m_Inventory()
{
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_Inventory[i];
	}
}

Character::Character(const Character &C):	m_sName(C.m_sName),
											m_Inventory()
{
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

Character::Character(std::string name):	m_sName(name)
{
}

std::string const& Character::getName() const
{
	return (m_sName);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!m_Inventory[i])
		{
			m_Inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	m_Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !m_Inventory[idx])
		return ;
	m_Inventory[idx]->use(target);
}
