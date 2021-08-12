#include "minishell.h"

void	free_tabs(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*is_util_exists(char *file_path)
{
	char	*str_concat;
	char	**paths;
	int		fd;
	int		i;

	paths = ft_split(getvalue("PATH"), ':');
	if (!paths)
		return((void *)ret_perr("malloc ft_split error"));
	if (*file_path == '\\')
		ft_memmove(file_path, &file_path[1], ft_strlen(file_path));
	str_concat = ft_strdup(file_path);
	i = -1;
	fd = 0;
	if(str_concat[0] == '.' && str_concat[1] == '/')
		fd = open(str_concat, O_RDONLY);
	else
	{
		while (paths[++i])
		{
			free(str_concat);
			str_concat = ft_strjoin_free(ft_strjoin(paths[i], "/"), file_path, 1);
			fd = open(str_concat, O_RDONLY);
			if (fd > 2)
				break ;
		}
	}
	free_tabs(paths);
	if (fd < 3)
	{
		free(str_concat);
		return (NULL);
	}
	close(fd);
	return (str_concat);
}