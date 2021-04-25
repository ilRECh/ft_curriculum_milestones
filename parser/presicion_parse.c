#include "parser.h"
#include "libft.h"

char	*precision_parse(char *spec, t_specifier *specifier, va_list arg)
{
	if (*spec == '*')
	{
		specifier->precision = va_arg(arg, int);
		return (++spec);
	}
	specifier->precision = ft_atoi(spec);
	while (ft_isdigit(*spec))
		spec++;
	return (spec);
}
