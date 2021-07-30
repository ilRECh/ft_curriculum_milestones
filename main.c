#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	//* START TEST
	char	*line;
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	//* END TEST
	return (0);
}