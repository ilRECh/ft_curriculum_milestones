#include "libft.h"

int32_t	ft_power(int32_t nbr, int32_t power)
{
	if (power <= 0)
		return (1);
	return (nbr * ft_power(nbr, power - 1));
}
