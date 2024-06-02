#include "parser.h"
#include "libft.h"

char	*width_parse(char *spec, t_specifier *specifier, va_list arg)
{
	specifier->width = 0;
	if (*spec == '*')
	{
		specifier->width = va_arg(arg, int);
		return (++spec);
	}
	if (ft_atoi(spec) > 0)
		specifier->width = ft_atoi(spec);
	while (ft_isdigit(*spec))
		spec++;
	return (spec);
}
