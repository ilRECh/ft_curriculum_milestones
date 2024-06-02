#include "parser.h"
#include "libft.h"

char	*precision_parse(char *spec, t_specifier *specifier, va_list arg)
{
	specifier->precision = -1;
	if (*spec == '.')
	{
		spec++;
		if (*spec == '*')
		{
			specifier->precision = va_arg(arg, int);
			return (++spec);
		}
		if (ft_atoi(spec) >= 0)
			specifier->precision = ft_atoi(spec);
		while (ft_isdigit(*spec))
			spec++;
	}
	return (spec);
}
