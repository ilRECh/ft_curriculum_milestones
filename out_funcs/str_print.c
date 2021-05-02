#include "out_funcs.h"

static void	ft_putstr(const char *s, unsigned int length)
{
	while (length--)
		write(1, s++, 1);
}

void	str_print(char *str, int *total, t_specifier *specifier)
{
	if (!str)
	{
		if (specifier->precision > 0 && specifier->precision < 6)
			str = "";
		else
			str = "(null)";
	}
	if (specifier->precision > (int)ft_strlen(str) || specifier->precision < 0)
		specifier->precision = ft_strlen(str);
	if (specifier->width > specifier->precision)
		specifier->width = specifier->width - specifier->precision;
	else
		specifier->width = 0;
	if (specifier->flags & MINUS_FLAG)
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
