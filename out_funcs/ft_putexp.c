#include "out_funcs.h"

static void	ft_exclude_zeros(t_list **decimal)
{
	uint16_t	cur_zeros;
	t_list		*decimal_copy;

	decimal_copy = ft_lstlast(*decimal);
	cur_zeros = count_symbs(decimal_copy->value, 10) - 1;
	while (decimal_copy->value % ft_power(10, cur_zeros) == 0)
	{
		if (decimal_copy->prev)
		{
			decimal_copy = decimal_copy->prev;
			free(decimal_copy->next);
			decimal_copy->next = NULL;
		}
		cur_zeros = 9;
	}
	decimal_copy->value += ft_power(10, count_symbs(decimal_copy->value,10));
	ft_lstnormalizer(decimal_copy);
}

void	ft_change_to_exp(t_list **integer, t_list **decimal, t_specifier *specifier,
			   int32_t *total)
{
	uint16_t	integer_symbs;
	uint16_t	decimal_zeros;
	int16_t		exp;

	exp = 0;
	integer_symbs = integer_symbs_count(*integer);
	decimal_zeros = decimal_zeros_count(*decimal);
	if (integer_symbs == 1 && (*integer)->value == 0)
		;
}
