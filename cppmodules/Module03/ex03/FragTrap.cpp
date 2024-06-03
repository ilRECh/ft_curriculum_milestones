#include "FragTrap.hpp"

FragTrap::FragTrap():	ClapTrap(100, 100, 30)
{
	std::cout << "Default constructor called, RandomChump created!(FragTrap)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called, " << Name << " vanished! (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &F):	ClapTrap(	F.Hitpoints,
													F.EnergyPoints,
													F.AttackDamage,
													F.Name)
{
	std::cout << "Copy constructor called! (FragTrap)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &F)
{
	if (this == &F)
		return (*this);
	Name = F.Name;
	Hitpoints = F.Hitpoints;
	EnergyPoints = F.EnergyPoints;
	AttackDamage = F.AttackDamage;
	return (*this);
}

FragTrap::FragTrap(std::string sName):	ClapTrap(100, 100, 30, sName)
{
	std::cout << "Constructor with a name called, " << Name << " created! (FragTrap)" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "Guys! Do you know what time is it? It's HIGH FIVE TIME!!!" << std::endl;
}
