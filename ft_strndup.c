#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;

	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	dst[len] = 0;
	while (len--)
		dst[len] = s[len];
	return (dst);
}
