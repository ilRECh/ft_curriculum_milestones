#include "ScavTrap.hpp"

ScavTrap::ScavTrap():	ClapTrap()
{
	Name = "RandomChumpScavTrap";
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "Default constructor called, RandomChumpScavTrap created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, " << Name << " dissappeared!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &S):	ClapTrap()
{
	Name = S.Name;
	Hitpoints = S.Hitpoints;
	EnergyPoints = S.EnergyPoints;
	AttackDamage = S.AttackDamage;
	std::cout << "Copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &S)
{
	if (this == &S)
		return (*this);
	Name = S.Name;
	Hitpoints = S.Hitpoints;
	EnergyPoints = S.EnergyPoints;
	AttackDamage = S.AttackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	
}
