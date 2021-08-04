#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*list_of_lists;
	//* START TEST
	// char *str = ft_strdup("echo \"$PWD kkk00;00\" > a > b;echo \"00;00\" > a > b");
	char *str = ft_strdup(*++argv);	//for testing
	char	*line;
	if (argc > 1)
		list_of_lists = get_command_line(&str, env);
	else if (get_next_line(0, &line))
		list_of_lists = get_command_line(&line, env);
	//* END TEST
	return (0);
}