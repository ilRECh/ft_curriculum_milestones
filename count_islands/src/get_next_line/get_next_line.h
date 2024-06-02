#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define BUFFER_SIZE 100

enum
{
	BUF = -42,
};

typedef struct s_list_gnl
{
	int32_t				fd;
	char				*str;
	struct s_list_gnl	*next;
}	t_list_gnl;

int		get_next_line(int fd, char **line);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strndup(const char *s, size_t len);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dst_size);
char	*gnl_strjoin(char *s1, char *s2);

#endif