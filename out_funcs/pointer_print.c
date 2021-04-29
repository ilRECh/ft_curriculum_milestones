#include "out_funcs.h"

static size_t	count_symbs(unsigned long nbr, int base)
{
	size_t	counter;

	counter = 1;
	while (nbr > base)
	{
		counter++;
		nbr /= base;
	}
	return (counter);
}

void	pointer_print(void *ptr, int *total, t_specifier *specifier)
{
	uint8_t	symbs_amount;

	if (!ptr)
	{
		str_print("(null)", total, specifier);
		return ;
	}
	write(1, "0x", 2);
	symbs_amount = count_symbs((unsigned long)ptr, 16);
	if (specifier->precision > symbs_amount)
	{
		fill_with('0', specifier->precision - symbs_amount);
		*total += specifier->precision + 2;
	}
	else
		*total += symbs_amount + 2;
	ft_putnbr_base((unsigned long)ptr, 16, "0123456789abcdef");
}
