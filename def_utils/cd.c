#include "minishell.h"

static int	relative(char *path)
{
	if (chdir(path) < 0 && error())
		return (1);
	return (0);
}

static int	absolute(char *path)
{
	char	*cur_path;
	int		dirs;
	int		iter_1;

	cur_path = getcwd(NULL, 0);
	if (!cur_path && error())
		return (1);
	dirs = 0;
	iter_1 = 0;
	while (cur_path[iter_1])
	{
		if (cur_path[iter_1++] == '/')
			dirs++;
	}
	dirs -= 2;
	while (dirs--)
	{
		if (chdir("..") < 0 && error())
			return (1);
	}
	if (chdir(path) < 0 && error())
		return (1);
	return (0);
}

int	ft_cd(char *path)
{
	if (path[0] == '~')
		return (absolute(++path));
	else
		return (relative(path));
}
