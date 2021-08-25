/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:39 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:54:40 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exp(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->exprt && g_param->exprt[++iter_1])
		printf("%s\n", g_param->exprt[iter_1]);
	return (0);
}
