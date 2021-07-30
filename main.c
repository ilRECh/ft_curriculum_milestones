#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	//* START TEST
	char	*line;
	while (get_next_line(0, &line) > 0)
	{
		// Лови возвращаемое значение !!!
		// t_parse которая в листах t_list
		get_command_line(line);
	}
	//* END TEST
	return (0);
}