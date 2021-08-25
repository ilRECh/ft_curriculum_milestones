/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsupdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:16:21 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:46:54 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//
//	heredoc analog. Takes place in the ft_rdrct func
//
void	whatsupdoc(int fd, char *stopword)
{
	char	*line;
	int		copy_cur_stdin;

	copy_cur_stdin = dup(0);
	dup2(0, g_param->stdin_copy);
	while (true)
	{
		line = readline("\033[2K\rwhatsupdoc?> ");
		if (line && ft_strncmp(line, stopword, ft_strlen(stopword)))
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		else if (line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	dup2(copy_cur_stdin, 0);
	close(copy_cur_stdin);
}
