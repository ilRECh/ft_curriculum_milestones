/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsupdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:16:21 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/03 22:56:51 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	writing(int fd, char **line)
{
	*line = dollar_get_env(*line);
	write(fd, *line, ft_strlen(*line));
	write(fd, "\n", 1);
}

static void	ctrl_c_wd(int signum, siginfo_t *siginfo, void *code)
{
	(void)signum;
	(void)siginfo;
	(void)code;
	g_param->ret = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, CYAN "\nwhatsupdoc?> " RESET, 26);
}

void	whatsupdoc(int fd, char *stopword)
{
	char				*line;
	int					copy_cur_stdin;
	bool				loop;
	struct sigaction	control_c;

	loop = true;
	copy_cur_stdin = dup(0);
	dup2(0, g_param->stdin_copy);
	ft_memset(&control_c, 0, sizeof(control_c));
	sig_set(SIGINT, &control_c, ctrl_c_wd);
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
	sig_set(SIGINT, &control_c, ctrl_c);
	dup2(copy_cur_stdin, 0);
	close(copy_cur_stdin);
}
