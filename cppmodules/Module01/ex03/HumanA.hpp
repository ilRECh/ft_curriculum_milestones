#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	HumanA();
	std::string	m_sName;
	Weapon &m_Weapon;
public:
	HumanA(std::string sName, Weapon &weapon);
	~HumanA();
	void	attack();
};
