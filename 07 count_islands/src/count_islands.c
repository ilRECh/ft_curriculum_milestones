#include "count_islands.h"

static void	count(int height,
		int length, char index_num, t_islands *islands)
{
	if (islands->map[height][length] != 'M' ||
		!ft_isdigit(index_num))
		return ;
	islands->map[height][length] = index_num;
	count(height - 1, length, index_num, islands);
	count(height - 1, length - 1, index_num, islands);
	count(height, length - 1, index_num, islands);
	count(height + 1, length - 1, index_num, islands);
	count(height + 1, length, index_num, islands);
	count(height + 1, length + 1, index_num, islands);
	count(height, length + 1, index_num, islands);
	count(height - 1, length + 1, index_num, islands);
}

bool	count_islands(t_islands *islands)
{
	int		i;
	int		j;
	char	index_num;

	index_num = (i = 0) + '0';
	while (++i < islands->height)
	{
		j = 0;
		while (++j < islands->length)
		{
			if (islands->map[i][j] == 'M')
				count(i, j, index_num++, islands);
		}
	}
	i = 0;
	while (++i < islands->height)
	{
		islands->map[i][islands->length + 1] = '\n';
		printf("%s", islands->map[i] + 1);
	}
	i = -1;
	while (islands->map[++i])
		free(islands->map[i]);
	free(islands->map);
	return (false);
}
