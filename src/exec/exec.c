#include "minishell.h"

/*\
 *
 *		Should this function be safe? 
 *	Should we resolve situation, when pipe returns -1?
 *	Should we resolve open -1 return?
 *	Don't forget to make a 'heredoc' analog here.
 *		@to - char either RDCT_L, or RDCT_L2, or RDCT_R, or RDCT_R2
 *	@rdrct - structure s_rdrct, multiple meanings
 *	@file - redirect input from, or redirect output to
 * 
\*/
int	ft_rdrct(char to, t_rdrct *rdrct, t_parse *file)
{
	if ((to == RDCT_L || to == RDCT_L2)
		&& !rdrct->inall.isrdr)
	{
		rdrct->inall.isrdr = true;
		pipe(rdrct->inall.pipefd);
	}
	if (!rdrct->outall.isrdr)
	{
		rdrct->outall.isrdr = true;
		pipe(rdrct->outall.pipefd);
	}
	if (to == RDCT_L)
		ft_lstadd_back(rdrct->in, (void *)open(file->argv[1], O_RDONLY));
	else if (to == RDCT_L2)
		(void)0; //make whatsupdoc?> here
	else if (to == RDCT_R)
		ft_lstadd_back(rdrct->out, (void *)open(file->argv[1], O_WRONLY | O_TRUNC));
	else if (to == RDCT_R2)
		ft_lstadd_back(rdrct->out, (void *)open(file->argv[1], O_WRONLY | O_APPEND));
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
t_list	ft_all_rdrcts(t_list *lst, t_rdrct **rdrct)
{
	t_list	sublst;

	*rdrct = ft_calloc(1, sizeof(t_rdrct));
	sublst.head = lst->cur;
	while (lst->cur
		&& ((t_parse *)lst->cur->content)->oper != END
		&& ((t_parse *)lst->cur->content)->oper != AND
		&& ((t_parse *)lst->cur->content)->oper != OR
		&& ((t_parse *)lst->cur->content)->oper != PIPE)
	{
		if (((t_parse *)lst->cur->content)->oper == RDCT_L)
			ft_rdrct(RDCT_L, *rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_L2)
			ft_rdrct(RDCT_L2, *rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R)
			ft_rdrct(RDCT_R, *rdrct, lst->cur->content);
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R2)
			ft_rdrct(RDCT_R2, *rdrct, lst->cur->content);
		lst->cur = lst->cur->next;
	}
	sublst.end = lst->cur;
	return (sublst);
}

int	exec(t_list *lst, int exitcode)
{
	t_list	sublst;
	t_rdrct	*rdrct;

	//sublst.end = (t_dlist *)1;
	//while (sublst.end)
	//{
		//sublst = ft_all_rdrcts(lst, &rdrct);
		// 
		/* 
		if (sublst.end)
		{
			exec_cmd(sublst, rdrct);
			if ((t_parse *)sublst.end->content)->oper == |
				rdrct out -> rdrct in
			if ((t_parse *)sublst.end->content)->oper == &&
				if okay -> then:
				output
				sublst = ft_all_rdrcts
			if ((t_parse *)sublst.end->content)->oper == ||
				if not okay -> then?
				output
				sublst = ft_all_rdrcts
			if ((t_parse *)sublst.end->content)->oper == ;
				does not mean anything, just continue
		}
	//}
		*/
	return (0);
}
//---------------------------------------------------------------
// ╭─name@name in ~/Desktop/minishell on master ✘ (origin/master)
// ╰$ ls | grep a | (echo || cat -e)  

// ╭─name@name in ~/Desktop/minishell on master ✘ (origin/master)
// ╰$ ls | grep a | (echo && cat -e)

// main.c$
// main.o$
// Makefile$
// ╭─name@name in ~/Desktop/minishell on master ✘ (origin/master)
// ╰$ ls | grep a | (echo && (echo && cat -e))


// main.c$
// main.o$
// Makefile$
// ╭─name@name in ~/Desktop/minishell on master ✘ (origin/master)
// ╰$ 
//---------------------------------------------------------------