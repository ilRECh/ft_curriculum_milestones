#include "libft.h"
#define BUFFER_SIZE 256

int	to_short(char *np, char *tail)
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

int	get_next(int fd, char **line)
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
		*line = ft_strjoin(*line, tail);
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
