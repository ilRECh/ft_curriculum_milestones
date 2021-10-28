#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *m_Materias[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &M);
	MateriaSource& operator=(const MateriaSource &M);
	virtual void learnMateria(AMateria* a);
	virtual AMateria* createMateria(std::string const & type);
};
