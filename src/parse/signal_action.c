/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:37:24 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 23:03:40 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int signum)
{
	(void)signum;

	g_param->ret = 130;
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// write(1, "\n", 1);
	write(1, RED "\nsuper " CYAN "shell " RESET "$> ", 35);
	rl_redisplay();
}

// void	ctrl_c2(int signum)
// {
// 	(void)signum;
// 	(void)siginfo;
// 	(void)code;
// }
