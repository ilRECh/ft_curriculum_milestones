#include "libft.h"
#define BUFFER_SIZE 1024

static char	*ft_strjoin_free_s1(char const *s1, char const *s2)
{
	long	i;
	long	j;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return ((char *)s2);
	else if (s2 == NULL)
		return ((char *)s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = *(s1 + i);
	while (s2[++j])
		str[i + j] = *(s2 + j);
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

static int	to_short(char *np, char *tail)
{
	int	lenp;

	if (np)
	{
		lenp = ft_strlen(np);
		ft_memcpy(tail, np, lenp + 1);
		ft_memset(&tail[lenp], 0, BUFFER_SIZE - lenp);
		return (1);
	}
	ft_memset(tail, 0, BUFFER_SIZE);
	return (0);
}

static int	get_next(int fd, char **line)
{
	static char	tail[BUFFER_SIZE + 1];
	int			check_out;
	char		*np;

	while (1)
	{
		if (!*tail)
		{
			check_out = read(fd, tail, BUFFER_SIZE);
			if (check_out < 1)
			{
				if (check_out < 0)
					free(*line);
				return (check_out);
			}
			tail[check_out] = 0;
		}
		np = ft_memchr(tail, '\n', BUFFER_SIZE);
		if (np)
			*np++ = 0;
		*line = ft_strjoin_free_s1(*line, tail);
		if (to_short(np, tail))
			return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	if (!line || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	*line = (char *)ft_calloc(sizeof(char), 1);
	if (!*line)
		return (-1);
	return (get_next(fd, line));
}
