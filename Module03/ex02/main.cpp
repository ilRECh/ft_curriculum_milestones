#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap A("first");
	ScavTrap B("second");
	FragTrap C("third");

	B.guardGate();
	B.attack(A.GetName());
	A.takeDamage(B.GetAD());
	A.beRepaired(100);
	C.highFiveGuys();
	return (0);
}
