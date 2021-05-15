#include "get_next_line.h"

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

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;
	char	*dst_copy;

	if (!s)
		return (NULL);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[len] = 0;
	dst_copy = dst;
	while (len--)
		*dst_copy++ = *s++;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	char	*end;

	if (!s)
		return (0);
	end = (char *)s;
	while (*end)
		end++;
	return (end - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	source_len;

	if (!dst || !src)
		return (0);
	source_len = ft_strlen(src);
	if (dst_size)
	{
		dst_size--;
		while (dst_size-- && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (source_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	result_size;
	char	*dst;

	if (!s1)
		s1 = ft_strndup("", 0);
	if (!s1)
		return (NULL);
	result_size = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((result_size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[result_size] = 0;
	ft_strlcpy(dst + ft_strlcpy(dst, s1, result_size + 1),
		s2, ft_strlen(s2) + 1);
	free(s1);
	return (dst);
}
