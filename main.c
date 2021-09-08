/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:46:08 by vcobbler          #+#    #+#             */
/*   Updated: 2021/09/04 01:56:56 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	*g_param;

static void	pre_env(void)
{
	char		*new_value;
	static char	*new_env[] = {NULL, "SHLVL=1", NULL};
	char		*tmp;

	if (getvalue("SHLVL"))
	{
		setvalue("SHLVL",
			new_value = ft_itoa(ft_atoi(getvalue("SHLVL")) + 1));
		free(new_value);
	}
	else
		ft_export((char **)new_env);
	if (!getvalue("PWD"))
	{
		tmp = getcwd(NULL, 0);
		if (tmp)
		{
			new_env[1] = ft_strjoin("PWD=", tmp);
			ft_export((char **)new_env);
			free(new_env[1]);
		}
		else
			error_str("cannot retrieve current directory\n");
		free(tmp);
	}
}

static void	setup_env(char **argv, char **env)
{
	int		vars;
	int		iter_1;
	char	**environ_;

	g_param = ft_calloc(1, sizeof(t_param));
	g_param->stdin_copy = dup(0);
	g_param->stdout_copy = dup(1);
	vars = 0;
	iter_1 = 0;
	while (env[iter_1++])
		vars++;
	environ_ = (char **)ft_calloc(vars + 1, sizeof(char *));
	iter_1 = -1;
	while (env[++iter_1])
		environ_[iter_1] = ft_strdup(env[iter_1]);
	g_param->env = environ_;
	if (getvalue("SHELL"))
		setvalue("SHELL", argv[0]);
	pre_env();
	// tcgetattr(STDIN_FILENO, &g_param->saved);
}

int	main(int argc, char **argv, char **env)
{
	t_list				*list_of_parses;
	char				*line;

	(void)argc;
	line = (char *) 0xFF;
	setup_env(argv, env);
	// add_to_env(ft_split("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/share/dotnet:/usr/local/munki:~/.dotnet/tools", '='));
	while (line)
	{
		signal(SIGINT, ctrl_c), signal(SIGQUIT, SIG_IGN);
		line = readline(RED "super " CYAN "shell " RESET "$> ");
		// line = ft_strdup("echo \"\\taaaaa\"");//echo "\taaaaa"
		if (!line)
			break ;
		if (*line)
			add_history(line);
		list_of_parses = get_command_line(&line);
		// exit(0);
		if (!list_of_parses)
			continue ;
		signal(SIGINT, SIG_IGN);
		go_on_I_will_wait(exec(list_of_parses));
		rl_replace_line("", 0);
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
	}
	return (0);
}
