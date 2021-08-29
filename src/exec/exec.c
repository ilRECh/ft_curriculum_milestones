/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:34 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/28 22:26:10 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "additional_exec.h"

static void	errr(int pid, int *exitcode, t_rdrct *rdrct)
{
	if (pid == -42)
	{
		printf("command not found\n");
		*exitcode = 1;
		g_param->ret = 1;
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
}

static void	or(int pid, int *exitcode, t_list *lst)
{
	if (pid > 0)
		if (waitpid(pid, exitcode, 0) < 0)
			*exitcode = g_param->ret;
	if (!*exitcode)
	{
		lst->cur = lst->cur->next;
		while (lst->cur
			&& ((t_parse *)lst->cur->content)->oper != END
			&& ((t_parse *)lst->cur->content)->oper != AND)
			lst->cur = lst->cur->next;
		if (lst->cur)
			lst->cur = lst->cur->next;
	}
	else
		lst->cur = lst->cur->next;
}

static void	and(int pid, int *exitcode, t_list *lst)
{
	if (pid > 0)
		if (waitpid(pid, exitcode, 0) < 0)
			*exitcode = g_param->ret;
	if (*exitcode)
	{
		lst->cur = lst->cur->next;
		while (lst->cur
			&& ((t_parse *)lst->cur->content)->oper != END
			&& ((t_parse *)lst->cur->content)->oper != OR)
			lst->cur = lst->cur->next;
		if (lst->cur)
			lst->cur = lst->cur->next;
	}
	else
		lst->cur = lst->cur->next;
}

static void	end(int pid, int *exitcode, t_list *lst)
{
	if (pid > 0)
		if (waitpid(pid, exitcode, 0) < 0)
			*exitcode = g_param->ret;
	lst->cur = lst->cur->next;
}

int	exec(t_list *lst)
{
	t_rdrct	*rdrct;
	t_list	sublst;
	int		exitcode;
	int		pid;

	init(&pid, &exitcode, &rdrct, lst);
	while (lst->cur)
	{
		sublst = ft_all_rdrcts(lst, rdrct);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, true);
		pid = exec_cmd_or_braces(sublst, rdrct, &exitcode);
		errr(pid, &exitcode, rdrct);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, false);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == AND)
			and(pid, &exitcode, lst);
		else if (lst->cur && ((t_parse *)lst->cur->content)->oper == OR)
			or(pid, &exitcode, lst);
		else if (lst->cur && ((t_parse *)lst->cur->content)->oper == END)
			end(pid, &exitcode, lst);
		else if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			lst->cur = lst->cur->next;
	}
	return (free(rdrct), (g_param->ret = exitcode), pid);
}
