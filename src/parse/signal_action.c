/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:37:24 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/02 07:11:43 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}
	// if (*rl_line_buffer)
	// 	write(1, "\n", 1);

void	sig_set(struct sigaction *action,
	void (*f)(int, siginfo_t *, void *))
{
	action->sa_sigaction = (*f);
	action->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, action, NULL);
}
