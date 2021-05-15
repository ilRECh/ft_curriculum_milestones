#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

enum
{
	BUF = -42,
};

typedef struct s_list
{
	int32_t			fd;
	char			*str;
	struct s_list	*next;
}	t_list;

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char *s1, char *s2);

#endif