#include "minishell.h"

char	**environment;

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
	printf("hi%d%p%p\n", argc, argv, env);
	environment = setup_env(env);
	printf("%s\n", getcwd(NULL, 0));
	printf("%s\n", getvalue("PWD"));
	ft_cd(argv[1]);
	printf("%s\n", getcwd(NULL, 0));
	printf("%s\n", getvalue("PWD"));
	ft_cd(argv[1]);
	printf("%s\n", getcwd(NULL, 0));
	printf("%s\n", getvalue("PWD"));
	
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
