/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:47 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/10 19:15:47 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **args)
{
	char	*tmp;

	if (args[1])
	{
		error_str("pwd: too many arguments\n");
		return (1);
	}
	else if (getvalue("PWD"))
		printf("%s\n", getvalue("PWD"));
	else
	{
		tmp = getcwd(NULL, 0);
		if (tmp)
			printf("%s\n", tmp);
		else
		{
			error_str("pwd: cannot retrieve current directory\n");
			return (1);
		}
		free(tmp);
	}
	return (0);
}
