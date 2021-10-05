#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook():	m_nSize(0), m_nCurrentFreePosition(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Add()
{
	m_aContact[m_nCurrentFreePosition].setFirstName();
	m_aContact[m_nCurrentFreePosition].setLastName();
	m_aContact[m_nCurrentFreePosition].setPhoneNumber();
	m_aContact[m_nCurrentFreePosition].setDarkestSecret();
	if (m_nCurrentFreePosition < 7)
		m_nCurrentFreePosition += 1;
	else
		m_nCurrentFreePosition = 0;
	if (m_nSize < 8)
	{
		m_nSize += 1;
	}
}

void	PhoneBook::Search()
{

}

void	PhoneBook::MainLoop()
{
	std::string	sCmd;

	while (true)
	{
		std::getline(std::cin, sCmd);
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (sCmd == "EXIT")
			break ;
		else if (sCmd == "ADD")
			Add();
		else if (sCmd == "SEARCH")
			Search();
	}
}

