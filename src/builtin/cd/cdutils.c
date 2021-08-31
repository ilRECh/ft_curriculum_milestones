/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 14:28:05 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/31 19:02:19 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env(char *newpath)
{
	char	*tmp;
	char	*pwd[2];

	if (newpath[0] != '/')
	{
		tmp = newpath;
		newpath = ft_strjoin("/", newpath);
		free(tmp);
	}
	if (getvalue("PWD"))
		setvalue("PWD", newpath);
	else
	{
		pwd[0] = "PWD";
		pwd[1] = newpath;
		ft_export(pwd);
	}
	free(newpath);
}

int	is_way_exist(char *way)
{
	DIR	*dir;

	dir = opendir(way);
	if (!dir)
		return (1);
	return (0);
}

int	chpath(char *newpath)
{
	if (is_way_exist(newpath) && error())
		return (1);
	chdir(newpath);
	update_env(getcwd(NULL, 0));
	return (0);
}

char	*oldpwd(void)
{
	char	*oldpath;

	oldpath = getcwd(NULL, 0);
	if (!oldpath && getvalue("PWD"))
		oldpath = ft_strdup(getvalue("PWD"));
	return (oldpath);
}

void	update_oldpwd(bool res, char *oldpath)
{
	if (!res && oldpath && getvalue("OLDPWD"))
		setvalue("OLDPWD", oldpath);
	else
		printf("cd: error setting up OLDPWD");
	free(oldpath);
}
