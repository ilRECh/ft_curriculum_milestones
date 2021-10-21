#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap A("first");
	ScavTrap B("second");
	FragTrap C("third");
	DiamondTrap D("fourth");

	B.guardGate();
	B.attack(A.GetName());
	A.takeDamage(B.GetAD());
	A.beRepaired(A.GetEP());
	C.highFiveGuys();
	D.highFiveGuys();
	D.attack(C.GetName());
	C.takeDamage(D.GetAD());
	D.attack(B.GetName());
	B.takeDamage(D.GetAD());
	D.beRepaired(D.GetEP());
	return (0);
}
