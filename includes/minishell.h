#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <dirent.h>

extern char	**environment;

int		ft_cd(char *path);
int		ft_export(char **vars);
char	*getvalue(char *word);

static inline uint8_t	error(void)
{
	printf(RED "ERROR: " RESET "%s\n", strerror(errno));
	return (1);
}

static inline uint8_t	error_str(char *str)
{
	printf(RED "ERROR: " RESET "%s\n", str);
	return (1);
}

#endif