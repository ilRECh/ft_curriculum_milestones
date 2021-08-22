#include "minishell.h"

/*\
 *
 *	heredoc analog. Takes place in the ft_rdrct func
 *
\*/
static void	whatsupdoc(int fd, char *stopword)
{
	char	*line;
	int		copy_cur_stdin;

	copy_cur_stdin = dup(0);
	dup2(0, g_param->stdin_copy);
	while (true)
	{
		line = readline("\033[2K\rwhatsupdoc?> ");
		if (line && ft_strncmp(line, stopword, ft_strlen(stopword)))
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		else if (line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	dup2(copy_cur_stdin, 0);
	close(copy_cur_stdin);
}

/*\
 *
 *		@to - char either RDCT_L, or RDCT_L2, or RDCT_R, or RDCT_R2
 *	@rdrct - structure s_rdrct, multiple meanings
 *	@file - redirect input from, or redirect output to
 *		Should this function be safe? 
 *	Should we resolve situation, when pipe returns -1?
 *	Should we resolve open -1 return?
 * 
\*/
static int	ft_rdrct(char to, t_rdrct *rdrct, t_parse *file)
{
	if ((to == RDCT_L || to == RDCT_L2)
		&& !rdrct->inall.is)
	{
		rdrct->inall.is = true;
		pipe(rdrct->inall.pipefd);
	}
	if (to == RDCT_L)
		ft_lstadd_back(&rdrct->in, (void *)((long long)open(file->argv[1], O_RDONLY)));
	else if (to == RDCT_L2)
	{
		int pipefd[2];
		pipe(pipefd);
		ft_lstadd_back(&rdrct->in, (void *)((long long)pipefd[0]));
		whatsupdoc(pipefd[1], file->argv[1]);
		close(pipefd[1]);
	}
	else if (to == RDCT_R)
		ft_lstadd_back(&rdrct->out, (void *)((long long)open(file->argv[1], O_WRONLY | O_CREAT | O_TRUNC, 00777)));
	else if (to == RDCT_R2)
		ft_lstadd_back(&rdrct->out, (void *)((long long)open(file->argv[1], O_WRONLY | O_CREAT | O_APPEND, 00777)));
	return (0);
}

/*\
 *
 *		Checking all the redirects in a lst, in a current sublst. 'Sublst' is every sublst,
 *	that starts from an and ends at an element, related to ONE single command.
 *	Braces are count as a single command.
 *		@lst -  list with all parsed commands. .cur field points either at the start, or special symbol.
 * 
\*/
static t_list	ft_all_rdrcts(t_list *lst, t_rdrct *rdrct)
{
	t_list	sublst;

	if (!rdrct->outall.is)
	{
		rdrct->outall.is = true;
		pipe(rdrct->outall.pipefd);
	}
	sublst.head = lst->cur;
	while (lst->cur && ((t_parse *)lst->cur->content)->oper != END
		&& ((t_parse *)lst->cur->content)->oper != AND
		&& ((t_parse *)lst->cur->content)->oper != OR
		&& ((t_parse *)lst->cur->content)->oper != PIPE)
	{
		if (((t_parse *)lst->cur->content)->oper == RDCT_L)
			ft_rdrct(RDCT_L, rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_L2)
			ft_rdrct(RDCT_L2, rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R)
			ft_rdrct(RDCT_R, rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R2)
			ft_rdrct(RDCT_R2, rdrct, lst->cur->content);
		lst->cur = lst->cur->next;
	}
	sublst.end = lst->cur;
	return (sublst);
}

/*\
 *
 *		Looks for either braces sublst, or command to execute.
 *	sublst->cur will point to the element with above containings at the end
 *	of the func execution.
 *
\*/
static void	find_sublst_or_command(t_list *sublst)
{
	sublst->cur = sublst->head;
	while (sublst->cur && !((t_parse *)sublst->cur->content)->argv[0])
		sublst->cur = sublst->cur->next;
}

/*\
 *
 *		read from all descriptors stored in the out list,
 *	write the read stuff to the infd descriptor. Close these descriptors.
 *	The infd descriptor will be passed to a program as input further.
 *
\*/
static void	in(t_list *in, int infd)
{
	int		rd;
	char	buf[1000];

	rd = 1;
	in->cur = in->head;
	while (in->cur)
	{
		while (rd > 0)
		{
			rd = read((int)in->cur->content, buf, 1000);
			write(infd, buf, rd);
		}
		close((int)in->cur->content);
		in->cur = in->cur->next;
		rd = 1;
	}
	ft_lstclear(in, NULL);
}

/*\
 *
 *		Fucntion for a child writer, who will read from outfd,
 *	and put everything in fds in the out list.
 *
\*/
static void	out(t_list *out, int outfd)
{
	int		rd;
	char	buf[1000];

	rd = 1;
	if (out && ft_lstsize(*out))
	{
		while (rd > 0)
		{
			out->cur = out->head;
			rd = read(outfd, buf, 1000);
			while (out->cur)
			{
				write((int)out->cur->content, buf, rd);
				out->cur = out->cur->next;
			}
		}
	}
	else
	{
		while (rd > 0)
		{
			rd = read(outfd, buf, 1000);
			write(1, buf, rd);
		}
	}
}

static int	exec_cmd(char **args, t_rdrct *rdrct)
{
	int	pid = 0;
	int	writer_pid;

	if (rdrct->inall.is)
		in(&rdrct->in, rdrct->inall.pipefd[1]);
	pid = fork();
	if (!pid)
	{
		ft_lstclear(&rdrct->in, NULL);
		ft_lstclear(&rdrct->out, NULL);
		if (rdrct->copy.is0)
			close(rdrct->copy.fd[0]);
		if (rdrct->copy.is1)
			close(rdrct->copy.fd[1]);
		if (rdrct->inall.is)
			close(rdrct->inall.pipefd[1]);
		close(rdrct->outall.pipefd[0]);
		if (rdrct->inall.is)
			dup2(rdrct->inall.pipefd[0], 0);
		dup2(rdrct->outall.pipefd[1], 1);
		execve(args[0], args, g_param->env);
	}
	else
	{
			writer_pid = fork();
			if (!writer_pid)
			{
				if (rdrct->pipe.is)
					close(rdrct->pipe.pipefd[0]);
				if (rdrct->copy.is0)
					close(rdrct->copy.fd[0]);
				if (rdrct->copy.is1)
					close(rdrct->copy.fd[1]);
				if (rdrct->inall.is)
				{
					close(rdrct->inall.pipefd[0]);
					close(rdrct->inall.pipefd[1]);
				}
				close(rdrct->outall.pipefd[1]);
				out(&rdrct->out, rdrct->outall.pipefd[0]);
				close(rdrct->outall.pipefd[0]);
				ft_lstclear(&rdrct->in, NULL);
				ft_lstclear(&rdrct->out, NULL);
				exit(0);
			}
		if (rdrct->inall.is)
		{
			close(rdrct->inall.pipefd[0]);
			close(rdrct->inall.pipefd[1]);
		}
		close(rdrct->outall.pipefd[0]);
		close(rdrct->outall.pipefd[1]);
		rdrct->outall.is = false;
		rdrct->inall.is = false;
		ft_lstclear(&rdrct->out, NULL);
		ft_lstclear(&rdrct->in, NULL);
	}
	return (pid);
}

/*\
 *
 *		Executes braces sublst alongsiede with braces sublst writer child
 *	ATTENTION! DANGEROUS FUNC! NOT YET DEBUGGED!
 *
\*/
static int	exec_braces(t_list sublst, t_rdrct *rdrct, int *exitcode)
{
	int	writer_pid;

	if (rdrct->inall.is)
		in(&rdrct->in, rdrct->inall.pipefd[1]);
	writer_pid = fork();
	if (!writer_pid)
	{
		if (rdrct->pipe.is)
			close(rdrct->pipe.pipefd[0]);
		if (rdrct->copy.is0)
			close(rdrct->copy.fd[0]);
		if (rdrct->copy.is1)
			close(rdrct->copy.fd[1]);
		if (rdrct->inall.is)
		{
			close(rdrct->inall.pipefd[0]);
			close(rdrct->inall.pipefd[1]);
		}
		close(rdrct->outall.pipefd[1]);
		out(&rdrct->out, rdrct->outall.pipefd[0]);
		close(rdrct->outall.pipefd[0]);
		ft_lstclear(&rdrct->in, NULL);
		ft_lstclear(&rdrct->out, NULL);
		exit(0);
	}
	if (rdrct->inall.is)
	{
		rdrct->copy.fd[0] = dup(0);
		rdrct->copy.is0 = true;
		dup2(rdrct->inall.pipefd[0], 0);
	}
	rdrct->copy.fd[1] = dup(1);
	rdrct->copy.is1 = true;
	dup2(rdrct->outall.pipefd[1], 1);
	if (rdrct->inall.is)
		close(rdrct->inall.pipefd[1]);
	close(rdrct->outall.pipefd[0]);
	*exitcode = exec((t_list *)((t_parse *)sublst.cur->content)->argv[1]);
	if (rdrct->inall.is)
	{
		dup2(rdrct->copy.fd[0], 0);
		close(rdrct->copy.fd[0]);
		rdrct->copy.is0 = false;
	}
	dup2(rdrct->copy.fd[1], 1);
	close(rdrct->copy.fd[1]);
	rdrct->copy.is1 = false;

		if (rdrct->inall.is)
		{
			close(rdrct->inall.pipefd[0]);
			close(rdrct->inall.pipefd[1]);
		}
		close(rdrct->outall.pipefd[0]);
		close(rdrct->outall.pipefd[1]);
		rdrct->outall.is = false;
		rdrct->inall.is = false;
		ft_lstclear(&rdrct->out, NULL);
		ft_lstclear(&rdrct->in, NULL);

	return (writer_pid);
}

/*\
 *
 *		Either executes a command, which first has to be found in the sublst,
 *	or, if occurs, calls exec on braces sublst detection.
 *
\*/
static int	exec_cmd_or_braces(t_list sublst, t_rdrct *rdrct, int *exitcode)
{
	int	pid;

	pid = 0;
	find_sublst_or_command(&sublst);
	if (sublst.cur && ((t_parse *)sublst.cur->content)->argv[0]
		&& !ft_strncmp(((t_parse *)sublst.cur->content)->argv[0], CASE, ft_strlen(CASE)))
		pid = exec_braces(sublst, rdrct, exitcode);
	else
		pid = exec_cmd(((t_parse *)sublst.cur->content)->argv, rdrct);
	return (pid);
}

/*\
 *
 *		Opens pipe if direction is true, and assigns rdrct->pipe.pipefd[1] to
 *	out list for the child writer to write. If the direction is false, then
 *	assigns rdrct->pipe values to rdrct->inall. 
 *
\*/
static int	openpipe(t_rdrct *rdrct, int direction)
{
	if (direction)
	{
		rdrct->pipe.is = true;
		pipe(rdrct->pipe.pipefd);
		ft_lstadd_back(&rdrct->out, (void *)((long long)rdrct->pipe.pipefd[1]));
	}
	else
	{
		rdrct->pipe.is = false;
		rdrct->inall.is = true;
		rdrct->inall.pipefd[0] = rdrct->pipe.pipefd[0];
		rdrct->inall.pipefd[1] = rdrct->pipe.pipefd[1];
	}
	return (0);
}

/*\
 *
 *		
 *
\*/
int	exec(t_list *lst)
{
	t_rdrct	*rdrct;
	t_list	sublst;
	int 	exitcode;
	int		pid;

	if (!lst)
		return (-1);
	pid = 0;
	exitcode = 0;
	rdrct = ft_calloc(1, sizeof(t_rdrct));
	lst->cur = lst->head;
	while (lst->cur)
	{
		sublst = ft_all_rdrcts(lst, rdrct);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, true);
		pid = exec_cmd_or_braces(sublst, rdrct, &exitcode);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == PIPE)
			openpipe(rdrct, false);
		if (lst->cur && ((t_parse *)lst->cur->content)->oper == AND)
		{
			if (pid > 0)
				waitpid(pid, &exitcode, 0);
			if (exitcode)
			{
				lst->cur = lst->cur->next;
				while (lst->cur
					&& ((t_parse *)lst->cur->content)->oper != END
					&& ((t_parse *)lst->cur->content)->oper != OR
					&& ((t_parse *)lst->cur->content)->oper != PIPE)
						lst->cur = lst->cur->next;
			}
			else
				lst->cur = lst->cur->next;
		}
		else if (lst->cur && ((t_parse *)lst->cur->content)->oper == OR)
		{
			if (pid > 0)
				waitpid(pid, &exitcode, 0);
			if (!exitcode)
			{
				lst->cur = lst->cur->next;
				while (lst->cur
					&& ((t_parse *)lst->cur->content)->oper != END
					&& ((t_parse *)lst->cur->content)->oper != AND
					&& ((t_parse *)lst->cur->content)->oper != PIPE)
						lst->cur = lst->cur->next;
			}
			else
				lst->cur = lst->cur->next;
		}
		else if (lst->cur && (((t_parse *)lst->cur->content)->oper == PIPE
			|| ((t_parse *)lst->cur->content)->oper == END))
			lst->cur = lst->cur->next;
	}
	free(rdrct);
	return (exitcode);
}
