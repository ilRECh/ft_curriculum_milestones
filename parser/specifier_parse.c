#include "parser.h"
#include "out_funcs.h"
#include "libft.h"

//create array of pointers to parse_functions instead of if..else statements



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
	if (ft_strchr(types_set, *spec))
	{
		specifier.type = *ft_strchr(types_set, *spec);
		out_funcs(arg, total, &specifier);
		spec++;
	}
	else
		return (spec_copy);
	return (spec);
}
