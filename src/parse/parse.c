#include "parse.h"

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
			while (*ln && ft_strchr("<> ", *++ln))
				;
			sp_prev = sp;
			line = ln;
		}
		else if (sp > 4 && sp < 9)	// если пайпы, операторы или конец (в отдельный элементос)
		{
			if (ln != line )
				ft_lstadd_back(lst, add_data_tolst(sp_prev, line, ln));
			ft_lstadd_back(lst, pars_gen_fill((char **)NULL, sp));
			while (*ln && ft_strchr(";&| ", *++ln))
				;
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
			while (*ln && *++ln && cases)
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