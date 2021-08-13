#include "minishell.h"

/*Do I have to check bin existing again?*/
// static void	paths_check(t_list arg, char **paths)
// {
// 	char	*tmp;
// 	char	**paths_copy;

// 	paths_copy = paths;
// 	while (paths_copy && *paths_copy)
// 	{
// 		tmp = ft_strjoin(*paths_copy++,
// 				((t_content *)arg.cur->content)->arg[0]);
// 		if (!access(tmp, X_OK))
// 		{
// 			free(((t_content *)arg.cur->content)->arg[0]);
// 			((t_content *)arg.cur->content)->arg[0] = tmp;
// 			clean_paths(paths);
// 			return ;
// 		}
// 		free(tmp);
// 	}
// 	ft_printf(RED "ERROR: %s: %s\n" RESET,
// 		((t_content *)arg.cur->content)->arg[0], strerror(errno));
// 	clean_paths(paths);
// 	ft_lstclear(&arg, clean_content);
// 	exit(1);
// }

/* I think Rasul has done it himself */
// static void	check_cmd_path(t_list arg, char **envp)
// {
// 	char	**paths;
// 	char	**paths_copy;
// 	char	*tmp;

// 	while (ft_strncmp("PATH=", *envp, 4))
// 		envp++;
// 	paths = ft_split(*envp + 5, ':');
// 	paths_copy = paths;
// 	while (paths_copy && *paths_copy)
// 	{
// 		tmp = *paths_copy;
// 		*paths_copy = ft_strjoin(*paths_copy, "/");
// 		free(tmp);
// 		paths_copy++;
// 	}
// 	paths_check(arg, paths);
// }

// static void	check_cmd_access(t_list args, char **envp)
// {
// 	args.cur = args.head->next;
// 	while (args.cur != args.end)
// 	{
// 		if (((t_content *)args.cur->content)->arg[0][0] == '/'
// 			&& access(((t_content *)args.cur->content)->arg[0], X_OK))
// 		{
// 			ft_printf(RED "ERROR: %s %s\n" RESET,
// 				((t_content *)args.cur->content)->arg[0], strerror(errno));
// 			ft_lstclear(&args, clean_content);
// 			exit(1);
// 		}
// 		else if (((t_content *)args.cur->content)->arg[0][0] != '/')
// 			check_cmd_path(args, envp);
// 		args.cur = args.cur->next;
// 	}
// }

typedef struct s_rdrct
{
	struct s_inall
	{
		bool	isrdr;
		int		pipefd[2];
	}			inall;
	struct s_outall
	{
		bool	isrdr;
		int		pipefd[2];
	}			outall;
}	t_rdrct;

int	ft_rdct(char to, t_rdrct *rdrct, t_parse *from)
{
	(void)to;
	(void)rdrct;
	(void)from;
	return (0);
}

int	exec(t_list *lst)
{
	t_rdrct	rdrct;

	rdrct.inall.isrdr = false;
	rdrct.outall.isrdr = false;
	lst->cur = lst->head;
	while (lst->curc
		&& )
	{
		if (((t_parse *)lst->cur->content)->oper == RDCT_L)
			ft_rdrct(RDCT_L, &rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_L2)
			ft_rdrct(RDCT_L2, &rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R)
			ft_rdrct(RDCT_R, &rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R2)
			ft_rdrct(RDCT_R2, &rdrct, lst->cur->content);
		lst->cur = lst->cur->next;
	}
	// exec_cmd(args, envp);
	return (0);
}
