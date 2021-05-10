#include "out_funcs.h"

static void	spec_init(t_specifier *specifier)
{
	if (specifier->precision < 0)
		specifier->precision = 6;
	else if (specifier->precision == 0)
		specifier->precision = 1;
}

void	exclude_trailing_zeros(t_list *decimal, t_specifier *specifier)
{
	uint32_t	iter_1;

	decimal = ft_lstlast(decimal);
	iter_1 = count_symbs(decimal->value, 10) - 1;
	while (iter_1 < specifier->precision && decimal->prev)
	{
		iter_1 += 9;
		decimal = decimal->prev;
	}
	iter_1 -= specifier->precision;
	while (specifier->precision)
	{
		if (decimal->value / ft_power(10, iter_1++) % 10 == 0)
		{
			specifier->precision--;
			if (iter_1 == 9)
			{
				decimal = decimal->next;
				iter_1 = 0;
			}
		}
		else
			break;
	}
}

void	g_print(t_list *integer, t_list *decimal, t_specifier *specifier)
{
	uint16_t	integer_symbs;
	uint16_t	decimal_zeros;
	int16_t		exp;

	integer_symbs = integer_symbs_count(integer);
	decimal_zeros = decimal_zeros_count(decimal);
	exp = (integer_symbs - 1) * (integer->value != 0)
		+ (decimal_zeros + 1) * (-1) * (!integer->value);
	specifier->flags |= G_FLAG;
	spec_init(specifier);
	if (specifier->precision == 0)
		specifier->precision = 1;
	if (specifier->precision > exp && exp >= -4)
	{
		specifier->type = 'f';
		specifier->precision -= exp + 1;
	}
	else
	{
		specifier->type = 'e';
		specifier->precision -= 1;
	}
}
