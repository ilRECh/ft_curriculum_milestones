#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
protected:
	ClapTrap(	int Hitpoints,
				int EnergyPoints,
				int AttackDamage,
				std::string sName = "RandomChump");
	std::string Name;
	int	Hitpoints;
	int EnergyPoints;
	int AttackDamage;
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &C);
	ClapTrap& operator=(const ClapTrap& C);
	ClapTrap(std::string sName);
	std::string GetName();
	int GetHP();
	int GetEP();
	int GetAD();
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
