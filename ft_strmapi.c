#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int n, char c))
{
	char	*result;
	size_t	iter_1;

	if (!s || !f)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	iter_1 = -1;
	while (s[++iter_1])
		result[iter_1] = (*f)(iter_1, s[iter_1]);
	return (result);
}		
