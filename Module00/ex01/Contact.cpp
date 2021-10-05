#include "Contact.hpp"

Contact::Contact():	m_sFirstName(), m_sLastName(),
					m_sPhoneNumber(), m_sDarkestSecret()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string &sFirstName)
{
	m_sFirstName = sFirstName;
}

void	Contact::getFirstName()
{
	std::cout << m_sFirstName << std::endl;
}

void	Contact::setLastName(std::string &sLastName)
{
	m_sLastName = sLastName;
}

void	Contact::getLastName()
{
	std::cout << m_sLastName << std::endl;
}

void	Contact::setPhoneNumber()
{
	char	tmp;

	
}

void	Contact::getPhoneNumber()
{
	std::cout << m_sPhoneNumber << std::endl;
}

void	Contact::setDarkestSecret(std::string &sDarkestSecret)
{
	m_sDarkestSecret = sDarkestSecret;
}

void	Contact::getDarkestSecret()
{
	std::cout << m_sDarkestSecret << std::endl;
}
