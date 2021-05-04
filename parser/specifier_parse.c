#include "parser.h"
#include "out_funcs.h"
#include "libft.h"

char	*parse_specifier(char *spec, va_list arg, int *total)
{
	t_specifier	specifier;
	char		*spec_copy;
	char		*types_set;

	types_set = "cspdiuxXnfge%";
	spec_copy = spec;
	spec = flags_parse(spec, &specifier);
	spec = width_parse(spec, &specifier, arg);
	spec = precision_parse(spec, &specifier, arg);
	spec = size_parse(spec, &specifier);
	if (*spec && ft_strchr(types_set, *spec))
	{
		specifier.type = *ft_strchr(types_set, *spec);
		out_funcs(arg, total, &specifier);
		spec++;
	}
	else
	{
		write(1, "%", 1);
		*total += 1;
		return (spec_copy);
	}
	return (spec);
}
