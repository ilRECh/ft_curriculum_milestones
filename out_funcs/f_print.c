#include "out_funcs.h"

static void	spec_init(t_specifier *specifier,
						 double const *nbr, uint8_t *symbs_amount)
{
	if (specifier->precision < 0)
		specifier->precision = 6;
	*symbs_amount += specifier->precision + 1 * (specifier->precision != 0)
			+ ((*nbr < 0) || ((specifier->flags & PLUS_FLAG) != 0)
			|| ((specifier->flags & SPACE_FLAG) != 0));
	if (specifier->width < *symbs_amount)
		specifier->width = *symbs_amount;
}

static void	print_decimal(t_specifier *specifier,
						   double const *u_nbr)
{
	double	decimal;
	double	correction;
	uint8_t iter_1;
	char	c;

	decimal = *u_nbr - (double)((int)*u_nbr);
	correction = 5.f;
	specifier->precision++;
	iter_1 = -1;
	while (++iter_1 < specifier->precision)
		correction /= 10;
	decimal += correction;
	specifier->precision--;
	iter_1 = -1;
	while (++iter_1 < specifier->precision)
	{
		c = (char)(decimal * 10) + '0';
		write(1, &c, 1);
		decimal = decimal * 10 - (double)((int)(decimal * 10));
	}
}

static void	put_flag_symbol(double const *nbr, t_specifier *specifier)
{
	char	c;

	c = '+' * ((specifier->flags & PLUS_FLAG) != 0) * (*nbr >= 0)
		+ ' ' * ((specifier->flags & SPACE_FLAG) != 0
				 && !(specifier->flags & PLUS_FLAG)) * (*nbr >= 0)
		+ '-' * (*nbr < 0);
	if (c)
		write(1, &c, 1);
}

void	print_prefix_space(t_specifier *specifier, uint8_t *symbs_amount,
						double const *nbr)
{
	if (!(specifier->flags & MINUS_FLAG) && (specifier->width > *symbs_amount)
		&& !(specifier->flags & ZERO_FLAG))
	{
		fill_with(' ', specifier->width - *symbs_amount);
		put_flag_symbol(nbr, specifier);
	}
	else if (!(specifier->flags & MINUS_FLAG) && (specifier->width > *symbs_amount))
	{
		put_flag_symbol(nbr, specifier);
		fill_with('0', specifier->width - *symbs_amount);
	}
	else
		put_flag_symbol(nbr, specifier);
}

void	f_print(double nbr, int32_t *total, t_specifier *specifier)
{
	uint8_t	symbs_amount;
	double	u_nbr;

	if (fge_special_cases(&nbr, total, specifier))
		return ;
	u_nbr = nbr * (-1 * (nbr < 0)) + nbr * (nbr >= 0);
	symbs_amount = count_symbs((uint64_t)u_nbr, 10);
	spec_init(specifier, &nbr, &symbs_amount);
	print_prefix_space(specifier, &symbs_amount, &nbr);
	ft_putnbr_base((uint64_t)u_nbr, 10, "0123456789");
	if (specifier->precision)
	{
		write(1, ".", 1);
		print_decimal(specifier, &u_nbr);
	}
	if (specifier->flags & MINUS_FLAG && (specifier->width > symbs_amount))
		fill_with(' ', specifier->width - symbs_amount);
	*total += specifier->width;
}
