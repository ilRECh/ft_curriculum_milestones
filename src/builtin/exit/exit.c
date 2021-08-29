/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:53:18 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:53:18 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_all(char **args)
{
	int	iter_1;

	iter_1 = -1;
	while (args && args[++iter_1])
		free(args[iter_1]);
	free(args);
	iter_1 = -1;
	while (g_param->env && g_param->env[++iter_1])
		free(g_param->env[iter_1]);
	free(g_param->env);
	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
		free(g_param->exprt[iter_1]);
	free(g_param->exprt);
	while (g_param->locals && g_param->locals[++iter_1])
		free(g_param->locals[iter_1]);
	free(g_param->locals);
}

int	ft_exit(char **args)
{
	int	exit_status;

	if (!args)
		exit_status = 1;
	else if (args && args[1] && args[2]
		&& error_str("exit: too many arguments"))
		return (1);
	else if (args && args[1])
		exit_status = ft_atoi(args[1]);
	else
		exit_status = 0;
	free_all(args);
	exit(exit_status);
	return (0);
}
