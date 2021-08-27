/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:54:39 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/27 21:02:55 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exp(void)
{
	g_param->exprt.cur = g_param->exprt.head;
	while (g_param->exprt.cur)
	{
		printf("%s\n", g_param->exprt.cur->content);
		g_param->exprt.cur = g_param->exprt.cur->next;
	}
	return (0);
}
