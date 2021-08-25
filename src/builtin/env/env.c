/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:52:12 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:52:12 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char	**args)
{
	char	**tmp;

	if (args[1]
		&& error_str("env: too many arguments"))
		return (1);
	tmp = g_param->env;
	while (tmp && *tmp)
		printf("%s\n", *tmp++);
	return (0);
}
