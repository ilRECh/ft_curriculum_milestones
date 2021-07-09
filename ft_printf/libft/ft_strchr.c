#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	if (!s)
		return (NULL);
	character = (unsigned char)c;
	while (*s != character && *s)
		s++;
	if (*s != character)
		return (NULL);
	return ((char *)s);
}
