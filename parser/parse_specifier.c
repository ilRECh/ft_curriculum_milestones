#include "parser.h"
#include "out_funcs.h"
#include "libft.h"

//create array of pointers to parse_functions instead of if..else statements

char	*parse_specifier(char *spec, va_list arg, int *total)
{
	char	*set;

	set = "cspdiuxX%";
	//flags parse
	//width parse
	//precision parse
	//type parse		<- in progress
	if (ft_strchr(set, *spec))
	{
		char_print(va_arg(arg, int), total);
		spec++;
		//(*output_funcs[ft_strchr(set, *spec) - set])(arg);
	}
	return (spec);
}
