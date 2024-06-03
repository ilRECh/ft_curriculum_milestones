/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_braces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:23:15 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:00:56 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	closer(t_rdrct *rdrct)
{
	if (rdrct->inall.is)
	{
		dup2(rdrct->copy.fd[0], 0);
		close(rdrct->copy.fd[0]);
		rdrct->copy.is0 = false;
	}
	dup2(rdrct->copy.fd[1], 1);
	close(rdrct->copy.fd[1]);
	rdrct->copy.is1 = false;
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

//
//
//	Executes braces sublst alongsiede with braces sublst writer child
//
//
int	exec_braces(t_list sublst, t_rdrct *rdrct)
{
	int	writer_pid;
	int	pid;

	if (rdrct->inall.is)
		in(&rdrct->in, rdrct->inall.pipefd[1]);
	writer_pid = fork();
	writer(writer_pid, rdrct);
	if (rdrct->inall.is)
	{
		rdrct->copy.fd[0] = dup(0);
		rdrct->copy.is0 = true;
		dup2(rdrct->inall.pipefd[0], 0);
	}
	rdrct->copy.fd[1] = dup(1);
	rdrct->copy.is1 = true;
	dup2(rdrct->outall.pipefd[1], 1);
	if (rdrct->inall.is)
		close(rdrct->inall.pipefd[1]);
	close(rdrct->outall.pipefd[0]);
	pid = exec((t_list *)((t_parse *)sublst.cur->content)->argv[1]);
	closer(rdrct);
	return (pid);
}
