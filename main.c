#include "minishell.h"

char	**g_env;

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
	g_env = setup_env(env);
	
	ft_export(argv + 1);
	ft_env();
	// t_list	*list_of_lists;
	// //* START TEST
	// // char *str = ft_strdup("echo \"$PWD kkk00;00\" > a > b;echo \"00;00\" > a > b");
	// char *str = ft_strdup(*++argv);	//for testing
	// char	*line;
	// if (argc > 1)
	// 	list_of_lists = get_command_line(&str, env);
	// else if (get_next_line(0, &line))
	// 	list_of_lists = get_command_line(&line, env);
	//* END TEST
	return (0);
}
