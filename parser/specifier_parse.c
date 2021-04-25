#include "parser.h"
#include "out_funcs.h"
#include "libft.h"

//create array of pointers to parse_functions instead of if..else statements



char	*parse_specifier(char *spec, va_list arg, int *total)
{
	t_specifier	specifier;

	specifier.flags = 0;
	//flags parse
	spec = flags_parse(spec, &specifier);

	//width parse
	spec = width_parse(spec, &specifier, arg);

	//precision parse
	if (*spec == '.')
		spec = precision_parse(++spec, &specifier, arg);

	//size parse

	//type parse		<- in progress
	if (ft_strchr("cspdiuxX%", *spec))
	{
		char_print(va_arg(arg, int), total);
		spec++;
		//(*output_funcs[ft_strchr(set, *spec) - set])(arg);
	}
	return (spec);
}
