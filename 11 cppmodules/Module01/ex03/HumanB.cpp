#include "HumanB.hpp"

HumanB::HumanB(std::string sName):	m_sName(sName), m_Weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	m_Weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout	<< m_sName << " attack with his  "
				<< m_Weapon->getType() << std::endl;
}
