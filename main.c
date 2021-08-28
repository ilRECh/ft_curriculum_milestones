#include "minishell.h"
int	main(int argc, char **argv, char **env);
t_param	*g_param;

static char	**setup_env(char **env)
{
	int		vars;
	int		iter_1;
	char	**environ_;

	vars = 0;
	iter_1 = 0;
	while (env[iter_1++])
		vars++;
	environ_ = (char **)ft_calloc(vars + 1, sizeof(char *));
	iter_1 = 0;
	while (env[iter_1])
	{
		environ_[iter_1] = ft_strdup(env[iter_1]);
		iter_1++;
	}
	return (environ_);
}

int	main(int argc, char **argv, char **env)
{
	struct sigaction	control_c;
	t_list	*list_of_parses;
	char	*line;
	(void)argc;
	(void)argv;

	ft_memset(&control_c, 0, sizeof(control_c));
	g_param = ft_calloc(1, sizeof(t_param));
	g_param->env = setup_env(env);
	g_param->stdin_copy = dup(0);
	g_param->locals = NULL;
	line = (char *)0xFF;
	while (line)
	{
		sig_set(&control_c, TRUE);
		line = readline(RED "super " CYAN "shell " RESET "$> ");
		if (!line)
			break ;
		add_history(line);
		list_of_parses = get_command_line(&line);
		if (!list_of_parses)
			continue ;
		sig_set(&control_c, FALSE);
		go_on_I_will_wait(exec(list_of_parses));
		rl_replace_line("", 0);
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
	}
	return (0);
}
