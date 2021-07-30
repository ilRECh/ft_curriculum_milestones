#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include "libft.h"

typedef struct  s_parse
{
	//  Название запускаемой утилиты
	char    *utils_to_run;
	//  Аргументы для утилиты
	char    *argv;
	//  was pipe ?
	_Bool   pipe;
}   t_parse;

t_list	*get_command_line(char *line);

#endif