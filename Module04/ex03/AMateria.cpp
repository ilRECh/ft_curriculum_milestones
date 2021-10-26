#include "AMateria.hpp"

AMateria::AMateria():	m_Type("Default")
{
	std::cout << "Default constructor called! (AMateria)" << std::endl;
}

AMateria::AMateria()
{
	std::cout << "Destructor called! (AMateria)" << std::endl;
}

AMateria::AMateria(const AMateria &AM):	m_Type(AM.m_Type)
{
	std::cout << "Copy constructor called! (AMateria)" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &AM)
{
	if (this == &AM)
		return (*this);
	m_Type = AM.m_Type;
	return (*this);
}

AMateria::AMateria(std::string const & type):	m_Type(type)
{
	std::cout << "Constructor with a name called! (AMateria)" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (m_Type);
}
