#include "libft.h"

static size_t	ft_wrdcnt(char const *s, char c)
{
	size_t	count;
	char	in_word_flag;

	count = 0;
	in_word_flag = 0;
	while (*s && *s == c)
		s++;
	if (*s)
		count++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) && !in_word_flag)
		{
			in_word_flag++;
			count++;
		}
		else if (*(s + 1) == c && in_word_flag)
			in_word_flag--;
		s++;
	}
	return (count);
}

static void	ft_getword(const char **start, const char **end, char c)
{
	while (**start == c)
		(*start)++;
	*end = *start + 1;
	while (**end != c)
		(*end)++;
}

//change func

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		result_size;
	size_t		iter_1;
	const char	*start;
	const char	*end;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(
			(result_size = ft_wrdcnt(s, c)) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	start = s;
	iter_1 = 0;
	while (iter_1 < result_size)
	{
		ft_getword(&start, &end, c);
		result[iter_1++] = ft_strndup(start, end - start);
		start = end + 1;
	}
	return (result);
}
