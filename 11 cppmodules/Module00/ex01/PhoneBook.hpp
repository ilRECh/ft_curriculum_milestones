#pragma once
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	int		m_nCurrentFreePosition;
	int		m_nSize;
	Contact	m_aContact[8];
public:
	PhoneBook();
	~PhoneBook();
	void	Add();
	void	Search();
	void	MainLoop();
};
