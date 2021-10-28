#include "AMateria.hpp"

AMateria::AMateria():	m_Type("Default"), m_Equiped(false)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &AM):	m_Type(AM.m_Type), m_Equiped(AM.m_Equiped)
{
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
