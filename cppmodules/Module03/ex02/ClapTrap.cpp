#include "ClapTrap.hpp"

ClapTrap::ClapTrap():	Name("RandomChumpClapTrap"),
						Hitpoints(10),
						EnergyPoints(10),
						AttackDamage(0)
{
	std::cout << "Default constructor called, RandomChump created!(ClapTrap)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called, " << Name << " vanished! (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &C):	Name(C.Name),
										Hitpoints(C.Hitpoints),
										EnergyPoints(C.EnergyPoints),
										AttackDamage(C.AttackDamage)
{
	std::cout << "Copy constructor called! (ClapTrap)" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& C)
{
	if (this == &C)
		return (*this);
	Name = C.Name;
	Hitpoints = C.Hitpoints;
	EnergyPoints = C.EnergyPoints;
	AttackDamage = C.AttackDamage;
	return (*this);
}

ClapTrap::ClapTrap(std::string sName):	Name(sName),
										Hitpoints(10),
										EnergyPoints(10),
										AttackDamage(0)
{
	std::cout << "Constructor with a name called, " << Name << " created! (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(	int nHitpoints,
					int nEnergyPoints,
					int nAttackDamage,
					std::string sName):	Name(sName),
										Hitpoints(nHitpoints),
										EnergyPoints(nEnergyPoints),
										AttackDamage(nAttackDamage)
{
	std::cout << "Protected constructor called, " << Name << " created! (ClapTrap)" << std::endl;
}
				

std::string ClapTrap::GetName()
{
	return (Name);
}

int ClapTrap::GetHP()
{
	return (Hitpoints);
}

int ClapTrap::GetEP()
{
	return (EnergyPoints);
}

int ClapTrap::GetAD()
{
	return (AttackDamage);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout <<	"ClapTrap " <<
					Name <<
					" attack " <<
					target << 
					", causing " <<
					AttackDamage <<
					" points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hitpoints <= 0)
	{
		std::cout <<	"ClapTrap " << Name <<
						" is already dead!" << std::endl;
		return ;
	}
	Hitpoints -= amount;
	if (Hitpoints <= 0)
	{
		std::cout <<	"ClapTrap " <<
						Name <<
						" damaged by " <<
						amount << 
						" points! " <<
						"And now he is dead." << std::endl;
	}
	else
	{
		std::cout <<	"ClapTrap " <<
				Name <<
				" damaged by " <<
				amount << 
				" points! " << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hitpoints <= 0)
	{
		std::cout <<	"ClapTrap " << Name <<
						" is dead! No repaires done." << std::endl;
		return ;
	}
	std::cout <<	"ClapTrap " <<
					Name <<
					" repaired by " <<
					amount << 
					" points! " << std::endl;
	Hitpoints += amount;
}
