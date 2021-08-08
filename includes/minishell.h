/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:42 by name              #+#    #+#             */
/*   Updated: 2021/08/08 00:04:52 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <dirent.h>

extern char	**g_env;

int		ft_cd(char *path);
int		ft_export(char **vars);
int		ft_echo(char **argv);
int		ft_env(void);
char	*getvalue(char *word);
int		setvalue(char *word, char *new_value);

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