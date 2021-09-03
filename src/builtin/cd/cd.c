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

static void	home(char *path, bool *res)
{
	if (getvalue("HOME"))
	{
		path = ft_strjoin(getvalue("HOME"), path);
		*res = chpath(path);
		free(path);
	}
	else
	{
		*res = false;
		error_str("HOME not set");
	}
}

static void	back(bool *res)
{
	if (getvalue("OLDPWD"))
		*res = chpath(getvalue("OLDPWD"));
	else
		error_str("cd: OLDPWD not set");
}

int	ft_cd(char **args)
{
	char	*oldpath;
	char	*path;
	bool	res;

	if (args[1] && args[2]
		&& error_str("cd: too many arguments"))
		return (1);
	res = false;
	path = args[1];
	if (!path)
		path = "~";
	oldpath = oldpwd();
	if (path[0] == '~'
		|| (path[0] == '-' && path[1] == '-' && !path[2] && path++))
		home(path + 1, &res);
	else if (path[0] == '-' && path[1] == 0)
		back(&res);
	else
		res = chpath(path);
	update_oldpwd(res, oldpath);
	return (res);
}
