/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:58:42 by name              #+#    #+#             */
/*   Updated: 2021/08/08 16:33:18 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include <dirent.h>
# include <signal.h>

typedef struct s_param
{
	char	**env;
	char	**exprt;
	char	**locals;
	int		ret;
	int		stdin_copy;
}	t_param;

//
//	@copy - 2 descriptors for copy the original main threads: stdin and stdout
// 	@pipe -> pipein - 
//	@pipeout - 
//	@inall -
//	@outall -
//   
typedef struct s_rdrct
{
	t_list		in;
	t_list		out;
	struct s_copy
	{
		bool	is0;
		bool	is1;
		int		fd[2];
	}			copy;
	struct s_pipe
	{
		bool	is;
		int		pipefd[2];
	}			pipe;
	struct s_inall
	{
		bool	is;
		int		pipefd[2];
	}			inall;
	struct s_outall
	{
		bool	is;
		int		pipefd[2];
	}			outall;
}	t_rdrct;

//
//	SINGLE LEGIT GLOBAL VARIABLE
// 
extern t_param	*g_param;

//
//	BUILTINS
//
int		ft_cd(char **args);
void	update_env(char *newpath);
int		is_way_exist(char *path);
int		is_way_exist(char *path);
int		chpath(char *newpath);
char	*oldpwd(void);
void	update_oldpwd(bool res, char *oldpath);
int		ft_echo(char **args);
int		ft_env(char **args);
int		ft_exit(char **args);
int		ft_export(char **args);
void	add_to_env(char **split);
void	add_to_exprt(char **split);
int		var_count(char **vars);
void	free_split(char **split);
int		check_var(char *var);
int		print_exp(void); //for the ft_export func
int		ft_pwd(char **args);
int		ft_unset(char **args);

//
//	ENV UTILS
// 
char	*getvalue(char *word);
char	*getval_local(char *word);
int		setvalue(char *word, char *new_value);
int		setval_local(char *word, char *new_value);
void	remove_local(char *str);
char	*getvalue_exprt(char *word);
int		setvalue_exprt(char *word, char *new_value);
void	free_tabs(char **tab);

//
//	EXECUTION
// 
int		exec(t_list *lst);
void	whatsupdoc(int fd, char *stopword);
int		ft_rdrct(char to, t_rdrct *rdrct, t_parse *file);
t_list	ft_all_rdrcts(t_list *lst, t_rdrct *rdrct);
void	find_sublst_or_command(t_list *sublst);
void	in(t_list *in, int infd);
void	out(t_list *out, int outfd);
int		openpipe(t_rdrct *rdrct, int direction);
int		exec_cmd_or_braces(t_list sublst, t_rdrct *rdrct, int *exitcode);
int		exec_cmd(char **args, t_rdrct *rdrct);
int		exec_braces(t_list sublst, t_rdrct *rdrct);
int		exec_builtin(t_list sublst, t_rdrct *rdrct, int *exitcode);
int		check_builtin(char *name);
void	ft_close(void *fd);
int		go_on_I_will_wait(int pid);
int		exec_minishell(char **argv, t_rdrct *rdrct, int *exitcode);

static inline uint8_t	error(void)
{
	printf(RED "ERROR: " RESET "%s\n", strerror(errno));
	return (1);
}

static inline uint8_t	error_str(char *str)
{
	printf(RED "ERROR: " RESET "%s", str);
	return (1);
}

#endif // MINISHELL_H
