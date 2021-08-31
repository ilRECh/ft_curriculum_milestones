/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:39 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/31 19:02:41 by vcobbler         ###   ########.fr       */
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

static void	print_with_quotes(char *word)
{
	int	iter_1;

	write(1, "declare -x ", 12);
	iter_1 = -1;
	while (word[++iter_1] != '=')
		write(1, word + iter_1, 1);
	write(1, "=\"", 2);
	while (word[++iter_1])
		write(1, word + iter_1, 1);
	write(1, "\"\n", 2);
}

int	print_exp(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->env && g_param->env[++iter_1])
	{
		if (!(g_param->env[iter_1][0] == '_'
			&& g_param->env[iter_1][1] == '='))
			print_with_quotes(g_param->env[iter_1]);
	}
	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
		if (check_in_env(g_param->exprt[iter_1]))
			print_with_quotes(g_param->exprt[iter_1]);
	return (0);
}
