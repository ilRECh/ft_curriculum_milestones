/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_on_I_will_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sip <sip@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:52:46 by sip               #+#    #+#             */
/*   Updated: 2021/08/25 11:13:23 by sip              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int go_on_I_will_wait(int pid)
{
	int exitcode;
	int wpid;

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
	return (0);
}
