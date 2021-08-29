/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_or_braces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:19:19 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/28 22:20:06 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd_or_braces(t_list sublst, t_rdrct *rdrct, int *exitcode)
{
	int	pid;

	pid = 0;
	find_sublst_or_command(&sublst);
	if (sublst.cur && sublst.cur != sublst.end
		&& ((t_parse *)sublst.cur->content)->argv[0]
		&& !ft_strncmp(((t_parse *)sublst.cur->content)->argv[0],
			CASE, ft_strlen(CASE)))
		pid = exec_braces(sublst, rdrct);
	else if (sublst.cur && sublst.cur != sublst.end
		&& check_builtin(((t_parse *)sublst.cur->content)->argv[0]))
		pid = exec_builtin(sublst, rdrct, exitcode);
	else if (sublst.cur && sublst.cur != sublst.end
		&& ft_strnstr(((t_parse *)sublst.cur->content)->argv[0],
			"minishell", ft_strlen(((t_parse *)sublst.cur->content)->argv[0])))
		pid = exec_minishell(((t_parse *)sublst.cur->content)->argv,
				rdrct, exitcode);
	else if (sublst.cur && sublst.cur != sublst.end)
		pid = exec_cmd(((t_parse *)sublst.cur->content)->argv, rdrct);
	else
		pid = -42;
	return (pid);
}
