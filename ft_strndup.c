#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;
	char	*dst_copy;

	if (!s)
		return (NULL);
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	dst_copy = dst;	
	while (len--)
		*dst_copy++ = *s++;
	return (dst);
}
