#include "out_funcs.h"

static void	ft_putnbr(uint64_t nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = '0' + nbr;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putnbr_length(uint64_t nbr, uint8_t length, uint8_t is_dec)
{
	uint8_t		symbs_amount;
	uint8_t		length_copy;
	uint64_t	coeff;

	if (!length)
		return ;
	coeff = 1;
	length_copy = length;
	symbs_amount = count_symbs(nbr, 10);
	if (length > symbs_amount)
		fill_with('0', length - symbs_amount);
	while (length--)
		coeff *= 10;
	if (is_dec)
	{
		symbs_amount = count_symbs(nbr % coeff, 10);
		if (length_copy > symbs_amount)
			fill_with('0', length_copy - symbs_amount);
	}
	ft_putnbr(nbr % coeff);
}

static void	ft_round_decimal(t_list **integer,
						  t_list **decimal, t_specifier *specifier)
{
	t_list		*decimal_copy;
	uint32_t	iter_1;

	decimal_copy = ft_lstlast(*decimal);
	iter_1 = count_symbs(decimal_copy->value, 10) - 1;
	while (decimal_copy)
	{
		if (iter_1 > specifier->precision || !decimal_copy->prev)
			break;
		decimal_copy = decimal_copy->prev;
		iter_1 += 9;
	}
	if (iter_1 > specifier->precision && (decimal_copy->value /
		ft_power(10, iter_1 - specifier->precision - 1)) % 10 >= 5)
	{
		decimal_copy->value += 5
				* ft_power(10, iter_1 - specifier->precision - 1);
		ft_lstnormalizer(*decimal);
	}
	decimal_copy = ft_lstlast(*decimal);
	if ((decimal_copy->value
		/ ft_power(10, count_symbs(decimal_copy->value, 10) - 1)) > 1)
		(*integer)->value += 1;
}

void	ft_putdouble(t_list **integer, t_list **decimal, t_specifier *specifier)
{
	t_list *decimal_end = ft_lstlast(*decimal);
	t_list *integer_end = ft_lstlast(*integer);

	ft_round_decimal(integer, decimal, specifier);
	ft_putnbr_length(integer_end->value,
					 count_symbs(integer_end->value, 10), 0);
	integer_end = integer_end->prev;
	while (integer_end)
	{
		ft_putnbr_length(integer_end->value, 9, 0);
		integer_end = integer_end->prev;
	}
	write(1, ".", 1);
	ft_putnbr_length(decimal_end->value,
					 count_symbs(decimal_end->value, 10) - 1, 1);
	decimal_end = decimal_end->prev;
	while (decimal_end)
	{
		ft_putnbr_length(decimal_end->value, 9, 0);
		decimal_end = decimal_end->prev;
	}
	ft_lstclear(integer);
	ft_lstclear(decimal);
}