#include "out_funcs.h"

static void ft_offset_int(t_list **integer, t_list **decimal)
{
	t_list	*decimal_end;
	uint8_t	symbs_amount;
	uint8_t	first_int_symb;

	if (count_symbs(ft_lstlast(*integer)->value, 10) == 1)
		return ;
	decimal_end = ft_lstlast(*decimal);
	symbs_amount = count_symbs(decimal_end->value, 10);
	ft_bignummultiply(decimal, 10, 10 - symbs_amount);
	free(decimal_end->next);
	(*integer)->prev = decimal_end;
	decimal_end->next = *integer;
	decimal_end = ft_lstlast(decimal_end);
	symbs_amount = count_symbs(decimal_end->value, 10) - 1;
	*integer = NULL;
	ft_lstadd_front(integer,
		ft_lstnew(decimal_end->value / ft_power(10, symbs_amount)));
	first_int_symb = decimal_end->value
			/ ft_power(10, count_symbs(decimal_end->value, 10) - 1);
	decimal_end->value -= ft_power(10, count_symbs(decimal_end->value, 10) - 1)
			* (first_int_symb - 1);
}

static void	ft_exclude_zeros(t_list *integer, t_list *decimal)
{
	uint16_t	cur_zeros;
	uint8_t		first_int_symb;

	decimal = ft_lstlast(decimal);
	cur_zeros = count_symbs(decimal->value, 10) - 1;
	while (decimal->value % ft_power(10, cur_zeros) == 0)
	{
		if (decimal->prev)
		{
			decimal = decimal->prev;
			free(decimal->next);
			decimal->next = NULL;
		}
		else
			break;
		cur_zeros = 9;
	}
	if (cur_zeros < count_symbs(decimal->value, 10) && cur_zeros--)
		decimal->value -= ft_power(10, cur_zeros + 1);
	first_int_symb = decimal->value
			/ ft_power(10, count_symbs(decimal->value, 10) - 1);
	decimal->value = decimal->value - ft_power(10,
		count_symbs(decimal->value, 10) - 1) * (first_int_symb - 1);
	integer->value = first_int_symb;
	ft_lstnormalizer(decimal);
}

int16_t	ft_change_to_exp(t_list **integer, t_list **decimal, t_specifier *specifier)
{
	uint16_t	integer_symbs;
	uint16_t	decimal_zeros;

	integer_symbs = integer_symbs_count(*integer);
	decimal_zeros = decimal_zeros_count(*decimal) + 1;
	if (integer_symbs == 1
		&& (*integer)->value == 0
		&& (*decimal)->value)
	{
		ft_exclude_zeros(*integer, *decimal);
		ft_round_decimal(integer, decimal, specifier);
		while ((*integer)->value >= 10 && decimal_zeros--)
			(*integer)->value /= 10;
		return (decimal_zeros * (-1));
	}
	else
	{
		ft_offset_int(integer, decimal);
		ft_round_decimal(integer, decimal, specifier);
		while ((*integer)->value >= 10 && integer_symbs++)
			(*integer)->value /= 10;
		return (integer_symbs - 1);
	}
}
