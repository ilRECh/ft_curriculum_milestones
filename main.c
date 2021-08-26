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

// control + c
void	ctrl_c(int signum, siginfo_t *siginfo, void *code)
{
	(void)signum;
	(void)siginfo;
	(void)code;

	g_param->ret = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1,RED "\nsuper " CYAN "shell " RESET "$> ", 35);
}
void	ctrl_c2(int signum, siginfo_t *siginfo, void *code)
{
	(void)signum;
	(void)siginfo;
	(void)code;

	exit(0);
	// g_param->ret = 130;
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}

int	main(int argc, char **argv, char **env)
{
	struct sigaction	control_c;

	ft_memset(&control_c, 0, sizeof(control_c));

	g_param = ft_calloc(1, sizeof(t_param));
	g_param->env = setup_env(env);
	g_param->stdin_copy = dup(0);
	t_list	*list_of_parses;
	(void)list_of_parses;
	(void)argv;
	(void)env;
	(void)argc;
	//* START TEST
	char	*line;

	line = (char *)0xFF;
	while (line)
	{
		sig_set(&control_c, &ctrl_c);
		line = readline(RED "super " CYAN "shell " RESET "$> ");
		if (!line)
			continue ;
		add_history(line);
		list_of_parses = get_command_line(&line);
		if (!list_of_parses)
		{
			free(line);
			continue ;
		}
		sig_set(&control_c, &ctrl_c2);
		go_on_I_will_wait(exec(list_of_parses));
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
	}
	return (0);
}
