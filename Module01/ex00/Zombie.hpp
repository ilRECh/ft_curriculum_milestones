#pragma once
#include <string>
#include <iostream>

class Zombie
{
private:
	Zombie();
	std::string	name;
public:
	Zombie(std::string name);
	~Zombie();
	void	announce( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
