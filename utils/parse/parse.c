#include "parse.h"
#include <stdio.h>
#include "libft.h"

/*
	' '		в этих скобках все остается неизменным, служебные символы теряют силу
	& ;		конец каждой команды... так же & отображает кол-во процессов и их pid
	" "		в этих скобках текст остается неизменным, кроме _$_ и в некоторых случаях _\_
	\		экранирование обрабатывает следующий символ после себя, делая его НЕ служебным
	$		доллар распарсивает окружение и вытаскивает оттуда некотрую переменную
	;		Разделяет команды, 1 2 3
	|		пайп, козделение команды попайпа
	< > << >> Редиректы 
*/

//			\\	\+
//			echo \s \' "hello\;" '


char	*quotation(char *line, int *i, char c)
{
	int	j;
	int	lenj;
	int	leni;

	j = (*i);
	while ((++(*i) && line[*i] != c) || (line[*i] == c && line[(*i) - 1] == '\\'))
		if (!line[(*i)])
			return (NULL);
	lenj = ft_strlen(&line[j]);
	ft_memmove(&line[j], &line[j + 1], lenj);
	leni = ft_strlen(&line[--(*i)]);
	ft_memmove(&line[(*i)], &line[(*i) + 1], leni + 1);
	return (line);
}

char	*parsing_line(char *line)
{
	int	i;

	i = -1;
	while(line[++i])
	{
		if ((i && line[i] == '\\' && (line[i + 1] == ';' || line[i + 1] == '+')))
			continue ;
		if (!((i && line[i] != '\'') || (line[i] == '\'' && line[i - 1] == '\\')))
			line = quotation(line, &i, '\'');
		if (!((i && line[i] != '\"') || (line[i] == '\"' && line[i - 1] == '\\')))
			line = quotation(line, &i, '\"');
	}
	return (NULL);
}

t_list	*get_command_line(char *line)
{
	t_parse	*parse;

	parse->argv = NULL;
	parse->pipe = FALSE;
	parse->utils_to_run = NULL;
	printf("%s\n", parsing_line(line));
	return (NULL);
}