#include "HumanA.hpp"

HumanA::HumanA(std::string sName, Weapon &weapon):	m_sName(sName),
													m_Weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout	<< m_sName << " attack with his  "
				<< m_Weapon.getType() << std::endl;
}
