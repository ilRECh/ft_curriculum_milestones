#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zmbptr = newZombie("Anton");
	randomChump("Egor");
	zmbptr->announce();
	delete zmbptr;
	return (0);
}
