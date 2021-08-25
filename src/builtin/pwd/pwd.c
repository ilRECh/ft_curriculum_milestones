/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:47 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:54:48 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **args)
{
	if (args[1])
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	else
		printf("%s\n", getvalue("PWD"));
	return (0);
}
