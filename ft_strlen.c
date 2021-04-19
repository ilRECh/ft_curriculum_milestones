#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*end;

	end = (char *)s;
	while (*end)
		end++;
	return (end - s);
}
