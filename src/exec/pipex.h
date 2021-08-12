#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_content
{
	char	**arg;
}	t_content;

int		get_next_line(int fd, char **line);
void	pipex(int argc, char **argv, char **envp);
void	clean_content(void *content);
void	clean_paths(char **paths);
void	exec_cmd(t_list args, char **envp);

#endif