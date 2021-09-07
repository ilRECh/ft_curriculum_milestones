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

	// write(1, "\033[2K\r", 6);
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	// write(1, RED "\033[2K\rsuper " CYAN "shell " RESET "$> ", 39);
	rl_redisplay();
	// write(1, "\n", 1);
}

void	ctrl_fucking_c(int signum)
{
	(void)signum;

	write(1, "FUUUUUUCCCCCKK", 15);
	write(1, "\n", 1);
	exit(130);
}

// void	ctrl_c2(int signum)
// {
// 	(void)signum;
// 	(void)siginfo;
// 	(void)code;
// }
