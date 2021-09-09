/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_on_I_will_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:52:46 by sip               #+#    #+#             */
/*   Updated: 2021/09/09 18:57:14 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_on_I_will_wait(int pid)
{
	int	exitcode;
	int	wpid;

	if (pid == -1)
		pid--;
	while (true)
	{
		wpid = wait(&exitcode);
		if (wpid == pid)
		{
			if (exitcode != 2 && exitcode != 3)
				g_param->ret = WEXITSTATUS(exitcode);
			else if (exitcode == 2)
				g_param->ret = 130;
			else if (exitcode == 3)
				g_param->ret = 131;
		}
		else if (wpid <= 0)
			break ;
	}
	if (g_param->ret == 130 || g_param->ret == 131)
		write (1, "\n", 1);
	return (0);
}
