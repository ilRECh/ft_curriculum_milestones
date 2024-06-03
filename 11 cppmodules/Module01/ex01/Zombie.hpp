#pragma once
#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	m_sName;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	SetName(std::string name);
	void	announce( void );
};

Zombie* zombieHorde( int N, std::string name );
