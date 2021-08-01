#include "minishell.h"

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
	environ = setup_env(environ);

	int iter_1 = 0;

	char *vars[] = {"HI=hi", "HELLO=THERE", NULL};

	while (environ[iter_1])
		printf("%s\n", environ[iter_1++]);
	ft_export(vars);
	iter_1 = 0;
	while (environ[iter_1])
		printf("%s\n", environ[iter_1++]);	
	return (0);
}