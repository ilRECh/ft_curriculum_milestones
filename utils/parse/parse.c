#include "parse.h"

// Найдет первое совпадение одного из символов в лайне,
// и вернет указатель на этот символ в лайне
char	*find_one_sym(char *symbols, char *line)
{
	int	i;

	i = 0;
	while(*line)
	{
		while(symbols[i])
		{
			if (*line == symbols[i])
				return (line);
			i++;
		}
		line++;
		i = 0;
	}
	return (0);
}

t_list	*get_command_line(char *line)
{
	t_list	*lst;
	t_parse	*prs;
	char	*tmp;

	lst = NULL;
	prs = (t_parse *)malloc(sizeof(t_parse));
	if (!prs)
	{
		/*Тут планируется ошибка для malloc*/
		return (NULL);
	}
	tmp = ft_strchr(line, ' ');


	return (lst);
}