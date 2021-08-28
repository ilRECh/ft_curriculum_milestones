/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:37:24 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/28 19:01:15 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	ctrl_c(int signum, siginfo_t *siginfo, void *code)
{
	(void)signum;
	(void)siginfo;
	(void)code;
	g_param->ret = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, RED "\nsuper " CYAN "shell " RESET "$> ", 35);
}

void	ctrl_c2(int signum, siginfo_t *siginfo, void *code)
{
	(void)signum;
	(void)siginfo;
	(void)code;

	if (!ft_strncmp("cat", rl_line_buffer, ft_strlen(rl_line_buffer)))
		write(1, "\n", 1);
}

void	sig_set(struct sigaction *action, _Bool b)
{
	if (b)
		action->sa_sigaction = ctrl_c;
	else
		action->sa_sigaction = ctrl_c2;
	action->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, action, NULL);
}
