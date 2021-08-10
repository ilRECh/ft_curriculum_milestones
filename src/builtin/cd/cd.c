/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:03:09 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/07 10:59:17 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_env(char *newpath)
{
	char	*tmp;

	if (newpath[0] != '/')
	{
		tmp = newpath;
		newpath = ft_strjoin("/", newpath);
		free(tmp);
	}
	setvalue("PWD", newpath);
	free(newpath);
}

static int	chpath(char *newpath, char *oldpath, char *start_with)
{
	char	*path;

	while (TRUE)
	{
		path = getcwd(NULL, 0);
		if (ft_strlen(path) == 1)
			break ;
		free(path);
		chdir("..");
	}
	free(path);
	path = ft_strjoin(start_with, newpath);
	if (chdir(path) < 0 && error())
	{
		chdir(oldpath);
		free(path);
		return (1);
	}
	update_env(getcwd(NULL, 0));
	free(path);
	return (0);
}

int	ft_cd(char **args)
{
	char	*oldpath;
	char	*path;
	bool	res;

	if (args[2]
		&& error_str("cd: too many arguments"))
		return (1);
	path = args[1];
	oldpath = getcwd(NULL, 0);
	if (path[0] == '~')
		res = chpath(++path, oldpath, getvalue("HOME"));
	else if (path[0] == '/')
		res = chpath(++path, oldpath, "");
	else if (path[0] == '-' && path[1] == 0)
		res = chpath("", oldpath, getvalue("OLDPWD"));
	else
	{
		res = chpath(path = ft_strjoin("/", path), oldpath, oldpath);
		free(path);
	}
	if (!res)
		setvalue("OLDPWD", oldpath);
	free(oldpath);
	return (res);
}
