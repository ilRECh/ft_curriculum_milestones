#include "Fixed.hpp"

// typedef union u_Fixed
// {
// 	int	Value;
// 	struct __attribute__ ((packed))
// 	{
// 		int integer:	24;
// 		int	decimal:	8;
// 	}	bits;
// }	t_Fixed;


Fixed::Fixed():	m_nValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f):	m_nValue(f.m_nValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &f)
        return (*this);
	m_nValue = f.m_nValue;
	return (*this);
}

Fixed::Fixed(const int n):	m_nValue(0)
{
	if (!n)
		return ;

	m_nValue |= (((n >> 31) & 1) << 31) | ((n << (m_nFraction + 1)) >> 1);
}

Fixed::Fixed(const float n):	m_nValue(0)
{
	if (!n)
		return ;

	m_nValue |= ((((int)n >> 31) & 1) << 31)
		| (((int)n << (m_nFraction + 1)) >> 1);
	unsigned int rawBits = *(unsigned int *)&n;
	char exponent = ((rawBits << 1) >> 24) - 127;
	if (exponent >= (m_nFraction * -1) && exponent <= 22)
	{
		if (exponent > 0)
		{
			m_nValue |= ((rawBits << (9 + exponent)) >> (32 - m_nFraction));
		}
		else
		{
			m_nValue |= (1 << (m_nFraction + exponent))
				| ((rawBits << 9) >> (32 - m_nFraction + exponent));
		}
	}
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_nValue);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	m_nValue = raw;
}
