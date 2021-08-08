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

void	test_print_tab(char **split_dots);

// 
// case 1:
//	 echo "hello world" > file1 | cat file1 && ./a.out 5 4 3 2 1 | checker 5 4 3 2 1
//

//* Удалить!
typedef struct  s_parse
{
	//  Название запускаемой утилиты
	char			*util;
	//  Аргументы для утилиты || или если утилита не задана, то это название файла
	char    		**argv;
	//	разделитель	(&& = AND), (|| == OR), (; == END) (| == PIPE)
	//	Редиректы > < >> << RDCT_R, RDCT_L, RDCT_R2, RDCT_L
	unsigned short	oper;
}   t_parse;
//* это
char	*dollar_get_env(char *line);
char	*ft_strjoin_free(char *s1, char *s2, short fr);
t_list	*get_command_line(char **line);
char	*trimmer(char *str, char c);
t_list	*split_sub_argutils(t_list *lst);

#endif