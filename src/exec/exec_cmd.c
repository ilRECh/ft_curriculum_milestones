/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:22:41 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:23:02 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd(char **args, t_rdrct *rdrct)
{
	int	pid = 0;
	int	writer_pid;

	if (rdrct->inall.is)
		in(&rdrct->in, rdrct->inall.pipefd[1]);
	pid = fork();
	if (!pid)
	{
		ft_lstclear(&rdrct->in, ft_close);
		ft_lstclear(&rdrct->out, ft_close);
		if (rdrct->copy.is0)
			close(rdrct->copy.fd[0]);
		if (rdrct->copy.is1)
			close(rdrct->copy.fd[1]);
		if (rdrct->inall.is)
			close(rdrct->inall.pipefd[1]);
		close(rdrct->outall.pipefd[0]);
		if (rdrct->inall.is)
			dup2(rdrct->inall.pipefd[0], 0);
		dup2(rdrct->outall.pipefd[1], 1);
		execve(args[0], args, g_param->env);
	}
	else
	{
			writer_pid = fork();
			if (!writer_pid)
			{
				if (rdrct->pipe.is)
					close(rdrct->pipe.pipefd[0]);
				if (rdrct->copy.is0)
					close(rdrct->copy.fd[0]);
				if (rdrct->copy.is1)
					close(rdrct->copy.fd[1]);
				if (rdrct->inall.is)
				{
					close(rdrct->inall.pipefd[0]);
					close(rdrct->inall.pipefd[1]);
				}
				close(rdrct->outall.pipefd[1]);
				out(&rdrct->out, rdrct->outall.pipefd[0]);
				close(rdrct->outall.pipefd[0]);
				ft_lstclear(&rdrct->in, ft_close);
				ft_lstclear(&rdrct->out, ft_close);
				exit(0);
			}
		if (rdrct->inall.is)
		{
			close(rdrct->inall.pipefd[0]);
			close(rdrct->inall.pipefd[1]);
		}
		close(rdrct->outall.pipefd[0]);
		close(rdrct->outall.pipefd[1]);
		rdrct->outall.is = false;
		rdrct->inall.is = false;
		ft_lstclear(&rdrct->out, ft_close);
		ft_lstclear(&rdrct->in, ft_close);
	}
	return (pid);
}
