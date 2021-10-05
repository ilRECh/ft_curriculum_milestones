#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string	m_sFirstName;
	std::string	m_sLastName;
	std::string	m_sPhoneNumber;
	std::string	m_sDarkestSecret;
public:
	Contact();
	~Contact();
	void	setFirstName();
	void	getFirstName();
	void	setLastName();
	void	getLastName();
	void	setPhoneNumber();
	void	getPhoneNumber();
	void	setDarkestSecret();
	void	getDarkestSecret();
};
