#include "Weapon.hpp"

Weapon::Weapon(std::string sType):	type(sType)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string sType)
{
	type = sType;
}

const std::string	&Weapon::getType()
{
	return (type);
}
