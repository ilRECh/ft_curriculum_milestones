#include "parse.h"

char	*trimmer(char *str, char *c)
{
	short	x;

	while(ft_strchr(c, *str))
		ft_memmove(str, &str[1], ft_strlen(str));
	x = ft_strlen(str) - 1;
	while (ft_strchr(c, str[x]))
	{
		str[x] = 0;
		x = ft_strlen(str) - 1;
	}
	return (str);
}