#include "libft.h"

int32_t	ft_power(int32_t nbr, uint8_t power)
{
	if (!power)
		return (1);
	return (nbr * ft_power(nbr, power - 1));
}
