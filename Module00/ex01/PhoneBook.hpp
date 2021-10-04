#pragma once
#include <string>
#include <Contact.hpp>

class PhoneBook
{
private:
	Contact	*aContact[8];
public:
	PhoneBook();
	~PhoneBook();
	void	Add(Contact &Contact);
	void	Search();
	
};


