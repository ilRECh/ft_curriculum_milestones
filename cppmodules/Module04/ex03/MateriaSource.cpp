#include "MateriaSource.hpp"

MateriaSource::MateriaSource():	m_Materias()
{
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		delete m_Materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &M):	m_Materias()
{
	for (int i = 0; i < 4; ++i)
	{
		m_Materias[i] = M.m_Materias[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &M)
{
	if (this == &M)
		return (*this);
	for (int i = 0; i < 4; ++i)
	{
		delete m_Materias[i];
		m_Materias[i] = M.m_Materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* a)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!m_Materias[i])
		{
			m_Materias[i] = a;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_Materias[i] && (m_Materias[i]->getType() == type))
			return (m_Materias[i]->clone());
	}
	return (NULL);
}
