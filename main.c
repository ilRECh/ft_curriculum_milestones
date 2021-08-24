#include "minishell.h"
#include "signal.h"

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
	printf("\n" RED "super " CYAN "shell " RESET "$> ");
	// execve("minishell", NULL, g_param->env);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
// control + c
	struct sigaction	control_c;
	// struct sigaction	control_d;

	ft_memset(&control_c, 0, sizeof(control_c));
	// ft_memset(&control_d, 0, sizeof(control_d));
	control_c.sa_sigaction = ctrl_c;
	// control_d.sa_sigaction = ctrl_d;
	control_c.sa_flags = SA_SIGINFO;
	// control_d.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &control_c, NULL);
	// sigaction(????, &control_d, NULL);
// control + c; end

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
		line = readline(RED "super " CYAN "shell " RESET "$> ");
		if (!line)
			continue ;
		add_history(line);
		list_of_parses = get_command_line(&line);
		// exec
		exec(list_of_parses);
		while (wait(NULL) >= 0)
			;
		if (list_of_parses)
			ft_lstclear(list_of_parses, free_parse);
		free(list_of_parses);
	}
	return (0);
}
