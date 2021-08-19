#include "minishell.h"

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
	(void)argc;
	(void)argv;
	(void)env;
	g_param = ft_calloc(1, sizeof(t_param));
	g_param->env = setup_env(env);
	g_param->stdin_copy = dup(0);
	t_list	*list_of_parses;
	(void)list_of_parses;
	//* START TEST
	char	*line;

	line = (char *)0xFF;
	while (line)
	{
		line = readline(RED "super " CYAN "shell " RESET);
		add_history(line);
		list_of_parses = get_command_line(&line);
		//exec
	}
	return (0);
}
