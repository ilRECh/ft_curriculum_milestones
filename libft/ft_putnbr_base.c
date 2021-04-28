#include "libft.h"

void    ft_putnbr_base(unsigned long nbr, uint8_t base, char *symbs)
{
	if (nbr < base)
		write(1, symbs + nbr, 1);
	else
	{
		ft_putnbr_base(nbr / base, base, symbs);
		ft_putnbr_base(nbr % base, base, symbs);
	}
}
