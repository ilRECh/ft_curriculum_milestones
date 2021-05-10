#include "out_funcs.h"

static void	spec_init(t_specifier *specifier, uint16_t symbs_amount)
{
	if (specifier->precision < 0)
		specifier->precision = 6;
	symbs_amount += DOT * (specifier->precision > 0)
		+ specifier->precision + ((specifier->flags & NEGATIVE_NUMBER)
			|| ((specifier->flags & PLUS_FLAG) != 0)
			|| ((specifier->flags & SPACE_FLAG) != 0))
		+ ((specifier->flags & OCTAL_FLAG) != 0
			&& !specifier->precision)
		+ 4 * (specifier->type == 'e');
	if (specifier->width >= symbs_amount)
		specifier->width -= symbs_amount;
	else
		specifier->width = 0;
}

static void	put_flag_symbol(t_specifier *specifier, int32_t *total)
{
	char	c;

	c = '+' * ((specifier->flags & PLUS_FLAG) != 0)
		* ((specifier->flags & NEGATIVE_NUMBER) == 0)
		+ ' ' * ((specifier->flags & SPACE_FLAG) != 0
			&& !(specifier->flags & PLUS_FLAG))
		* ((specifier->flags & NEGATIVE_NUMBER) == 0)
		+ '-' * (specifier->flags & NEGATIVE_NUMBER);
	if (c)
		*total += write(1, &c, 1);
}

static void	print_prefix_space(int32_t *total, t_specifier *specifier)
{
	if (!(specifier->flags & MINUS_FLAG) && specifier->width
		&& !(specifier->flags & ZERO_FLAG))
	{
		fill_with(' ', (*total += specifier->width, specifier->width));
		put_flag_symbol(specifier, total);
	}
	else if (!(specifier->flags & MINUS_FLAG)
		&& specifier->width)
	{
		put_flag_symbol(specifier, total);
		fill_with('0', (*total += specifier->width, specifier->width));
	}
	else
		put_flag_symbol(specifier, total);
}

void	ft_outnum(t_list **integer, t_list **decimal, t_specifier *specifier,
			   int32_t *total)
{
	int16_t	exp;

	exp = 0;
	if (specifier->type == 'e')
		exp = ft_change_to_exp(integer, decimal, specifier);
	else
		ft_round_decimal(integer, decimal, specifier);
	if ((specifier->flags & G_FLAG)
		&& !(specifier->flags & OCTAL_FLAG))
		exclude_trailing_zeros(*decimal, specifier);
	spec_init(specifier, integer_symbs_count(*integer));
	print_prefix_space(total, specifier);
	ft_putdouble(integer, decimal, specifier, total);
	if (specifier->type == 'e')
	{
		if (exp < 0)
			*total += write(1, "e-", 2);
		else
			*total += write(1, "e+", 2);
		exp = ft_abs(exp);
		if (exp < 10)
			*total += write(1, "0", 1);
		*total += count_symbs(exp, 10);
		ft_putnbr_base(exp, 10, "0123456789");
	}
}

void	feg_print(double to_print, int32_t *total, t_specifier *specifier)
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
	if (feg_special_cases(nbr, total, specifier))
		return ;
	nbr->true_mantissa = ((uint64_t)1 << 52)
		| nbr->u_number.s_bitfields.mantissa;
	nbr->true_exponent = nbr->u_number.s_bitfields.exponent - 1023;
	if (nbr->u_number.s_bitfields.sign == 1)
		specifier->flags |= NEGATIVE_NUMBER;
	ft_int_dec(nbr, &integer, &decimal);
	if (specifier->type == 'g')
		g_print(integer, decimal, specifier);
	ft_outnum(&integer, &decimal, specifier, total);
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', (*total += specifier->width, specifier->width));
	free(nbr);
}
