#include <stdlib.h>
#include <limits>
#include "Contact.hpp"

static std::string	GetInput(const char *sPrompt)
{
	std::string	sTmp;

	while (sTmp.empty())
	{
		std::cout << sPrompt;
		if (!std::getline(std::cin, sTmp))
		{
			exit(0);
		}
		else if (sTmp.find_first_not_of(" \t\v\r\n") == sTmp.npos)
		{
			sTmp.clear();
		}
	}
	return (sTmp);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName()
{
	m_sFirstName = ::GetInput("Enter a first name: ");
}

const std::string	Contact::getFirstName() const
{
	return (m_sFirstName);
}

void	Contact::setLastName()
{
	m_sLastName = ::GetInput("Enter a last name: ");
}

const std::string	Contact::getLastName() const
{
	return (m_sLastName);
}

void	Contact::setNickName()
{
	m_sNickName = ::GetInput("Enter a nickname: ");
}

const std::string	Contact::getNickName() const
{
	return (m_sNickName);
}

void	Contact::setPhoneNumber()
{
	m_sNickName = ::GetInput("Enter a phone number: ");
}

const std::string	Contact::getPhoneNumber() const
{
	return (m_sPhoneNumber);
}

void	Contact::setDarkestSecret()
{
	m_sDarkestSecret = ::GetInput("Enter a darkest secret: ");
}

const std::string	Contact::getDarkestSecret() const
{
	return (m_sDarkestSecret);
}
