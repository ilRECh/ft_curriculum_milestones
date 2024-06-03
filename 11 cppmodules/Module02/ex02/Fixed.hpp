#pragma once
#include <iostream>

class Fixed
{
private:
	int	m_nValue;
	static const int	m_nFraction = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed(const int n);
	Fixed(const float n);
	Fixed& operator=(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int	toInt( void ) const;
	bool operator>(const Fixed &A) const;
	bool operator<(const Fixed &A) const;
	bool operator>=(const Fixed &A) const;
	bool operator<=(const Fixed &A) const;
	bool operator==(const Fixed &A) const;
	bool operator!=(const Fixed &A) const;
	Fixed operator+(const Fixed &A);
	Fixed operator-(const Fixed &A);
	Fixed operator*(const Fixed &A);
	Fixed operator/(const Fixed &A);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& A, Fixed& B);
	static const Fixed& min(const Fixed& A, const Fixed& B);
	static Fixed& max(Fixed &A, Fixed &B);
	static const Fixed& max(const Fixed& A, const Fixed& B);
};
	
std::ostream& operator<<(std::ostream &out, const Fixed &f);
