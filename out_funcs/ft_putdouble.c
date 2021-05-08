#include "out_funcs.h"

static void	loc_fill_with(char c, unsigned int amount, t_specifier *specifier,
						  int32_t *total)
{
	while (amount-- && specifier->precision)
	{
		specifier->precision--;
		*total += write(1, &c, 1);
	}
}

static void	ft_putnbr(uint64_t nbr, t_specifier *specifier, int32_t *total)
{
	char	c;

	if ((nbr < 10 && specifier && specifier->precision)
		|| (nbr < 10 && !specifier))
	{
		c = '0' + nbr;
		if (specifier && specifier->precision)
			specifier->precision--;
		*total += write(1, &c, 1);
	}
	else if (!specifier || specifier->precision)
	{
		ft_putnbr(nbr / 10, specifier, total);
		ft_putnbr(nbr % 10, specifier, total);
	}
}

static void	ft_putnbr_length(t_list *element,
							 t_specifier *specifier, int32_t *total)
{
	uint8_t		symbs_amount;
	uint8_t		symbs_amount_copy;
	uint64_t	coeff;

	coeff = 1;
	symbs_amount = count_symbs(element->value, 10);
	symbs_amount_copy = symbs_amount;
	if (symbs_amount < 9 && element->next)
		loc_fill_with('0', 9 - symbs_amount, specifier, total);
	while (symbs_amount_copy--)
		if (specifier && symbs_amount_copy == 0 && !element->next)
			break ;
		else
			coeff *= 10;
	if (specifier && !element->next
		&& (--symbs_amount > count_symbs(element->value % coeff, 10)))
		loc_fill_with('0', symbs_amount - count_symbs(
					element->value % coeff, 10), specifier, total);
	if (coeff > 1)
		ft_putnbr(element->value % coeff, specifier, total);
}


void	ft_putdouble(t_list **integer, t_list **decimal,
				  t_specifier *specifier, int32_t *total)
{
	t_list *decimal_end;
	t_list *integer_end;

	decimal_end = ft_lstlast(*decimal);
	integer_end = ft_lstlast(*integer);
	while (integer_end)
	{
		ft_putnbr_length(integer_end, NULL, total);
		integer_end = integer_end->prev;
	}
	if (specifier->precision && write(1, ".", 1))
		*total += 1;
	while (decimal_end)
	{
		ft_putnbr_length(decimal_end, specifier, total);
		decimal_end = decimal_end->prev;
	}
	if (specifier->precision > 0)
		while (specifier->precision--)
			*total += write(1, "0", 1);
	ft_lstclear(integer);
	ft_lstclear(decimal);
}