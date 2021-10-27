#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor called! (MateriaSource)" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called! (MateriaSource)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &M)
{
	std::cout << "Copy constructor called! (MateriaSource)" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &M)
{
	if (this == &M)
		return (*this);
	
	return (*this);
}
