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
		if (par->argv && *par->argv && !(par->oper > 4 && par->oper < 9) && !ft_strncmp(CASE, (*par->argv), ft_strlen(CASE)))
		{
			printf(MAGENTA_BOLD "\n|%*s( sub_lst %d" RESET,(i) * 4, " ", i + 1);
			test_print_lst((t_list *)par->argv[1], i + 1);
			printf(MAGENTA_BOLD "\n|%*s) %s" RESET, (i) * 4, " ", test_opers(par->oper));
		}
		else
		{
			if (!(par->oper > 4 && par->oper < 9))
			{
				printf(BLUE "\n|%*s" RESET, i * 4, " ");
				printf(RED " %s " RESET, test_opers(par->oper));
				printf(BLUE "%-5s" RESET, *(par->argv));
				test_print_tab(&(par->argv)[1]);
			}
			else
				printf(MAGENTA_BOLD "\n| %*s" RED "%s " RESET, (i + 1) * 4, " ", test_opers(par->oper));
		}
		lst->cur = lst->cur->next;
	}
}

short	is_split(char *str)
{
	if (!str || !*(str) || *(str - 1) == '\\')
		return (0);
	if (*(str) == '(' && *(str - 2) != '\\')
		return (CASE_OPEN);
	if (*(str) == ')' && *(str - 2) != '\\')
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

t_parse	*pars_gen_fill(char **argv, unsigned short oper)
{
	t_parse	*pars;

	pars = (t_parse *)malloc(sizeof(t_parse));
	if(!pars)
		exit((short)ret_perr("malloc err -> pars") + 1);
	pars->argv = (char **)malloc(sizeof(char *));
	pars->argv = argv;
	pars->oper = oper;
	return (pars);
}

void	skip_quotation(char **ln)
{
	if (**ln == '\"' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\"' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
	if (**ln == '\'' && *(*ln - 1) != '\\')
	{
		while (*++(*ln) != '\'' || *(*ln - 1) == '\\')
			;
		++(*ln);
	}
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

t_parse	*add_data_tolst(short sp_prev, char *line, char *ln)
{
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * 2);
	argv[0] = trimmer(ft_strndup(line, ln - line), " ");
	argv[1] = NULL;
	return (pars_gen_fill(argv, sp_prev));
}

t_list	*split_ignore_caps(char *line, short sp_prev)
{
	int		cases;
	char	**argv;
	t_list	*lst;
	char	*ln;
	short	sp;

	sp = 0;
	while (*line == ' ')
		line++;
	ln = line;
	lst = ft_calloc(1, sizeof(t_list));
	while (*ln)
	{
		skip_quotation(&ln);
		sp = is_split(ln);
		while (*ln && !sp)
		{
			if (ft_strchr("\"\'", *ln) && *(ln - 1) != '\\')
				skip_quotation(&ln);
			else
				ln++;
			sp = is_split(ln);
		}
		if (!*ln || (sp > 0 && sp < 5))	// если редиректы
		{
			if (ln != line )
				ft_lstadd_back(lst, add_data_tolst(sp_prev, line, ln));
			while (*++ln && ft_strchr("<> ", *ln))

			sp_prev = sp;
			line = ln;
		}
		else if (sp > 4 && sp < 9)	// если пайпы, операторы или конец (в отдельный элементос)
		{
			if (ln != line )
				ft_lstadd_back(lst, add_data_tolst(sp_prev, line, ln));
			ft_lstadd_back(lst, pars_gen_fill((char **)NULL, sp));
			while (*++ln && ft_strchr(";&| ", *ln));
			sp_prev = sp = 0;
			line = ln;
		}
		else if (sp == 9)	// если скобки, (субмассив, рекурсия) и скипнуть скобки нах для текущей операции
		{
			cases = 1;
			if (ln != line )
				ft_lstadd_back(lst, add_data_tolst(sp_prev, line, ln));
			argv = (char **)malloc(sizeof(char *) * 3);
			argv[0] = ft_strdup(CASE);
			argv[1] = (char *)split_ignore_caps(ln + 1, 0);
			argv[2] = NULL;
			ft_lstadd_back(lst, pars_gen_fill(argv, 0));
			while (*++ln && cases)
			{
				if (*ln == '(')
					cases++;
				if (*ln == ')')
					cases--;
			}
			while(*ln == ' ')
				ln++;
			sp_prev = sp;
			line = ln;
		}
		else if (sp == 10)
		{
			if (ln != line )
				ft_lstadd_back(lst, add_data_tolst(sp_prev, line, ln));
			return (lst);
		}
	}
	return (lst);
}

t_list	*get_command_line(char **line)
{
	t_list	*lst;

	// printf("%s\n", *line);
	// printf("%s\n", *line);
	if (pre_parser(*line))
		return(NULL);
	// printf("%s\n", *line);
	// printf(CYAN "{" RESET);
	// printf(MAGENTA "  lst" RESET);
	*line = dollar_get_env(*line);		//раскрываем переменную из \$
	lst = split_ignore_caps(*line, 0);			//Делим по листам (&& = AND), (|| == OR), (; == END)
	lst = split_sub_argutils(lst);				//Инициализация сырых значений
	test_print_lst(lst, 0);						//смотрим результат
	// printf(CYAN "\n}\n\n" RESET);
	printf(RESET);
	printf("\n");



	return (lst);
}