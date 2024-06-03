/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:04:48 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/09 18:47:29 by vcobbler         ###   ########.fr       */
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
		printf("no right to execute\n");
		exit(1);
	}
	else
	{
		waitpid(pid, exitcode, 0);
		*exitcode = WEXITSTATUS(*exitcode);
	}
	return (-1);
}
