#include "ScavTrap.hpp"

ScavTrap::ScavTrap():	ClapTrap(100, 50, 20)
{
	std::cout << "Default constructor called, RandomChump created! (ScavTrap)" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, " << Name << " dissappeared! (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &S):	ClapTrap(S.Hitpoints, S.EnergyPoints, S.AttackDamage, S.Name)
{
	std::cout << "Copy constructor called! (ScavTrap)" << std::endl;
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

ScavTrap::ScavTrap(std::string sName):	ClapTrap(100, 50, 20, sName)
{
	std::cout << "Constructor with a name called, " << Name << " created! (ScavTrap)" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout <<	"ScavTrap " <<
					Name <<
					" attack " <<
					target << 
					", causing " <<
					AttackDamage <<
					" points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout <<	"ScavTrap " << Name <<
					" have entered the Gate keeper mode!" << std::endl;
}
