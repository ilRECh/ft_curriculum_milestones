#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	HumanB();
	std::string	m_sName;
	Weapon	*m_Weapon;
public:
	HumanB(std::string sName);
	~HumanB();
	void	setWeapon(Weapon &weapon);
	void	attack();
};
