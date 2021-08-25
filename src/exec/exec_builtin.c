/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:23:41 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:04 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*\
 *
 *		Checks for builtin
 *
\*/
int	check_builtin(char *name)
{
	int	index;
	
	index = 0;
	if ((++index, !ft_strncmp(name, "cd", 2))
		|| (++index, !ft_strncmp(name, "echo", 4))
		|| (++index, !ft_strncmp(name, "env", 3))
		|| (++index, !ft_strncmp(name, "exit", 4))
		|| (++index, !ft_strncmp(name, "export", 6))
		|| (++index, !ft_strncmp(name, "pwd", 3))
		|| (++index, !ft_strncmp(name, "unset", 5)))
		return (index);
	return (0);
}

/*\
 *
 *		Executes builtin
 *
\*/
int	exec_builtin(t_list sublst, t_rdrct *rdrct, int *exitcode)
{
	int	writer_pid;
	int	(* const builtin[])(char **) = {
		ft_cd,
		ft_echo,
		ft_env,
		ft_exit,
		ft_export,
		ft_pwd,
		ft_unset
	};

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
		ft_lstclear(&rdrct->in, NULL);
		ft_lstclear(&rdrct->out, NULL);
		exit(0);
	}
	ft_lstclear(&rdrct->in, NULL);
	ft_lstclear(&rdrct->out, NULL);
	if (rdrct->copy.is0)
		close(rdrct->copy.fd[0]);
	if (rdrct->copy.is1)
		close(rdrct->copy.fd[1]);
	if (rdrct->inall.is)
	{
		close(rdrct->inall.pipefd[0]);
		close(rdrct->inall.pipefd[1]);
	}
	close(rdrct->outall.pipefd[0]);
	rdrct->copy.fd[1] = dup(1);
	rdrct->copy.is1 = true;
	dup2(rdrct->outall.pipefd[1], 1);
	*exitcode = builtin[check_builtin(((t_parse *)sublst.cur->content)->argv[0]) - 1](((t_parse *)sublst.cur->content)->argv);
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

	return (-1);
}