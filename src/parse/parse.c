#include "parse.h"

void	test_print_tab(char **split_dots)
{
	if (split_dots && *split_dots)
		while (*split_dots)
			printf("|%s|", *split_dots++);
}

void	test_print_lst(t_list *lst)
{
	t_parse	*par;

	lst->cur = lst->head;
	while (lst->cur)
	{
		par = (t_parse *)(lst->cur->content);
		printf("|%d| ", par->oper);
		printf("|%-11s| ", par->util);
		test_print_tab(par->argv);
		lst->cur = lst->cur->next;
		printf("\n");
	}
	printf("\n");
}

short	is_split(char *str)
{
	if (!str || !*(str) || *(str - 1) == '\\')
		return (0);
	if (*(str) == *(str + 1))
	{
		if (*(str) == '&')
			return (AND);
		if (*(str) == '|')
			return(OR);
		if (*(str) == '<')
			return(RDCT_L2);
		if (*(str) == '>')
			return(RDCT_R2);
	}
	if (*(str) == ';')
		return (END);
	if(*(str) == '|')
		return (PIPE);
	if (*(str) == '<')
		return(RDCT_L);
	if (*(str) == '>')
		return(RDCT_R);
	return(FALSE);
}

t_list	*split_ignore_caps(char *line)
{
	t_list	*lst;
	t_parse	*pars;
	char	*ln;
	short	sp;

	ln = line;
	lst = ft_calloc(1, sizeof(t_list));
	while (*ln)
	{
		if (ft_strchr("\'\"", *ln))
			while (*++ln && (!ft_strchr("\'\"", *ln) || (ft_strchr("\'\"", *ln) && *(ln - 1) == '\\')))
				if (!*ln)
					return (NULL); //ERR message about open case " or '
		sp = is_split(++ln);
		if (!*ln || sp)
		{
			(pars = (t_parse *)malloc(sizeof(t_parse)))->util = trimmer(ft_strndup(line, ln - line), ' ');
			pars->oper = sp;
			ft_lstadd_back(lst, pars);
			if (pars->oper == RDCT_L2 || pars->oper == RDCT_R2 || pars->oper == AND || pars->oper == OR)
				ln++;
			line = ln + 1;
		}
	}
	return (lst);
}

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	*line = dollar_get_env(*line);		//раскрываем переменную из \$
	if (!line)
		return (NULL);
	lst = split_ignore_caps(*line);			//Делим по листам (&& = AND), (|| == OR), (; == END)
	if (!lst)
		return (NULL);
	lst = split_sub_argutils(lst);				//Инициализация сырых значений
	if (!lst)
		return (NULL);
	test_print_lst(lst);						//смотрим результат



	return (NULL);
}