/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:22:41 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/28 18:38:20 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(char **args, t_rdrct *rdrct)
{
	// struct sigaction	control_c;
	// ft_memset(&control_c, 0, sizeof(control_c));
	// sig_set(&control_c, FALSE);
	ft_lstclear(&rdrct->in, NULL);
	ft_lstclear(&rdrct->out, NULL);
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

static void	writer(int writer_pid, t_rdrct *rdrct)
{
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
		ft_lstclear(&rdrct->in, NULL);
		ft_lstclear(&rdrct->out, NULL);
		exit(0);
	}
}

int	exec_cmd(char **args, t_rdrct *rdrct)
{
	int	pid;
	int	writer_pid;

	pid = fork();
	if (!pid)
		child(args, rdrct);
	else
	{
		writer_pid = fork();
		writer(writer_pid, rdrct);
		if (rdrct->inall.is)
			in(&rdrct->in, rdrct->inall.pipefd[1]);
		if (rdrct->inall.is)
		{
			close(rdrct->inall.pipefd[0]);
			close(rdrct->inall.pipefd[1]);
		}
		close(rdrct->outall.pipefd[0]);
		close(rdrct->outall.pipefd[1]);
		rdrct->outall.is = false;
		rdrct->inall.is = false;
		ft_lstclear(&rdrct->out, NULL);
		ft_lstclear(&rdrct->in, NULL);
	}
	return (pid);
}
