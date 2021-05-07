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

//static void	put_flag_symbol(double const *nbr, t_specifier *specifier)
//{
//	char		c;
//	t_double	t_nbr;
//
//	t_nbr.value = *nbr;
//	c = '+' * ((specifier->flags & PLUS_FLAG) != 0) * (t_nbr.f_bits.sign == 0)
//		+ ' ' * ((specifier->flags & SPACE_FLAG) != 0
//				 && !(specifier->flags & PLUS_FLAG)) * (t_nbr.f_bits.sign == 0)
//		+ '-' * t_nbr.f_bits.sign;
//	if (c)
//		;//write(1, &c, 1);
//}

//void	print_prefix_space(t_specifier *specifier, uint8_t *symbs_amount,
//						double const *nbr)
//{
//	if (!(specifier->flags & MINUS_FLAG) && (specifier->width > *symbs_amount)
//		&& !(specifier->flags & ZERO_FLAG))
//	{
//		fill_with(' ', specifier->width - *symbs_amount);
//		put_flag_symbol(nbr, specifier);
//	}
//	else if (!(specifier->flags & MINUS_FLAG)
//		&& (specifier->width > *symbs_amount))
//	{
//		put_flag_symbol(nbr, specifier);
//		fill_with('0', specifier->width - *symbs_amount);
//	}
//	else
//		put_flag_symbol(nbr, specifier);
//}

void	f_print(double to_print, int32_t *total, t_specifier *specifier,
			 char *if_e_print)
{
	t_double	*nbr;
	t_list		*integer;
	t_list		*decimal;

	nbr = ft_calloc(1, sizeof(t_double));
	nbr->number.value = to_print;
	integer = NULL;
	decimal = NULL;
	if (fge_special_cases(nbr, total, specifier))
		return;
	nbr->true_mantissa = ((uint64_t)1 << 52)
						 | nbr->number.s_bitfields.mantissa;
	nbr->true_exponent = nbr->number.s_bitfields.exponent - 1023;
	if (nbr->number.all_bits)
		ft_int_dec(nbr, &integer, &decimal);
	else
	{
		ft_lstadd_front(&integer, ft_lstnew(0));
		ft_lstadd_front(&decimal, ft_lstnew(10));
	}
	nbr->true_exponent = nbr->number.s_bitfields.exponent - 1023;
	ft_putdouble(&integer, &decimal, specifier);
}
