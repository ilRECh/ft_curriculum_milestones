/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:04:48 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 23:14:11 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_minishell(char **argv, t_rdrct *rdrct, int *exitcode)
{
	int		pid;
	char	*new_value;

	ft_lstclear(&rdrct->in, NULL);
	ft_lstclear(&rdrct->out, NULL);
	pid = fork();
	if (!pid)
	{
		setvalue("SHLVL", new_value = ft_itoa(atoi(getvalue("SHLVL") + 1)));
		free(new_value);
		execve(argv[0], argv, g_param->env);
	}
	else
	{
		waitpid(pid, exitcode, 0);
	}
	return (-1);
}
