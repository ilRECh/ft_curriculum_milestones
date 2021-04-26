#include "parser.h"
#include "libft.h"

char	*flags_parse(char *spec, t_specifier *specifier)
{
	char	*set;
	char	*search;

	specifier->flags = 0;
	set = "-+ #0";
	while (WE_EXIST)
	{
		search = ft_strchr(set, *spec);
		if (search)
			specifier->flags |= 1 << (search - set);
		else
			break;
		spec++;
	}
	return (spec);
}
