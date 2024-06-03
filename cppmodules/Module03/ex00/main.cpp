#include "ClapTrap.hpp"

int	main()
{
	ClapTrap A("first");
	ClapTrap B("second");

	A.attack(B.GetName());
	B.takeDamage(A.GetAD());
	return (0);
}
