/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:39 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 01:31:40 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_in_env(char *to_check)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->env[++iter_1])
		if (!ft_strncmp(g_param->env[iter_1], to_check, ft_strlen(to_check)))
			return (0);
	return (1);
}

int	print_exp(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->env && g_param->env[++iter_1])
	{
		if (!(g_param->env[iter_1][0] == '_'
			&& g_param->env[iter_1][1] == '='))
			printf("declare -x %s\n", g_param->env[iter_1]);
	}
	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
		if (check_in_env(g_param->exprt[iter_1]))
			printf("declare -x %s\n", g_param->exprt[iter_1]);
	return (0);
}
