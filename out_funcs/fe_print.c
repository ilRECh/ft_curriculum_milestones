#include "out_funcs.h"

static void	spec_init(t_specifier *specifier,
						 t_double const *nbr, uint16_t symbs_amount)
{
	if (specifier->precision < 0)
		specifier->precision = 6;
	symbs_amount += DOT * (specifier->precision > 0)
		+ specifier->precision + ((nbr->u_number.s_bitfields.sign)
			|| ((specifier->flags & PLUS_FLAG) != 0)
			|| ((specifier->flags & SPACE_FLAG) != 0))
		+ ((specifier->flags & OCTAL_FLAG) != 0
			&& !specifier->precision);
	if (specifier->width >= symbs_amount)
		specifier->width -= symbs_amount;
	else
		specifier->width = 0;
}

static void	put_flag_symbol(t_double const *nbr, t_specifier *specifier,
							int32_t *total)
{
	char	c;

	c = '+' * ((specifier->flags & PLUS_FLAG) != 0)
		* (nbr->u_number.s_bitfields.sign == 0)
		+ ' ' * ((specifier->flags & SPACE_FLAG) != 0
			&& !(specifier->flags & PLUS_FLAG))
		* (nbr->u_number.s_bitfields.sign == 0)
		+ '-' * nbr->u_number.s_bitfields.sign;
	if (c)
		*total += write(1, &c, 1);
}

static void	print_prefix_space(t_double const *nbr, int32_t *total,
						t_specifier *specifier)
{
	if (!(specifier->flags & MINUS_FLAG) && specifier->width
		&& !(specifier->flags & ZERO_FLAG))
	{
		fill_with(' ', (*total += specifier->width, specifier->width));
		put_flag_symbol(nbr, specifier, total);
	}
	else if (!(specifier->flags & MINUS_FLAG)
		&& specifier->width)
	{
		put_flag_symbol(nbr, specifier, total);
		fill_with('0', (*total += specifier->width, specifier->width));
	}
	else
		put_flag_symbol(nbr, specifier, total);
}

void	ft_outnum(t_list **integer, t_list **decimal, t_specifier *specifier,
			   int32_t *total)
{
	if (specifier->type == 'e')
		ft_change_to_exp(integer, decimal, specifier);
	ft_putdouble(integer, decimal, specifier, total);
}

void	fe_print(double to_print, int32_t *total, t_specifier *specifier)
{
	t_double	*nbr;
	t_list		*integer;
	t_list		*decimal;

	nbr = ft_calloc(1, sizeof(t_double));
	if (!nbr)
		return ;
	nbr->u_number.value = to_print;
	integer = NULL;
	decimal = NULL;
	if (fge_special_cases(nbr, total, specifier))
		return ;
	nbr->true_mantissa = ((uint64_t)1 << 52)
		| nbr->u_number.s_bitfields.mantissa;
	nbr->true_exponent = nbr->u_number.s_bitfields.exponent - 1023;
	ft_int_dec(nbr, &integer, &decimal);
	spec_init(specifier, nbr, integer_symbs_count(integer));
	ft_round_decimal(&integer, &decimal, specifier);
	print_prefix_space(nbr, total, specifier);
	ft_outnum(&integer, &decimal, specifier, total);
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', (*total += specifier->width, specifier->width));
	free(nbr);
}
