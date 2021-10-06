#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook():	m_nCurrentFreePosition(0), m_nSize(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Add()
{
	m_aContact[m_nCurrentFreePosition].setFirstName();
	m_aContact[m_nCurrentFreePosition].setLastName();
	m_aContact[m_nCurrentFreePosition].setNickName();
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
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::Search()
{
	int	nTmpIndex;

	std::cout	<< "_____________________________________________\n"
				<< "|" << "   index  " << "|"
				<< "first name" << "|"
				<< "last  name" << "|"
				<< " nickname " << "|\n"
				<< "_____________________________________________" << std::endl;
	for (int i = 0; i < m_nSize; ++i)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		if (m_aContact[i].getFirstName().length() <= 10)
		{
			std::cout << std::setw(10) << m_aContact[i].getFirstName();
		}
		else
		{
			std::cout.write(m_aContact[i].getFirstName().c_str(), 9);
			std::cout.put('.');
		}
		std::cout << "|";
		if (m_aContact[i].getLastName().length() <= 10)
		{
			std::cout << std::setw(10) << m_aContact[i].getLastName();
		}
		else
		{
			std::cout.write(m_aContact[i].getLastName().c_str(), 9);
			std::cout.put('.');
		}
		std::cout << "|";
		if (m_aContact[i].getNickName().length() <= 10)
		{
			std::cout << std::setw(10) << m_aContact[i].getNickName();
		}
		else
		{
			std::cout.write(m_aContact[i].getNickName().c_str(), 9);
			std::cout.put('.');
		}
		std::cout << "|" << std::endl;
	}
	if (m_nSize > 0)
	{
		std::cout << "Enter an index of the desired contact: ";
		while (!(std::cin >> nTmpIndex) || !(nTmpIndex >= 1 && nTmpIndex <= 8))
		{
			std::cout << "Your input makes no sence, and this is relevant behavior!" << std::endl;
			std::cout << "Enter an index of the desired contact: ";
		}
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		nTmpIndex -= 1;
		std::cout	<< m_aContact[nTmpIndex].getFirstName() << std::endl
					<< m_aContact[nTmpIndex].getLastName() << std::endl
					<< m_aContact[nTmpIndex].getNickName() << std::endl
					<< m_aContact[nTmpIndex].getPhoneNumber() << std::endl
					<< m_aContact[nTmpIndex].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout.put('\n');
	}
}

void	PhoneBook::MainLoop()
{
	std::string	sCmd;

	while (true)
	{
		std::cout << "Enter a command: ";
		// std::getline(std::cin, sCmd);
		std::cin >> sCmd;
		if (sCmd == "EXIT")
			break ;
		else if (sCmd == "ADD")
			Add();
		else if (sCmd == "SEARCH")
			Search();
	}
}

