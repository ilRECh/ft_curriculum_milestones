#include "out_funcs.h"

void	u_digit_print(uint32_t nbr, int *total, t_specifier *specifier)
{
	uint8_t	symbs_amount;

	symbs_amount = count_symbs(nbr, 10);
	if (specifier->width < symbs_amount)
		specifier->width = symbs_amount;
	if (specifier->flags & ZERO_FLAG && specifier->precision < 0)
		specifier->precision = specifier->width;
	else if (specifier->precision < symbs_amount && specifier->precision)
		specifier->precision = symbs_amount;
	if (specifier->width < specifier->precision)
		specifier->width = specifier->precision;
	if (!(specifier->flags & MINUS_FLAG) && specifier->width > symbs_amount)
		fill_with(' ', specifier->width - specifier->precision);
	fill_with('0', (specifier->precision > symbs_amount)
		* (specifier->precision - symbs_amount));
	if (specifier->precision || nbr)
		ft_putnbr_base(nbr, 10, "0123456789");
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', specifier->width - specifier->precision);
	*total += specifier->width - !(specifier->precision || nbr);
}
