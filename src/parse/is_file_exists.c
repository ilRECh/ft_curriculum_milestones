#include "minishell.h"

void	free_tabs(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

_Bool	is_file_exists(char *str)
{
	char	*str_concat;
	char	**paths;
	int		fd;
	int		i;

	paths = ft_split(getvalue("PATH"), ':');
	if (!paths)
		return(0);	//ERR malloc
	if (*str == '\\')
		ft_memmove(str, &str[1], ft_strlen(str));
	str_concat = ft_strdup(str);
	i = -1;
	fd = 0;
	if(str_concat[0] == '.' && str_concat[1] == '/')
		fd = open(str_concat, O_RDONLY);
	else
	{
		while (paths[++i])
		{
			free(str_concat);
			str_concat = ft_strjoin_free(ft_strjoin(paths[i], "/"), str, 1);
			fd = open(str_concat, O_RDONLY);
			if (fd > 2)
				break ;
		}
	}
	free(str_concat);
	free_tabs(paths);
	if (fd < 3)
		return (FALSE);
	close(fd);
	return (TRUE);
}