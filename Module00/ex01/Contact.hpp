#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string	m_sFirstName;
	std::string	m_sLastName;
	std::string	m_sNickName;
	std::string	m_sPhoneNumber;
	std::string	m_sDarkestSecret;
public:
	Contact();
	~Contact();
	void	setFirstName();
	const std::string	getFirstName() const ;
	void	setLastName();
	const std::string	getLastName() const ;
	void	setNickName();
	const std::string	getNickName() const;
	void	setPhoneNumber();
	const std::string	getPhoneNumber() const ;
	void	setDarkestSecret();
	const std::string	getDarkestSecret() const ;
};
