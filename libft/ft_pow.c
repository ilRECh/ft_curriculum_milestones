#include "libft.h"

unsigned long	ft_pow(int n, uint8_t pow)
{
	if (!pow)
		return (1);
	return (n * ft_pow(n, pow - 1));
}