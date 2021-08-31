/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:46:08 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/31 19:47:43 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	*g_param;

static void	pre_env(void)
{
	char		*new_value;
	static char	*new_env[] = {NULL, "SHLVL=1", NULL, NULL};
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
			new_env[2] = ft_strjoin("PWD=", tmp);
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
}

int	main(int argc, char **argv, char **env)
{
	struct sigaction	control_c;
	t_list				*list_of_parses;
	char				*line;

	(void)argc;
	ft_memset(&control_c, 0, sizeof(control_c));
	setup_env(argv, env);
	line = (char *) 0xFF;
	// char *eee[] = {"HELLO=THERE", "PATH=/Users/csamuro/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/share/dotnet:/usr/local/munki:~/.dotnet/tools:/Users/csamuro/.brew/bin", NULL};
	// ft_export(eee);
	while (line)
	{
		sig_set(&control_c, ctrl_c);
		line = readline(RED "\033[2K\rsuper " CYAN "shell " RESET "$> ");
		// line = ft_strdup("echo \"hello \\n world\"");
		if (!line)
			break ;
		add_history(line);
		list_of_parses = get_command_line(&line);
		if (!list_of_parses)
			continue ;
		sig_set(&control_c, ctrl_c2);
		go_on_I_will_wait(exec(list_of_parses));
		rl_replace_line("", 0);
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
		// exit(1);
	}
	return (0);
}
