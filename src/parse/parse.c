#include "parse.h"

void	test_print_tab(char **split_dots)
{
	if (split_dots && *split_dots)
		while (*split_dots)
			printf("%s\n", *split_dots++);
}

void	test_print_lst(t_list *lst)
{
	t_parse	*pr;

	lst->cur = lst->head;
	while (lst->cur)
	{
		printf("%s\n", ((t_parse *)(lst->cur->content))->util);
		lst->cur = lst->cur->next;
	}
}

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
	lst = ft_calloc(1, sizeof(t_list));
	while (*ln)
	{
		if (ft_strchr("\'\"", *ln))
		{
			while (*++ln && 
				(!ft_strchr("\'\"", *ln) || (ft_strchr("\'\"", *ln) && *(ln - 1) == '\\')))
					if (!*ln)
						return (NULL); //ERR message about open case " or '
		}
		ln++;
		sp = is_split(ln);
		if (!*ln || sp)
		{
			pars = (t_parse *)malloc(sizeof(t_parse));
			pars->util = ft_strndup(line, ln - line);
			pars->differ = sp;
			ft_lstadd_back(lst, pars);
			line = ln + 1;
		}
	}
	return (lst);
}

t_list	*get_command_line(char **line, char **env)
{
	t_list	*lst;

	*line = dollar_get_env(*line, env);		//раскрываем переменную из \$
	lst = split_ignore_caps(*line);			//Делим по листам (&& = AND), (|| == OR), (; == END)
	test_print_lst(lst);					//смотрим результат



	return (NULL);
}