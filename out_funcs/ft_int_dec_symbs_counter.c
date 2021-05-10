#include "out_funcs.h"

uint16_t	integer_symbs_count(t_list *integer)
{
	uint16_t	symbs_amount;

	integer = ft_lstlast(integer);
	symbs_amount = count_symbs(integer->value, 10);
	while (integer->prev)
	{
		symbs_amount += 9;
		integer = integer->prev;
	}
	return (symbs_amount);
}

//uint16_t	decimal_symbs_count(t_list *decimal)
//{
//	uint16_t	symbs_amount;
//
//	decimal = ft_lstlast(decimal);
//	symbs_amount = count_symbs(decimal->value, 10);
//	while (decimal->prev)
//	{
//		symbs_amount += 9;
//		decimal = decimal->prev;
//	}
//	return (symbs_amount);
//}

uint16_t	decimal_zeros_count(t_list *decimal)
{
	uint16_t	zeros_amount;
	uint16_t	cur_zeros;

	decimal = ft_lstlast(decimal);
	zeros_amount = 0;
	if (decimal->value == 0)
		return (zeros_amount);
	cur_zeros = count_symbs(decimal->value, 10) - 1;
	while (WE_EXIST)
	{
		while (cur_zeros--)
		{
			if ((decimal->value / ft_power(10, cur_zeros)) % 10 == 0)
				zeros_amount++;
			else
				return (zeros_amount);
		}
		decimal = decimal->prev;
		if (!decimal)
			break ;
		cur_zeros = 9;
	}
}
