/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:42 by name              #+#    #+#             */
/*   Updated: 2021/08/08 16:33:18 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include <dirent.h>

typedef struct s_param
{
	char	**env;
	char	**exprt;
	int		ret;
}	t_param;

/*\
 *
 *	SINGLE LEGIT GLOBAL VARIABLE
 * 
\*/
extern t_param	*g_param;

/*\
 *
 *	BUILTINS
 * 
\*/
int		ft_cd(char **args);
int		ft_export(char **args);
int		print_exp(void);
int		ft_echo(char **args);
int		ft_env(char **args);
int		ft_unset(char **args);
int		ft_exit(char **args);

/*\
 *
 *	ENV UTILS
 * 
\*/
char	*getvalue(char *word);
int		setvalue(char *word, char *new_value);
char	*getvalue_exprt(char *word);
int		setvalue_exprt(char *word, char *new_value);
void	free_tabs(char **tab);

/*\
 *
 *	EXECUTION
 * 
\*/
int		exec(t_list *lst);
void	exec_cmd(t_list args, char **envp);


/*\
 *
 *	ERROR output funcs
 *
\*/
static inline uint8_t	error(void)
{
	printf(RED "ERROR: " RESET "%s\n", strerror(errno));
	return (1);
}

static inline uint8_t	error_str(char *str)
{
	printf(RED "ERROR: " RESET "%s", str);
	return (1);
}

#endif