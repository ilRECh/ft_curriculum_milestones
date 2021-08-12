#include "parse.h"

void	test_print_tab(char **split_dots)
{
	if (split_dots && *split_dots)
		while (*split_dots)
			printf(YELLOW " %s " RESET, *split_dots++);
}

char	*test_opers(unsigned short oper)
{
	if (oper == 1)
		return(ft_strdup(">"));
	if (oper == 2)
		return(ft_strdup("<"));
	if (oper == 3)
		return(ft_strdup("<<"));
	if (oper == 4)
		return(ft_strdup(">>"));
	if (oper == 5)
		return(ft_strdup(";"));
	if (oper == 6)
		return(ft_strdup("&&"));
	if (oper == 7)
		return(ft_strdup("||"));
	if (oper == 8)
		return(ft_strdup("|"));
	// if (oper == 9)
	// 	return(ft_strdup("("));
	// if (oper == 10)
	// 	return(ft_strdup(")"));
	return(ft_strdup("0"));
}

void	test_print_lst(t_list *lst, int i)
{
	t_parse	*par;

	lst->cur = lst->head;
	while (lst->cur)
	{
		par = (t_parse *)(lst->cur->content);
		if (par->util && !ft_strncmp(CASE, par->util, ft_strlen(CASE)))
		{
			printf(MAGENTA_BOLD "\n|%*s( sub_lst %d" RESET,(i) * 4, " ", i + 1);
			test_print_lst((t_list *)par->argv, i + 1);
			// printf(MAGENTA_BOLD "\n|%*s*s" RESET, (i + 1) * 4, " ", test_opers(par->oper));
			printf(MAGENTA_BOLD "\n|%*s) %s" RESET, (i) * 4, " ", test_opers(par->oper));
		}
		else
		{
			if (!par->util)
				par->util = " ";
			printf(BLUE "\n|%*s%-5s" RESET, i * 4, " ", par->util);
			test_print_tab(par->argv);
			printf(RED " %s " RESET, test_opers(par->oper));
		}
		lst->cur = lst->cur->next;
	}
}

short	is_split(char *str)
{
	if (!str || !*(str) || *(str - 1) == '\\')
		return (0);
	if (*(str - 1) == '(' && *(str - 2) != '\\')
		return (CASE_OPEN);
	if (*(str - 1) == ')' && *(str - 2) != '\\')
		return (CASE_CLOSE);
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

t_parse	*pars_gen_fill(char *util, char **argv, unsigned short oper)
{
	t_parse	*pars;

	pars = (t_parse *)malloc(sizeof(t_parse));
	if(!pars)
		return((void *)ret_perr("malloc err -> pars"));
	pars->util = util;
	pars->argv = argv;
	pars->oper = oper;
	return (pars);
}

void	skip_quotation(char **ln)
{
	if (**ln == '\"' && *(*ln - 1) != '\\')
		while (*++(*ln) != '\"' || *(*ln - 1) == '\\')
			;
	if (**ln == '\'' && *(*ln - 1) != '\\')
		while (*++(*ln) != '\'' || *(*ln - 1) == '\\')
			;
}

_Bool	skip_open_case(char **ln)
{
	int	cnt_case;

	cnt_case = 1;
	while (*++(*ln) && cnt_case)
	{
		skip_quotation(ln);
		if (**ln == ')')
			cnt_case--;
		else if (**ln == '(')
			cnt_case++;
	}
	if (cnt_case)
		return (FALSE);
	return (TRUE);
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
		skip_quotation(&ln);
		sp = is_split(++ln);
		if (!*ln || sp)
		{
			if (sp == CASE_OPEN)
			{
				pars = pars_gen_fill(ft_strdup(CASE), (char **)split_ignore_caps(ln), 0);
				skip_open_case(&ln);
				sp = 0;
				while (*ln && !sp)
					sp = is_split(++ln);
				pars->oper = sp;
				
			}
			else
				pars = pars_gen_fill(trimmer(ft_strndup(line, ln - line), " ()"), NULL, sp);
			ft_lstadd_back(lst, pars);
			if (sp == CASE_CLOSE)
				return (lst);
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

	// printf("%s\n", *line);
	printf("%s\n", *line);
	pre_parser(*line);
	printf("%s\n", *line);
	printf(CYAN "{" RESET);
	printf(MAGENTA "  lst" RESET);
	*line = dollar_get_env(*line);		//раскрываем переменную из \$
	if (!line)
		return ((void *)ret_perr("malloc err, dollar"));
	lst = split_ignore_caps(*line);			//Делим по листам (&& = AND), (|| == OR), (; == END)
	if (!lst)
		return (void *)(ret_perr("malloc err, lst"));
	lst = split_sub_argutils(lst);				//Инициализация сырых значений
	if (!lst)
		return (void *)(ret_perr("malloc err, lst_sub"));
	test_print_lst(lst, 0);						//смотрим результат
	printf(CYAN "\n}\n\n" RESET);
	printf(RESET);



	return (NULL);
}