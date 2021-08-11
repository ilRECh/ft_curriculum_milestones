#include "minishell.h"

t_param	*g_param = NULL;

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
	int a;
	a = 5;
	char	*env_args[] = {"/usr/bin/env", NULL};
	char	*tmp[] = {"FUCKFUCK=FUCK_YOU", NULL};
	char	*tmp_NULL[] = {NULL};
	g_param = ft_calloc(1, sizeof(t_param));
	g_param->env = setup_env(env);


	ft_export(tmp);
	ft_env(env_args);
	ft_export(tmp_NULL);
	tmp[0] = "FANTASY";
	ft_export(tmp);
	ft_env(env_args);
	ft_export(tmp_NULL);
	exit(1);
	ft_unset(tmp);
	ft_env(env_args);
	// ft_unset(argv + 2);
	// ft_env();
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
