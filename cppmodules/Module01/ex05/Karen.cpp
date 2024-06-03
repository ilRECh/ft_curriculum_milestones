#include "Karen.hpp"

static int	HashIt(std::string &sTmp)
{
	int	lcl_nLength = sTmp.length();
	int	i = 0;
	int	sum = 0;

	for (; i < lcl_nLength; ++i)
	{
		sum += sTmp[i] * i;
	}
	return (sum + lcl_nLength);
}

Karen::Karen()
{
}

Karen::~Karen()
{
}

void	Karen::debug( void )
{
	std::cout	<< "I love to get extra bacon "
				"for my 7XL-double-cheese-triple-pickle-special-ketchup"
				" burger. I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout	<< "I cannot believe adding extra"
				" bacon cost more money. You don’t put enough!"
				" If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void )
{
	std::cout	<< "I think I deserve to have some extra"
				" bacon for free. I’ve been coming here for years"
				" and you just started working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout	<< "This is unacceptable,"
				"I want to speak to the manager now." << std::endl;
}

void	Karen::complain( std::string level )
{
	void	(Karen::*f[])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	switch (HashIt(level))
	{
		case 745:
			(this->*f[0])();
			break ;
		case 459:
			(this->*f[1])();
			break ;
		case 1578:
			(this->*f[2])();
			break ;
		case 816:
			(this->*f[3])();
			break ;
		default:
			break;
	}
}
