#include "libft.h"

size_t	count_symbs(uint64_t nbr, uint8_t base)
{
	size_t	counter;

	counter = 1;
	while (nbr >= base)
	{
		counter++;
		nbr /= base;
	}
	return (counter);
}
