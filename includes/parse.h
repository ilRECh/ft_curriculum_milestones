/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:51 by name              #+#    #+#             */
/*   Updated: 2021/08/05 23:58:52 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
#include "minishell.h"

# define RDCT_R 1
# define RDCT_L 2
# define RDCT_L2 3
# define RDCT_R2 4
# define END 1
# define AND 2
# define OR 3
# define PIPE 4

//* Удалить!
typedef struct  s_parse
{
	//  Название запускаемой утилиты
	char			*util;
	//  Аргументы для утилиты || или если утилита не задана, то это название файла
	char    		**argv;
	//	разделитель	(&& = AND), (|| == OR), (; == END)
	unsigned short	differ;
	//	Редиректы > < >> << RDCT_R, RDCT_L, RDCT_R2, RDCT_L
	unsigned short	redirect;
	//  was pipe ?
	_Bool   pipe;
}   t_parse;
//* это
char	*dollar_get_env(char *line, char **env);
char	*ft_strjoin_free(char *s1, char *s2, short fr);
t_list	*get_command_line(char **line, char **env);


#endif