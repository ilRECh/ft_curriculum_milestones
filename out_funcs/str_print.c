#include "out_funcs.h"

static void	spec_init(char *str, t_specifier *specifier)
{
	if (specifier->width < 0)
	{
		specifier->width *= -1;
		specifier->flags |= MINUS_FLAG;
	}
	if (specifier->precision > (int)ft_strlen(str) || specifier->precision < 0)
		specifier->precision = ft_strlen(str);
	if (specifier->width > specifier->precision)
		specifier->width = specifier->width - specifier->precision;
	else
		specifier->width = 0;
}

static void	ft_putstr(const char *s, unsigned int length)
{
	while (length--)
		write(1, s++, 1);
}

void	str_print(char *str, int *total, t_specifier *specifier)
{
	if (!str)
		str = "(null)";
	spec_init(str, specifier);
	if (specifier->flags & MINUS_FLAG)
	{
		ft_putstr(str, specifier->precision);
		fill_with(' ', specifier->width);
	}
	else
	{
		fill_with('0' * ((specifier->flags & ZERO_FLAG) != 0)
			+ ' ' * ((specifier->flags & ZERO_FLAG) == 0), specifier->width);
		ft_putstr(str, specifier->precision);
	}
	*total += specifier->precision + specifier->width;
}
