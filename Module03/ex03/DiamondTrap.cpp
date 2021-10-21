#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():	ClapTrap(100, 50, 30, "RandomChump_clap_name"),
							ScavTrap("RandomChump"),
							FragTrap("RandomChump"),
							Name("RandomChump")
{
	std::cout << "Default constructor called, RandomChump created!(DiamondTrap)" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called, " << Name << " vanished! (DiamondTrap)" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &D):	ClapTrap(	D.Hitpoints,
															D.EnergyPoints,
															D.AttackDamage,
															D.Name + "_clap_name"),
												ScavTrap(D.Name),
												FragTrap(D.Name),
												Name(D.Name)

{
	std::cout << "Copy constructor called! (DiamondTrap)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &D)
{
	if (this == &D)
		return (*this);
	Name = D.Name;
	Hitpoints = D.Hitpoints;
	EnergyPoints = D.EnergyPoints;
	AttackDamage = D.AttackDamage;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string sName):	ClapTrap(100, 50, 30, sName + "_clap_name"),
												ScavTrap(sName),
												FragTrap(sName),
												Name(sName)
{
	std::cout << "Constructor with a name called, " << Name << " created! (DiamondTrap)" << std::endl;
}
