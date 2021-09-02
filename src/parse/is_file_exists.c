/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:25 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 07:05:25 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tabs(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	run_compare(char **paths, int *fd,
			char **str_concat, char *file_path)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		free(*str_concat);
		*str_concat = ft_strjoin_free(
				ft_strjoin(paths[i], "/"), file_path, 1);
		*fd = open(*str_concat, O_RDONLY);
		if (*fd > 2)
			break ;
	}
}

_Bool	is_from_path(char **paths, char *str)
{
	unsigned int	iter;

	iter = -1;
	while (paths[++iter])
		if (!ft_strncmp(paths[iter], str, \
		ft_strlen(paths[iter])))
			return (TRUE);
	return (FALSE);
}

char	*is_util_exists(char *file_path)
{
	char	*str_concat;
	char	**paths;
	int		fd;

	paths = ft_split(getvalue("PATH"), ':');
	if (!paths)
		return ((void *)ret_perr("malloc ft_split error"));
	if (*file_path == '\\')
		ft_memmove(file_path, &file_path[1], ft_strlen(file_path));
	str_concat = ft_strdup(file_path);
	fd = 0;
	if ((str_concat[0] == '.' && str_concat[1] == '/') \
	|| is_from_path(paths, str_concat))
		fd = open(str_concat, O_RDONLY);
	else
		run_compare(paths, &fd, &str_concat, file_path);
	free_tabs(paths);
	if (fd < 3)
	{
		free(str_concat);
		return (NULL);
	}
	close(fd);
	return (str_concat);
}
