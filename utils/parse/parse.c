#include "parse.h"
#include <stdio.h>
#include "libft.h"
// #define MAX_CMDS 128

void	test_print_tab(char **split_dots)
{
	if (split_dots && *split_dots)
		while (*split_dots)
			printf("res = \"%s\"\n", *split_dots++);
}

void	test_print_lst(t_list *lst)
{
	lst->cur = lst->head;
	while (lst->end)
	{
		printf("res = \"%s\"\n", ((t_parse *)lst->cur->content)->util);
		lst->cur = lst->cur->next;
	}
}
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

char	*quotation(char *ln, char c)
{
	int	lenj;
	int	leni;
	int	k;

	k = 0;
	while ((ln[++k] != c) || (ln[k] == c && ln[k - 1] == '\\'))
		if (!ln[k])
			return (NULL); //ERR message about open case " or '
	lenj = ft_strlen(ln);
	ft_memmove(ln, &ln[1], lenj);
	leni = ft_strlen(&ln[--k]);
	ft_memmove(&ln[k], &ln[k + 1], leni + 1);
	return (&ln[k]);
}

short	is_split(char *str)
{
	unsigned short	iter;

	iter = 0;
	if (*str == ';')
		return(END);
	while (iter < 2 && str[iter] == "&&"[iter])
		iter++;
	if(iter == 2)
		return(AND);
	else
		iter = 0;
	while (iter < 2 && str[iter] == "||"[iter])
		iter++;
	if(iter == 2)
		return(OR);
	if(*str == '|')
		return (PIPE);
	return(FALSE);
	
}

t_list	*split_ignore_caps(char *line)
{
	t_list	*lst;
	t_parse	*pars;
	char	*ln;
	short	sp;

	ln = line;
	ft_lst_init(1, lst);
	while (*ln)
	{
		if (ft_strchr("\'\"", *ln))
		{
			while (*++ln && (!ft_strchr("\'\"", *ln) || (ft_strchr("\'\"", *ln) && *(ln - 1) != '\\')))
				if (!*ln)
					return (NULL); //ERR message about open case " or '
		}
		else
			ln++;
		sp = is_split(ln);
		if (!*ln || sp)
		{
			pars = (t_parse *)malloc(sizeof(t_parse));
			pars->util = (char *)malloc(sizeof(char) * (ln - line + 2));
			pars->differ = sp;
			ft_strlcpy(pars->util, line, ln - line + 1);
			ft_lstadd_back(lst, pars);
			line = ln + 1;
		}
	}
	return (lst);
}

		// if (*ln == '\'' && (!iter || ln[iter - 1] != '\\'))
		// 	ln = quotation(ln, '\'');
		// else if (*ln == '\"' && (!iter || ln[iter - 1] != '\\'))
		// 	ln = quotation(ln, '\"');

t_list	*get_command_line(char **line, char **env)
{
	// t_parse	*parse;
	t_list	*lst;
	// char	**split_dots;

	*line = dollar_get_env(*line, env);		//раскрываем переменную из \$
	
	lst = split_ignore_caps(*line);			//Делим по листам (&& = AND), (|| == OR), (; == END)
	// test_print_tab(split_dots);			//смотрим результат
	test_print_lst(lst);					//смотрим результат



	return (NULL);
}