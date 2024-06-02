#include "parser.h"
#include "libft.h"

char	*size_parse(char *spec, t_specifier *specifier)
{
	specifier->size = 0;
	if (*spec == 'l')
	{
		specifier->size |= 1;
		if (*(spec + 1) == 'l')
			return (spec + 2);
		else
			return (spec + 1);
	}
	else if (*spec == 'h' && *(spec + 1) != 'h')
	{
		specifier->size |= (1 << 1);
		return (spec + 1);
	}
	else if (*spec == 'h' && *(spec + 1) == 'h')
	{
		specifier->size |= (1 << 2);
		return (spec + 2);
	}
	return (spec);
}
