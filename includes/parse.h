/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:51 by name              #+#    #+#             */
/*   Updated: 2021/08/12 18:52:48 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

/*open_case	*/	# define NO_UTIL	"\n\t{\nNot_util\n}\n\t"
/*open_case	*/	# define CASE		"\n\t{\ncase\n}\n\t"
/*		>	*/	# define RDCT_R		1
/*		<	*/	# define RDCT_L		2
/*		<<	*/	# define RDCT_L2	3
/*		>>	*/	# define RDCT_R2	4
/*		;	*/	# define END		5
/*		&&	*/	# define AND		6
/*		||	*/	# define OR			7
/*		|	*/	# define PIPE		8
/*		(	*/	# define CASE_OPEN	9
/*		)	*/	# define CASE_CLOSE	10

void	test_print_tab(char **split_dots);

// 
// case 1:
//	 echo "hello world" > file1 | cat file1 && ./a.out 5 4 3 2 1 | checker 5 4 3 2 1
//

//* Удалить!
typedef struct  s_parse
{
	//  имя утилиты
	char    		**argv;
	//  Аргументы для утилиты || или если утилита не задана, то это название файла
	unsigned short	oper;

//	(; | || &&)	отдельным элементом
//	(< > << >>) File1 2 3 ... отнести к файлам, а не утилитам.

	//	разделитель	(&& = AND), (|| == OR), (; == END) (| == PIPE)
	//	Редиректы > < >> << RDCT_R, RDCT_L, RDCT_R2, RDCT_L
}   t_parse;


typedef struct  s_void
{
	//  имя утилиты
	void	*data;
	int		open;
}   t_void;
//* это
char	*dollar_get_env(char *line);
char	*ft_strjoin_free(char *s1, char *s2, short fr);
t_list	*get_command_line(char **line);
char	*trimmer(char *str, char *c);
t_list	*split_sub_argutils(t_list *lst);
_Bool	ret_perr(const char *mess);
char	*is_util_exists(char *file_path);	// Существует ли утилита, во всех путях
_Bool	pre_parser(char *line);
t_parse	*pars_gen_fill(char **argv, unsigned short oper);
short	is_split(char *str);
void	skip_quotation(char **ln);
_Bool	skip_open_case(char **ln);

void	test_print_tab(char **split_dots);
char	*test_opers(unsigned short oper);
void	test_print_lst(t_list *lst, int i);

#endif