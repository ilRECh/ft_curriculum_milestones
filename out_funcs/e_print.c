#include "out_funcs.h"

static void	setup_str(char *str, int8_t exp)
{
	str[0] = 'e';
	str[3] = exp * (exp >= 0) + exp * ((-1) * (exp < 0));
	if (exp >= 0)
		str[1] = '+';
	else if (exp < 0)
		str[1] = '-';
}

void	e_print(double to_print, int32_t *total, t_specifier *specifier)
{
	int8_t	exp;
	char	str[3];
	t_double	*nbr;
	t_list		*integer;
	t_list		*decimal;
	uint16_t	symbs_amount;

	nbr = ft_calloc(1, sizeof(t_double));
	nbr->number.value = to_print;
	integer = NULL;
	decimal = NULL;

	if (fge_special_cases(nbr, total, specifier))
		return;
//	if (fge_special_cases(&nbr, total, specifier))
//		return ;
//	exp = 0;
//	while ((nbr > 10 && nbr > 0) || (nbr < -10 && nbr < 0))
//	{
//		nbr /= 10;
//		exp++;
//	}
//	while ((nbr < 1 && nbr > 0) || (nbr > -1 && nbr < 0))
//	{
//		nbr *= 10;
//		exp--;
//	}
//	if (specifier->width > 8)
//		specifier->width -= 4;
//	setup_str(str, exp);
//	f_print(nbr, total, specifier, str);
//	*total += 4;





	nbr->true_mantissa = ((uint64_t)1 << 52)
						 | nbr->number.s_bitfields.mantissa;
	nbr->true_exponent = nbr->number.s_bitfields.exponent - 1023;
	ft_int_dec(nbr, &integer, &decimal);
	symbs_amount = integer_symbs_count(integer);
	spec_init(specifier, nbr, &symbs_amount);
	ft_round_decimal(&integer, &decimal, specifier);
	print_prefix_space(nbr, total, specifier);
	ft_putdouble(&integer, &decimal, specifier, total);
	if (specifier->flags & MINUS_FLAG)
		fill_with(' ', (*total += specifier->width, specifier->width));
	free(nbr);
}
