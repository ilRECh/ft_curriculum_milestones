/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:47 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 03:09:33 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **args)
{
	char	*tmp;

	if (args[1])
	{
		printf("pwd: too many arguments\n");
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
	}
	return (0);
}
