/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:51 by name              #+#    #+#             */
/*   Updated: 2021/08/29 21:37:22 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
# define PARSE_H
# include "minishell.h"
# include "readline.h"
# include "history.h"

# define NO_UTIL	"\n\t{\nNot_util\n}\n\t"
# define CASE		"\n\t{\ncase\n}\n\t"
# define RDCT_R		1
# define RDCT_L		2
# define RDCT_L2	3
# define RDCT_R2	4
# define END		5
# define AND		6
# define OR			7
# define PIPE		8
# define CASE_OPEN	9
# define CASE_CLOSE	10

typedef struct s_parse
{
	char			**argv;
	unsigned short	oper;
}	t_parse;

typedef struct s_wheel
{
	t_list	*lst;
	char	*line;
	char	*ln;
	short	sp_prev;
	short	sp;
}	t_wheel;


void			ctrl_c(int signum, siginfo_t *siginfo, void *code);
void			ctrl_c2(int signum, siginfo_t *siginfo, void *code);
t_list			*check_line_lst(t_list *lst);
void			sig_set(struct sigaction *action,
					void (*f)(int, siginfo_t *, void *));
unsigned int	dollr(t_parse *parse);
char			*dollar_get_env(char *line);
char			*ft_strjoin_free(char *s1, char *s2, short fr);
t_list			*get_command_line(char **line);
char			*trimmer(char *str, char *c);
t_list			*split_args(t_list *lst);
_Bool			sub_sub_quote(char *str, int *i);
int				ft_strlenspace(char *str);
void			free_parse(void *p);
_Bool			ret_perr(const char *mess);
char			*is_util_exists(char *file_path);
_Bool			is_builtins(char *str);
_Bool			pre_parser(char *line);
char			*slash_parse(char *str);
_Bool			post_parser(t_list *lst);
t_parse			*pars_gen_fill(char **argv, unsigned short oper);
short			is_split(char *str);
int				skip_quote(char *str, int *k, char quote);
void			skip_quotation(char **ln);
_Bool			skip_open_case(char **ln);
void			case_skip(char **ln);
char			**argv_fill_1(char *str1);
char			**argv_fill_2(char *str1, char *str2);
void			get_next_sp(char **ln, short *sp);
t_list			*split_ignore_caps(char *line, short sp_prev);
char			**list_to_char2(t_list *lst);
void			test_print_tab(char **split_dots);
char			*test_opers(unsigned short oper);
void			test_print_lst(t_list *lst, int i);

#endif