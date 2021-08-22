#include "parse.h"

void	free_parse(void *p)
{
	t_parse	*parse;
	int	i;

	i = 0;
	parse = (t_parse *)p;
	if (parse->argv)
	{
		if (parse->argv[i] && !ft_strncmp(parse->argv[i], CASE, ft_strlen(CASE)))
				ft_lstclear((t_list *)parse->argv[1], free_parse);
		else
		{
			if (parse->argv[i])
				free(parse->argv[i]);
			while(parse->argv[++i])
				free(parse->argv[i]);
			free(parse->argv);
		}
	}
	free(parse);
}