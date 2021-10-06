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
	std::cout << "Enter a first name: ";
	std::cin >> m_sFirstName;
}

const std::string	Contact::getFirstName() const
{
	return (m_sFirstName);
}

void	Contact::setLastName()
{
	std::cout << "Enter a last name: ";
	std::cin >> m_sLastName;
}

const std::string	Contact::getLastName() const
{
	return (m_sLastName);
}

void	Contact::setNickName()
{
	std::cout << "Enter a nickname: ";
	std::cin >> m_sNickName;
}

const std::string	Contact::getNickName() const
{
	return (m_sNickName);
}

void	Contact::setPhoneNumber()
{
	std::cout << "Enter a phone number: ";
	std::cin >> m_sPhoneNumber;
}

const std::string	Contact::getPhoneNumber() const
{
	return (m_sPhoneNumber);
}

void	Contact::setDarkestSecret()
{
	std::cout << "Enter a darkest secret: ";
	std::cin >> m_sDarkestSecret;
}

const std::string	Contact::getDarkestSecret() const
{
	return (m_sDarkestSecret);
}
