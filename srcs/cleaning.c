#include "pipex.h"

void	clean_content(void *content)
{
	char **arg;

	arg = ((t_content *)content)->arg;
	while (arg && *arg)
		free(*arg++);
	free(((t_content *)content)->arg);
	free(content);
}

void	clean_paths(char **paths)
{
	char	**paths_copy;

	paths_copy = paths;
	while (paths_copy && *paths_copy)
		free(*paths_copy++);
	free(paths);
}
