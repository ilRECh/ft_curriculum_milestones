#include "out_funcs.h"

static void ft_offset_int(t_list **integer, t_list **decimal)
{
	t_list	*decimal_end;
	uint8_t	symbs_amount;

	decimal_end = ft_lstlast(*decimal);
	symbs_amount = count_symbs(decimal_end->value, 10);
	ft_bignummultiply(decimal, 10, 10 - symbs_amount);
	(*integer)->value -= 1;
	decimal_end->next = *integer;
	ft_lstnormalizer(decimal_end);
	decimal_end = ft_lstlast(decimal_end);
	symbs_amount = count_symbs(decimal_end->value, 10) - 1;
	*integer = NULL;
	ft_lstadd_front(integer,
		ft_lstnew(decimal_end->value / ft_power(10, symbs_amount)));
}

static void	ft_exclude_zeros(t_list *decimal)
{
	uint16_t	cur_zeros;

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
		cur_zeros = 9;
	}
	decimal->value += ft_power(10, count_symbs(decimal->value,10));
	ft_lstnormalizer(decimal);
}

uint16_t	ft_change_to_exp(t_list **integer, t_list **decimal, t_specifier *specifier)
{
	uint16_t	integer_symbs;
	uint16_t	decimal_zeros;
	int16_t		exp;

	exp = 0;
	integer_symbs = integer_symbs_count(*integer);
	decimal_zeros = decimal_zeros_count(*decimal);
	if (integer_symbs == 1 && (*integer)->value == 0)
	{
		ft_exclude_zeros(*decimal);
		return (decimal_zeros);
	}
	else
	{
		ft_offset_int(integer, decimal);
		return (integer_symbs - 1);
	}
}
