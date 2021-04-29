#include "out_funcs.h"

void	digit_print(int nbr, int *total, t_specifier *specifier)
{
	uint8_t		symbs_amount;
	uint32_t	u_nbr;

	u_nbr = ft_abs((uint32_t)nbr);
	symbs_amount = count_symbs(u_nbr, 10);
	if (specifier->width < symbs_amount + (nbr < 0))
		specifier->width = symbs_amount + (nbr < 0);
	if (specifier->flags & ZERO_FLAG && specifier->precision < 0)
		specifier->precision = specifier->width;
	else if (specifier->precision < symbs_amount)
		specifier->precision = symbs_amount;
	if (specifier->width < specifier->precision + (nbr < 0))
		specifier->width = specifier->precision + (nbr < 0);
	if (!(specifier->flags & MINUS_FLAG))
		fill_with(' ',specifier->width - specifier->precision - (nbr < 0));
	if (nbr < 0 && write(1, "-", 1))
		*total += 1;
	fill_with('0', specifier->precision - symbs_amount);
	ft_putnbr_base(u_nbr, 10, "0123456789");
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', specifier->width - specifier->precision - (nbr < 0));
	*total += specifier->width - (nbr < 0);
}
