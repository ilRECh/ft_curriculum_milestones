#include "Fixed.hpp"

Fixed::Fixed():	m_nValue(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &f):	m_nValue(f.m_nValue)
{
}

Fixed& Fixed::operator=(const Fixed &f)
{
	if (this == &f)
        return (*this);
	m_nValue = f.m_nValue;
	return (*this);
}

Fixed::Fixed(const int n):	m_nValue(0)
{
	if (!n)
		return ;

	m_nValue |= ((n < 0) ? (1 << 31) : (0)) | (((n < 0) ? (n * -1) : (n)) << m_nFraction);//((n << (m_nFraction + 1)) >> 1);
}

Fixed::Fixed(const float n):	m_nValue(0)
{
	if (!n)
		return ;

	m_nValue |= (((*(unsigned int*)&n >> 31) & 1) << 31)
		| ((((int)n < 0) ? ((int)n * -1) : ((int)n)) << m_nFraction);
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
				| ((rawBits << 9) >> (32 - (m_nFraction + exponent)));
		}
	}
}

int	Fixed::getRawBits( void ) const
{
	return (m_nValue);
}

void	Fixed::setRawBits( int const raw )
{
	m_nValue = raw;
}

float	Fixed::toFloat( void ) const
{
	float			sign = 1.0f;
	float			integer = (*(unsigned int *)&m_nValue << 1) >> (m_nFraction + 1);
	float			decimal = 0.0f;
	unsigned int	tmp_dec = m_nValue & ~(0xFFFFFFFF << m_nFraction);
	int				i = m_nFraction - 1;

	*((unsigned int *)&sign) |= ((m_nValue >> 31) & 1) << 31;
	for (; i >= 0; --i)
	{
		if (tmp_dec & (1 << i))
			break ;
	}
	if (i < 0)
	{
		decimal = 0.0f;
	}
	else
	{
		tmp_dec ^= 1 << i; 
		*((unsigned int *)&decimal) |= (((i - m_nFraction) + 127) << 23) | (tmp_dec << (23 - i));
	}
	return (sign * integer + sign * decimal);
}

int	Fixed::toInt( void ) const 
{
	return (((*(unsigned int *)&m_nValue << 1) >> (m_nFraction + 1)) * (((m_nValue >> 31) & 1) ? (-1) : (1)));
}

bool Fixed::operator>(const Fixed &A) const
{
	return (toFloat() > A.toFloat());
}

bool Fixed::operator<(const Fixed &A) const
{
	return (toFloat() < A.toFloat());
}

bool Fixed::operator>=(const Fixed &A) const
{
	return (toFloat() >= A.toFloat());
}

bool Fixed::operator<=(const Fixed &A) const
{
	return (toFloat() <= A.toFloat());
}

bool Fixed::operator==(const Fixed &A) const
{
	return (toFloat() == A.toFloat());
}

bool Fixed::operator!=(const Fixed &A) const
{
	return (toFloat() != A.toFloat());
}

Fixed Fixed::operator+(const Fixed &A)
{
	return (Fixed(toFloat() + A.toFloat()));
}

Fixed Fixed::operator-(const Fixed &A)
{
	return (Fixed(toFloat() - A.toFloat()));
}

Fixed Fixed::operator*(const Fixed &A)
{
	return (Fixed(toFloat() * A.toFloat()));
}

Fixed Fixed::operator/(const Fixed &A)
{
	return (Fixed(toFloat() / A.toFloat()));
}

Fixed& Fixed::operator++()
{
	float tmp = 0.0f;
	*(unsigned int*)&tmp |= (m_nFraction * -1 + 127) << 23;
	*this = Fixed(toFloat() + tmp);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed& Fixed::operator--()
{
	float tmp = 0.0f;
	*(unsigned int*)&tmp |= (m_nFraction * -1 + 127) << 23;
	*this = Fixed(toFloat() - tmp);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

Fixed& Fixed::min(Fixed& A, Fixed& B)
{
	if (A.toFloat() <= B.toFloat())
		return (A);
	else
		return (B);
}

const Fixed& Fixed::min(const Fixed& A, const Fixed& B)
{
	if (A.toFloat() <= B.toFloat())
		return (A);
	else
		return (B);
}

Fixed& Fixed::max(Fixed &A, Fixed &B)
{
	if (A.toFloat() >= B.toFloat())
		return (A);
	else
		return (B);
}

const Fixed& Fixed::max(const Fixed& A, const Fixed& B)
{
	if (A.toFloat() >= B.toFloat())
		return (A);
	else
		return (B);
}

std::ostream& operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
