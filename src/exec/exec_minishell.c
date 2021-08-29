/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:04:48 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/28 22:54:22 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_minishell(char **argv, t_rdrct *rdrct, int *exitcode)
{
	int		pid;

	ft_lstclear(&rdrct->in, NULL);
	ft_lstclear(&rdrct->out, NULL);
	pid = fork();
	if (!pid)
	{
		execve(argv[0], argv, g_param->env);
	}
	else
	{
		waitpid(pid, exitcode, 0);
	}
	return (-1);
}
