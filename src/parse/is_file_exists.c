/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:25 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/04 01:45:24 by csamuro          ###   ########.fr       */
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
			char **str_concat)
{
	char	*file_path;
	int		i;

	i = -1;
	file_path = ft_strdup(*str_concat);
	while (paths[++i])
	{
		free(*str_concat);
		*str_concat = ft_strjoin_free(
				ft_strjoin(paths[i], "/"), file_path, 1);
		*fd = open(*str_concat, O_RDONLY);
		if (*fd > 2)
			break ;
	}
	free(file_path);
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

	str_concat = trimmer(ft_strdup(file_path), "\"\'", FULL);
	if (*str_concat == '/')
	{
		(fd = open(str_concat, O_RDONLY)), close(fd);
		if (fd > 2)
			return (str_concat);
	}
	paths = ft_split(getvalue("PATH"), ':');
	if (!paths)
		return (NULL);
	if (ft_strnstr(str_concat, "./", 2) || is_from_path(paths, str_concat))
		fd = open(str_concat, O_RDONLY);
	else
		run_compare(paths, &fd, &str_concat);
	free_tabs(paths);
	if (fd < 3)
		free(str_concat), (str_concat = NULL);
	else
		close(fd);
	return (str_concat);
}
