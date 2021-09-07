/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsupdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:16:21 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/03 23:24:10 by csamuro          ###   ########.fr       */
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
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, CYAN "\nwhatsupdoc?> " RESET, 26);
}

// static void	ctrlsl(int signum)
// {
// 	(void)signum;
// 	// g_param->ret = 130;// 	rl_replace_line("", 0);
// 	rl_on_new_line();
// 	rl_redisplay();
// 	write(1, CYAN "\033[2K\rwhatsupdoc?> " RESET, 30);
// }

void	whatsupdoc(int fd, char *stopword)
{
	char				*line;
	int					copy_cur_stdin;
	bool				loop;

	loop = true;
	copy_cur_stdin = dup(0);
	dup2(0, g_param->stdin_copy);
	signal(SIGINT, ctrlwd), signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		line = readline(CYAN "\033[2K\rwhatsupdoc?> " RESET);
		if (line && ft_strncmp(line, stopword, ft_strlen(stopword)))
			writing(fd, &line);
		else if (line && !ft_strncmp(line, stopword, ft_strlen(stopword)))
		{
			free(line);
			break ;
		}
		free(line);
	}
	signal(SIGINT, ctrl_c), signal(SIGQUIT, SIG_IGN);
	dup2(copy_cur_stdin, 0);
	close(copy_cur_stdin);
}
