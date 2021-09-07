/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_on_I_will_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:52:46 by sip               #+#    #+#             */
/*   Updated: 2021/08/25 22:45:25 by vcobbler         ###   ########.fr       */
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
			g_param->ret = exitcode;
		else if (wpid <= 0)
			break ;
	}
	if (g_param->ret == 2)
		write (1, "\n", 1);
	return (0);
}
