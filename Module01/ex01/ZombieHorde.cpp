#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*aZombie;

	if (!(N > 1))
		return (NULL);
	aZombie = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		aZombie[i].SetName(name);
	}
	return (aZombie);
}