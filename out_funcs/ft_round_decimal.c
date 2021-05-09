#include "out_funcs.h"

void	ft_round_decimal(t_list **integer, t_list **decimal,
					  t_specifier *specifier)
{
	t_list		*decimal_copy;
	int32_t		iter_1;

	decimal_copy = ft_lstlast(*decimal);
	iter_1 = count_symbs(decimal_copy->value, 10) - 1;
	while (decimal_copy)
	{
		if (iter_1 > specifier->precision || !decimal_copy->prev)
			break ;
		decimal_copy = decimal_copy->prev;
		iter_1 += 9;
	}
	if (iter_1 > specifier->precision && (decimal_copy->value
			/ ft_power(10, iter_1 - specifier->precision - 1)) % 10 >= 5)
		decimal_copy->value += (uint64_t)(5.99
				* ft_power(10, iter_1 - specifier->precision - 1));
	ft_lstnormalizer(*decimal);
	decimal_copy = ft_lstlast(*decimal);
	if (!(!specifier->precision && (*integer)->value % 2 == 0
			  	 && !(decimal_copy->value
				   	 / ft_power(10,
					count_symbs(decimal_copy->value, 10) - 2) % 10))
		&& (decimal_copy->value
			/ ft_power(10, count_symbs(decimal_copy->value, 10) - 1)) > 1)
		(*integer)->value += 1;
}
