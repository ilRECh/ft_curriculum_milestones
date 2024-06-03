#include "Zombie.hpp"

Zombie::Zombie(std::string name):	m_sName(name)
{
}

Zombie::~Zombie()
{
	std::cout << m_sName << " is dead. And now forever!" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << m_sName << " BraiiiiiiinnnzzzZ..." << std::endl;
}
