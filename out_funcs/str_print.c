#include "out_funcs.h"

static void	fill_with(char c, unsigned int amount)
{
	while (amount--)
		write(1, &c, 1);
}

static void	ft_putstr(const char *s, unsigned int length)
{
	while (length--)
		write(1, s++, 1);
}

void	str_print(char *str, int *total, t_specifier *specifier)
{
	if (!str)
		return ;
	if (specifier->precision > ft_strlen(str) || !specifier->precision)
		specifier->precision = ft_strlen(str);
	if (specifier->width > specifier->precision)
		specifier->width = specifier->width - specifier->precision;
	if (specifier->flags & (1 << MINUS_FLAG))
	{
		ft_putstr(str, specifier->precision);
		fill_with(' ', specifier->width);
	}
	else
	{
		fill_with(' ', specifier->width);
		ft_putstr(str, specifier->precision);
	}
	*total += specifier->precision + specifier->width;
}
