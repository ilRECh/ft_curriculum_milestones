#include "out_funcs.h"

static void	put_flag_symbol(int64_t const *nbr,
							int *total, t_specifier *specifier)
{
	char	c;

	c = '+' * ((specifier->flags & PLUS_FLAG) != 0) * (*nbr >= 0)
		+ ' ' * ((specifier->flags & SPACE_FLAG) != 0
			&& !(specifier->flags & PLUS_FLAG)) * (*nbr >= 0)
		+ '-' * (*nbr < 0);
	if (c)
	{
		write(1, &c, 1);
		*total += 1;
	}
}

void	digit_print(int64_t nbr, int *total, t_specifier *specifier)
{
	uint8_t		symbs_amount;
	uint64_t	u_nbr;

	u_nbr = nbr * (-1 * (nbr < 0)) + nbr * (nbr >= 0);
	symbs_amount = count_symbs(u_nbr, 10);
	if (specifier->width > specifier->precision && (nbr < 0
			|| (specifier->flags & PLUS_FLAG) || (specifier->flags & SPACE_FLAG)))
		specifier->width--;
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
	put_flag_symbol(&nbr, total, specifier);
	fill_with('0', (specifier->precision > symbs_amount)
		* (specifier->precision - symbs_amount));
	if (specifier->precision || u_nbr)
		ft_putnbr_base(u_nbr, 10, "0123456789");
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', specifier->width - specifier->precision);
	*total += specifier->width - !(specifier->precision || u_nbr);
}
//function too long
