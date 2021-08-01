#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>

extern	char	**environ;

static inline uint8_t	error(void)
{
	printf(RED "ERROR: " RESET "%s\n", strerror(errno));
	return (1);
}

#endif