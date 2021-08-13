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
	t_list	*list_of_parses;
	//* START TEST
	// char *str = ft_strdup("echo \"$PWD kkk00;00\" > a > b;echo \"00;00\" > a > b");
	int	fd = 0;
	char	*line;

	if (argc > 1)
	{
		fd = open((*++argv), O_RDONLY);
		if (fd < 3)
			return (ret_perr(*argv));
	}
	line = (char *)0xFF;
	if (!fd)
	{
		while (line)
		{
			line = readline("Hello -> ");
			list_of_parses = get_command_line(&line);
		}
	}
	else
		while (get_next_line(fd, &line) > 0)
			list_of_parses = get_command_line(&line);
	list_of_parses = get_command_line(&line);
	//* END TEST
	//it's show time
	// exec(list_of_parses);
	return (0);
}
