#include "parse.h"
#include "libft.h"

/*
	(& ;) конец каждой команды... так же & отображает кол-во процессов и их pid
	"" в этих скобках текст остается неизменным, кроме _$_ и в некоторых случаях _\_
	'' в этих скобках все остается неизменным, служебные символы теряют силу
	\ экранирование обрабатывает следующий символ после себя, делая его НЕ служебным
	$ доллар распарсивает окружение и вытаскивает оттуда некотрую переменную
	; Разделяет команды, 1 2 3
	| пайп, козделение команды попайпа
	< > << >> Редиректы 
*/

_Bool	preparse(char *str)
{
	int	i;

	i = 0;	
	if (str[i] == ';')
		return (FALSE);
	while(str[i])
	{
		while (ft_strchr(" ", str[i]))
			i++;
	}
}

int	split_len(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		i++;
	return (i);
}

int	split_assign_tree(char ***res, char ***tab, char c)
{
	int	i;

	i = -1;
	while(tab[0][++i])
	{
		res[i] = ft_split(tab[0][i], c);
		free(tab[0][i]);
	}
	free(*tab);
	res[i] = (*tab = NULL);
	return (0);
}
char	***get_command_line(char *line)
{
	t_list	*lst = NULL;
	t_parse	*prs = NULL;
	char	***res;
	char	**tab;
	int		tablen;

	tab = ft_split(line, ';');
	tablen = split_len(tab);
	res = (char ***)malloc(sizeof(char **) * (tablen + 1));
	res[tablen] = NULL;
	split_assign_tree(res, &tab, ' ');



	return (NULL);
}