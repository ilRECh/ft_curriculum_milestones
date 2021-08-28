/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:46:08 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 00:50:18 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	*g_param;

static void	update_lvl(void)
{
	char	*new_value;
	char	*split[2];

	printf("%p\n", *g_param->env);
	if (getvalue("SHLVL"))
	{
		setvalue("SHLVL",
			new_value = ft_itoa(ft_atoi(getvalue("SHLVL")) + 1));
		free(new_value);
	}
	else
	{
		split[0] = "SHLVL";
		split[1] = "1";
		add_to_env(split);
	}
}

static void	setup_env(char **env)
{
	int		vars;
	int		iter_1;
	char	**environ_;

	vars = 0;
	iter_1 = 0;
	while (env[iter_1++])
		vars++;
	environ_ = (char **)ft_calloc(vars + 1, sizeof(char *));
	iter_1 = 1;
	while (env[++iter_1])
		environ_[iter_1] = ft_strdup(env[iter_1]);
	g_param->env = environ_;
	update_lvl();
}

int	main(int argc, char **argv, char **env)
{
	struct sigaction	control_c;
	t_list				*list_of_parses;
	char				*line;

	(void)argv, (void)argc;
	ft_memset(&control_c, 0, sizeof(control_c));
	g_param = ft_calloc(1, sizeof(t_param));
	setup_env(env), (g_param->stdin_copy = dup(0));
	sig_set(&control_c, TRUE);
	line = (char *)0xFF;
	while (line)
	{
		line = readline(RED "super " CYAN "shell " RESET "$> ");
		if (!line)
			break ;
		add_history(line);
		list_of_parses = get_command_line(&line);
		if (!list_of_parses)
			continue ;
		go_on_I_will_wait(exec(list_of_parses));
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
	}
	return (0);
}
