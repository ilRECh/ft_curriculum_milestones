#include "out_funcs.h"

static void	spec_init(t_specifier *specifier,
					  int64_t const *nbr, uint8_t const *symbs_amount)
{
	if (specifier->width < 0)
	{
		specifier->width *= -1;
		specifier->flags |= MINUS_FLAG;
		if (specifier->flags & ZERO_FLAG)
			specifier->flags ^= ZERO_FLAG;
	}
	if (specifier->width > specifier->precision && (*nbr < 0
		|| (specifier->flags & PLUS_FLAG) || (specifier->flags & SPACE_FLAG)))
		specifier->width--;
	if (specifier->width < *symbs_amount)
		specifier->width = *symbs_amount;
	if (specifier->flags & ZERO_FLAG && specifier->precision < 0)
		specifier->precision = specifier->width;
	if (specifier->width < specifier->precision)
		specifier->width = specifier->precision;
}

static void	print_space(t_specifier *specifier,
						   uint64_t const *nbr, uint8_t const *symbs_amount)
{
	int32_t	correction;

	if (*symbs_amount >= specifier->precision)
		correction = *symbs_amount;
	else
		correction = specifier->precision;
	if (specifier->width > correction)
		fill_with(' ', specifier->width
					   - correction * (specifier->precision != 0 || *nbr != 0));
}

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
	spec_init(specifier, &nbr, &symbs_amount);
	if (!(specifier->flags & MINUS_FLAG))
		print_space(specifier, &u_nbr, &symbs_amount);
	put_flag_symbol(&nbr, total, specifier);
	fill_with('0', (specifier->precision > symbs_amount)
		* (specifier->precision - symbs_amount));
	if (specifier->precision || u_nbr)
		ft_putnbr_base(u_nbr, 10, "0123456789");
	if (specifier->flags & MINUS_FLAG)
		print_space(specifier, &u_nbr, &symbs_amount);
	*total += specifier->width - !(specifier->precision || u_nbr);
}
