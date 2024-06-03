#include "ScavTrap.hpp"

int	main()
{
	ClapTrap A("first");
	ScavTrap B("second");

	B.guardGate();
	B.attack(A.GetName());
	A.takeDamage(B.GetAD());
	A.beRepaired(100);
	return (0);
}
