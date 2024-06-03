#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string Name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &D);
	DiamondTrap& operator=(const DiamondTrap &D);
	DiamondTrap(std::string sName);
	void shit(void);
};


