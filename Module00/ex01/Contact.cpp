#include <limits>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName()
{
	while ((std::cout << "Enter a first name: ") && isspace(std::cin.peek()))
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue ;
	}
	std::cin >> m_sFirstName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string	Contact::getFirstName() const
{
	return (m_sFirstName);
}

void	Contact::setLastName()
{
	while ((std::cout << "Enter a last name: ") && isspace(std::cin.peek()))
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue ;
	}
	std::cin >> m_sLastName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string	Contact::getLastName() const
{
	return (m_sLastName);
}

void	Contact::setNickName()
{
	while ((std::cout << "Enter a nickname: ") && isspace(std::cin.peek()))
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue ;
	}
	std::cin >> m_sNickName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string	Contact::getNickName() const
{
	return (m_sNickName);
}

void	Contact::setPhoneNumber()
{
	while ((std::cout << "Enter a phone number: ") && isspace(std::cin.peek()))
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue ;
	}
	std::cin >> m_sPhoneNumber;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string	Contact::getPhoneNumber() const
{
	return (m_sPhoneNumber);
}

void	Contact::setDarkestSecret()
{
	while ((std::cout << "Enter a darkest secret: ") && isspace(std::cin.peek()))
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue ;
	}
	std::cin >> m_sDarkestSecret;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string	Contact::getDarkestSecret() const
{
	return (m_sDarkestSecret);
}
