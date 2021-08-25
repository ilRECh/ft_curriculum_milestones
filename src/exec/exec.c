/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:34 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:16 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*\
 *
 *		Either executes a command, which first has to be found in the sublst, or builtin,
 *	or, if occurs, calls exec on braces sublst detection.
 *
\*/
static int	exec_cmd_or_braces(t_list sublst, t_rdrct *rdrct, int *exitcode)
{
	int	pid;

	pid = 0;
	find_sublst_or_command(&sublst);
	if (sublst.cur && ((t_parse *)sublst.cur->content)->argv[0]
		&& !ft_strncmp(((t_parse *)sublst.cur->content)->argv[0], CASE, ft_strlen(CASE)))
		pid = exec_braces(sublst, rdrct);
	else if (check_builtin(((t_parse *)sublst.cur->content)->argv[0]))
		pid = exec_builtin(sublst, rdrct, exitcode);
	else
		pid = exec_cmd(((t_parse *)sublst.cur->content)->argv, rdrct);
	return (pid);
}

/*\
 *
 *		
 *
\*/
int	exec(t_list *lst)
{
	t_rdrct	*rdrct;
	t_list	sublst;
	int		exitcode;
	int		pid;

	if (!lst)
		return (-1);
	pid = 0;
	exitcode = 0;
	rdrct = ft_calloc(1, sizeof(t_rdrct));
	lst->cur = lst->head;
	while (lst->cur)
	{
		sublst = ft_all_rdrcts(lst, rdrct);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, true);
		pid = exec_cmd_or_braces(sublst, rdrct, &exitcode);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, false);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == AND)
		{
			if (pid > 0)
				waitpid(pid, &exitcode, 0);
			if (exitcode)
			{
				lst->cur = lst->cur->next;
				while (lst->cur
					&& ((t_parse *)lst->cur->content)->oper != END
					&& ((t_parse *)lst->cur->content)->oper != OR
					&& ((t_parse *)lst->cur->content)->oper != PIPE)
						lst->cur = lst->cur->next;
				if (lst->cur)
					lst->cur = lst->cur->next;
			}
			else
				lst->cur = lst->cur->next;
		}
		else if (lst->cur && ((t_parse *)lst->cur->content)->oper == OR)
		{
			if (pid > 0)
				waitpid(pid, &exitcode, 0);
			if (!exitcode)
			{
				lst->cur = lst->cur->next;
				while (lst->cur
					&& ((t_parse *)lst->cur->content)->oper != END
					&& ((t_parse *)lst->cur->content)->oper != AND
					&& ((t_parse *)lst->cur->content)->oper != PIPE)
						lst->cur = lst->cur->next;
				if (lst->cur)
					lst->cur = lst->cur->next;
			}
			else
				lst->cur = lst->cur->next;
		}
		else if (lst->cur && (((t_parse *)lst->cur->content)->oper == PIPE
			|| ((t_parse *)lst->cur->content)->oper == END))
			lst->cur = lst->cur->next;
	}
	free(rdrct);
	return (pid);
}
