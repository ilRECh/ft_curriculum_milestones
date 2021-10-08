#pragma once
#include <string>

class Weapon
{
private:
	Weapon();
	std::string	type;
public:
	Weapon(std::string sType);
	~Weapon();
	const std::string	&getType();
	void	setType(std::string sType);
};
