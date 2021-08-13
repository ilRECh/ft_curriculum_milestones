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
	(void)argc;
	(void)argv;
	(void)env;
	environment = setup_env(env);
	// printf("%s\n", getcwd(NULL, 0));
	// ft_cd(argv[1]);
	// printf("%s\n", getcwd(NULL, 0));





	// while (*env)
	// {
	// 	printf("%s\n", *env++);
	// }	
	t_list	*list_of_parses;
	//* START TEST
	char	*line;

	line = (char *)0xFF;
	while (line)
	{
		line = readline(RED "super " CYAN "shell " RESET "> ");
		add_history(line);
		list_of_parses = get_command_line(&line);
	}
	// line = ft_strdup("cat < filename || (echo hello > file1)");
	// list_of_parses = get_command_line(&line);
	//* END TEST
	return (0);
}
