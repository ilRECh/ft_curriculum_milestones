#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dst;
	char const	*start;
	char const	*end;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1);
	while (ft_strchr(set, *start) && *start)
		start++;
	if (start != end)
		while (ft_strchr(set, *(end - 1)))
			end--;
	dst = ft_strndup(start, end - start);
	return (dst);
}
