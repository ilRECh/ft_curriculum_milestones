#include "AMateria.hpp"

AMateria::AMateria():	m_Type("Default"), m_Equiped(false)
{
	std::cout << "Default constructor called! (AMateria)" << std::endl;
}

AMateria::AMateria()
{
	std::cout << "Destructor called! (AMateria)" << std::endl;
}

AMateria::AMateria(const AMateria &AM):	m_Type(AM.m_Type), m_Equiped(AM.m_Equiped)
{
	std::cout << "Copy constructor called! (AMateria)" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &AM)
{
	if (this == &AM)
		return (*this);
	m_Type = AM.m_Type;
	m_Equiped = AM.m_Equiped;
	return (*this);
}

AMateria::AMateria(std::string const & type):	m_Type(type), m_Equiped(false)
{
	std::cout << "Constructor with a name called! (AMateria)" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (m_Type);
}

void AMateria::setEquiped(bool state)
{
	m_Equiped = state;
}

bool AMateria::getEquiped() const
{
	return (m_Equiped);
}
