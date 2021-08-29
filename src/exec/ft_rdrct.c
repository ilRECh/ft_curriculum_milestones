/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdrct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:49 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 22:47:39 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//
//		@to - char either RDCT_L, or RDCT_L2, or RDCT_R, or RDCT_R2
//	@rdrct - structure s_rdrct, multiple meanings
//	@file - redirect input from, or redirect output to
//

int	ft_rdrct(char to, t_rdrct *rdrct, t_parse *file)
{
	int			pipefd[2];
	long long	openfd;

	if ((to == RDCT_L || to == RDCT_L2)
		&& !rdrct->inall.is)
	{
		rdrct->inall.is = true;
		pipe(rdrct->inall.pipefd);
	}
	if (to == RDCT_L)
	{
		openfd = (long long)open(file->argv[1], O_RDONLY);
		if (openfd > 0)
			ft_lstadd_back(&rdrct->in, (void *)openfd);
		else if (error_str("no such file or dir"), printf("%s\n", file->argv[1]))
			return (1);
	}
	else if (to == RDCT_L2)
	{
		pipe(pipefd);
		ft_lstadd_back(&rdrct->in, (void *)((long long)pipefd[0]));
		whatsupdoc(pipefd[1], file->argv[1]);
		close(pipefd[1]);
	}
	else if (to == RDCT_R)
	{
		openfd = (long long)open(file->argv[1],
				O_WRONLY | O_CREAT | O_TRUNC, 00777);
		if (openfd > 0)
			ft_lstadd_back(&rdrct->out, (void *)openfd);
		else if (error_str("no such file or dir"), printf("%s\n", file->argv[1]))
			return (1);
	}
	else if (to == RDCT_R2)
	{
		openfd = (long long)open(file->argv[1],
					O_WRONLY | O_CREAT | O_APPEND, 00777);
		if (openfd > 0)
			ft_lstadd_back(&rdrct->out, (void *)openfd);
		else if (error_str("no such file"), printf("%s\n", file->argv[1]))
			return (1);
	}
	return (0);
}

//
//		Checking all the redirects in a lst,
//			in a current sublst. 'Sublst' is every sublst,
//	that starts from an and ends at an element, related to ONE single command.
//	Braces are count as a single command.
//		@lst -  list with all parsed commands.
//			cur field points either at the start, or special symbol.
//

t_list	ft_all_rdrcts(t_list *lst, t_rdrct *rdrct)
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
		{
			if (ft_rdrct(RDCT_L, rdrct, lst->cur->content))
			{
				sublst.head = NULL;
				sublst.cur = NULL;
				sublst.end = NULL;
				return (sublst);
			}
		}
		else if (((t_parse *)lst->cur->content)->oper == RDCT_L2)
		{
			if (ft_rdrct(RDCT_L2, rdrct, lst->cur->content))
			{
				sublst.head = NULL;
				sublst.cur = NULL;
				sublst.end = NULL;
				return (sublst);
			}
		}
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R)
		{
			if (ft_rdrct(RDCT_R, rdrct, lst->cur->content))
			{
				sublst.head = NULL;
				sublst.cur = NULL;
				sublst.end = NULL;
				return (sublst);
			}
		}
		else if (((t_parse *)lst->cur->content)->oper == RDCT_R2)
		{
			if (ft_rdrct(RDCT_R2, rdrct, lst->cur->content))
			{
				sublst.head = NULL;
				sublst.cur = NULL;
				sublst.end = NULL;
				return (sublst);
			}
		}
		lst->cur = lst->cur->next;
	}
	sublst.end = lst->cur;
	return (sublst);
}
