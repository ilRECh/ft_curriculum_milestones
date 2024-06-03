#include <stdlib.h>
#include <limits>
#include "PhoneBook.hpp"

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
}

void	PhoneBook::Search()
{
	int	nTmpIndex = 0;

	std::cout	<< "_____________________________________________\n"
				<< "|" << "   indx   " << "|"
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
		std::cout << "|\n---------------------------------------------\n" << std::endl;
	}
	if (m_nSize > 0)
	{
		while (true)
		{
			std::cout << "Enter an index of the desired contact: ";
			if (!(std::cin >> nTmpIndex) || !(nTmpIndex >= 1 && nTmpIndex <= m_nSize))
			{
				if (std::cin.eof())
				{
					exit(0);
				}
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Your input makes no sence, and this is relevant behavior!\n";
				continue ;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		nTmpIndex -= 1;
		std::cout	<< "The first name: " << m_aContact[nTmpIndex].getFirstName() << std::endl
					<< "The last name: " << m_aContact[nTmpIndex].getLastName() << std::endl
					<< "The nickname: " << m_aContact[nTmpIndex].getNickName() << std::endl
					<< "The phone number: " << m_aContact[nTmpIndex].getPhoneNumber() << std::endl
					<< "The darkest secret: " << m_aContact[nTmpIndex].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}

void	PhoneBook::MainLoop()
{
	std::string	sCmd;

	while (!std::cin.eof())
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, sCmd) || sCmd == "EXIT")
			break ;
		else if (sCmd == "ADD")
			Add();
		else if (sCmd == "SEARCH")
			Search();
	}
}
