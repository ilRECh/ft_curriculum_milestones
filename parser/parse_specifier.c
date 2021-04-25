#include "parser.h"
#include "libft.h"

//create array of pointers to parse_functions instead of if..else statements

int	parse_specifier(char *spec, va_list arg)
{
	int		offset;
	char	*set;


	offset = 0;
	set = "cspdiuxX%";
	//flags parse
	//width parse
	//precision parse
	//type parse		<- in progress
	if (ft_strchr(set, *spec))
		(*output_funcs[ft_strchr(set, *spec) - set])(arg)
	return (offset);
}
