/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsupdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:16:21 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/09 20:20:26 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	writing(int fd, char **line)
{
	*line = dollar_get_env(*line);
	write(fd, *line, ft_strlen(*line));
	write(fd, "\n", 1);
}

static void	ctrlwd(int signum)
{
	(void)signum;
	g_param->ret = 130;
}

void	whatsupdoc(int fd, char *stopword)
{
	char	*line;
	int		copy_cur_stdin;
	bool	loop;
	void	*cp;

	loop = true;
	copy_cur_stdin = dup(0);
	signal(SIGINT, ctrlwd), signal(SIGQUIT, SIG_IGN), (cp = rl_getc_function);
	(rl_getc_function = getc), dup2(0, g_param->stdin_copy);
	while (true)
	{
		line = readline(CYAN "\033[2K\rwhatsupdoc?> " RESET);
		if (line && ft_strncmp(line, stopword, ft_strlen(stopword)))
			writing(fd, &line);
		else if (!line
			|| (line && !ft_strncmp(line, stopword, ft_strlen(stopword))))
		{
			free(line);
			break ;
		}
		free(line);
	}
	(rl_getc_function = cp), signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN), dup2(copy_cur_stdin, 0), close(copy_cur_stdin);
}
