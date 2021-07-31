#ifndef PARSE_H
# define PARSE_H
// #include "minishell.h"



//* Удалить!
typedef struct  s_parse
{
	//  Название запускаемой утилиты
	char    *utils_to_run;
	//  Аргументы для утилиты
	char    *argv;
	//  was pipe ?
	_Bool   pipe;
}   t_parse;
//* это



#endif