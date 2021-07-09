#include "pipex.h"

static void	close_fds(int *fds, int amount)
{
	while (amount--)
		close(*fds++);
}

static int	create_pipes(t_list args, int **fds)
{
	int	pipefd[2];
	int fds_amount;
	int	index;

	index = 0;
	fds_amount = (ft_lstsize(args) - 2) * 2;
	*fds = ft_calloc(fds_amount, sizeof(int));
	(*fds)[0] = open(((t_content *)args.head->content)->arg[0], O_RDONLY);
	(*fds)[fds_amount - 1] = open(((t_content *)args.end->content)->arg[0],
		O_TRUNC | O_WRONLY, 0664);
	while (++index + 1 < fds_amount)
	{
		if (pipe(pipefd))
		{
			ft_printf(RED "ERROR: cannot PIPE in CREATE_PIPES\n" RESET);
			free(*fds);
			ft_lstclear(&args, clean_content);
			exit(1);
		}
		(*fds)[index] = pipefd[1];
		(*fds)[++index] = pipefd[0];
	}
	return ((fds_amount - 2) / 2);
}

static void	exec_child(t_list arg, int *fds, int index, char **envp)
{
	dup2(fds[index], 0);
	dup2(fds[index + 1], 1);
	ft_printf("%d\n", execve(((t_content *)arg.cur->content)->arg[0],
		((t_content *)arg.cur->content)->arg, envp));
}

void	exec_cmd(t_list args, char **envp)
{
	int	*fds;
	int pid;
	int	pipes;
	int	iter_1;

	iter_1 = -1;
	pipes = create_pipes(args, &fds);
	args.cur = args.head->next;
	while (iter_1++ < pipes)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_printf(RED "ERROR: cannot FORK in EXECUTE_CMD\n" RESET);
			ft_lstclear(&args, clean_content);
			close_fds(fds, pipes * 2 + 2);
			exit(1);
		}
		else if (!pid)
			exec_child(args, fds, iter_1 * 2, envp);
		args.cur = args.cur->next;
		iter_1 += 2;
		pid = fork();
		if (pid < 0)
		{
			ft_printf(RED "ERROR: cannot FORK in EXECUTE_CMD\n" RESET);
			ft_lstclear(&args, clean_content);
			close_fds(fds, pipes * 2 + 2);
			exit(1);
		}
		else if (!pid)
			exec_child(args, fds, iter_1 * 2, envp);
		exit(1);
	}
	ft_lstclear(&args, clean_content);
	close_fds(fds, pipes * 2 + 2);
}