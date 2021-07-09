#include "pipex.h"

static void	paths_check(t_list arg, char **paths)
{
	char	*tmp;
	char	**paths_copy;

	paths_copy = paths;
	while (paths_copy && *paths_copy)
	{
		tmp = ft_strjoin(*paths_copy++, ((t_content *)arg.cur->content)->arg[0]);
		if (!access(tmp, X_OK))
		{
			((t_content *)arg.cur->content)->arg[0] = ft_strdup(tmp);
			clean_paths(paths);
			return ;
		}
	}
	ft_printf(RED "ERROR: %s: %s\n" RESET,
		((t_content *)arg.cur->content)->arg[0], strerror(errno));
	clean_paths(paths);
	ft_lstclear(&arg, clean_content);
	exit(1);
}

static void	check_cmd_path(t_list arg, char **envp)
{
	char	**paths;
	char	**paths_copy;
	char	*tmp;

	while (ft_strncmp("PATH=", *envp, 4))
		envp++;
	paths_copy = paths = ft_split(*envp + 5, ':');
	while (paths_copy && *paths_copy)
	{
		tmp = *paths_copy;
		*paths_copy = ft_strjoin(*paths_copy, "/");
		free(tmp);
		paths_copy++;
	}
	paths_check(arg, paths);
}

static void	check_cmd_access(t_list args, char **envp)
{
	args.cur = args.head->next;
	while (args.cur != args.end)
	{
		if (((t_content *)args.cur->content)->arg[0][0] == '/'
			&& access(((t_content *)args.cur->content)->arg[0], X_OK))
		{
			ft_printf(RED "ERROR: %s %s\n" RESET,
				((t_content *)args.cur->content)->arg[0], strerror(errno));
			ft_lstclear(&args, clean_content);
			exit(1);
		}
		else if (((t_content *)args.cur->content)->arg[0][0] != '/')
			check_cmd_path(args, envp);
		args.cur = args.cur->next;
	}
}

static void	check_file_access(t_list args)
{
	if (access(((t_content *)args.head->content)->arg[0], R_OK))
	{
		ft_printf(RED "ERROR: %s: %s\n" RESET,
			((t_content *)args.head->content)->arg[0], strerror(errno));
		ft_lstclear(&args, clean_content);
		exit(1);
	}
	if (access(((t_content *)args.end->content)->arg[0], W_OK))
	{
		ft_printf(RED "ERROR: %s: %s\n" RESET,
			((t_content *)args.end->content)->arg[0], strerror(errno));
		ft_lstclear(&args, clean_content);
		exit(1);
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	t_list		args;
	t_content	*cont;

	if (argc - 4 > 1024 && write(1, RED "ERROR: TOO MANY CMDS\n" RESET, 33))
		exit(1);
	ft_lst_init(1, &args);
	while (--argc)
	{
		cont = ft_calloc(1, sizeof(t_content));
		if (!cont && write(1, RED "ERROR: PIPEX CONT\n" RESET, 29))
			exit(1);
		cont->arg = ft_split(argv[argc], ' ');
		ft_lstadd_front(&args, cont);
	}
	check_file_access(args);
	check_cmd_access(args, envp);
	exec_cmd(args, envp);
}
