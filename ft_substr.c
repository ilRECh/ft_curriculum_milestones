#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_size;
	char	*dst;

	substr_size = ft_strlen(s + start);
	if (len < substr_size)
		substr_size = len;
	dst = ft_strldup(s + start, substr_size);
	if (!dst)
		return (NULL);
	return (dst);
}
