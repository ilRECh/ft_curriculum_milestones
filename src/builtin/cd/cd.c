/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:03:09 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/04 20:27:00 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	relative(char *path)
{
	char	*tmp;

	if (chdir(path) < 0 && error())
		return (1);
	tmp = getcwd(NULL, 0);
	setvalue("PWD", tmp);
	free(tmp);
	return (0);
}

static int	absolute(char *new_path)
{
	char	*path;
	char	*old_path;

	old_path = getcwd(NULL, 0);
	while (TRUE)
	{
		path = getcwd(NULL, 0);
		if(ft_strlen(path) == 1)
			break ;
		free(path);
		chdir("..");
	}
	free(path);
	path = ft_strjoin(getvalue("HOME"), new_path);
	if (chdir(path) < 0 && error())
	{
		chdir(old_path);
		free(old_path);
		free(path);
		return (1);
	}
	setvalue("PWD", path);
	free(old_path);
	free(path);
	return (0);
}

int	back(char *oldpwd)
{
	char	*tmp;

	while (TRUE)
	{
		tmp = getcwd(NULL, 0);
		if(ft_strlen(tmp) == 1)
			break ;
		free(tmp);
		chdir("..");
	}
	chdir(getvalue("OLDPWD"));
	setvalue("OLDPWD", oldpwd);
	tmp = getcwd(NULL, 0);
	setvalue("PWD", tmp);
	free(tmp);
	return (0);
}

int	ft_cd(char *path)
{
	if (path[0] == '~')
		return (absolute(++path));
	else if (!(path[0] == '-' && path[1] == 0))
		return (relative(path));
	else
		return (back(getvalue("PWD")));
}
