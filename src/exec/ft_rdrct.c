/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdrct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:49 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 20:41:40 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_rdrct(char to, t_rdrct *rdrct, t_parse *file)
{
	int	pipefd[2];

	if ((to == RDCT_L || to == RDCT_L2)
		&& !rdrct->inall.is)
	{
		rdrct->inall.is = true;
		pipe(rdrct->inall.pipefd);
	}
	if (to == RDCT_L)
		ft_lstadd_back(&rdrct->in,
			(void *)((long long)open(file->argv[1], O_RDONLY)));
	else if (to == RDCT_L2)
	{
		pipe(pipefd);
		ft_lstadd_back(&rdrct->in, (void *)((long long)pipefd[0]));
		whatsupdoc(pipefd[1], file->argv[1]);
		close(pipefd[1]);
	}
	else if (to == RDCT_R)
		ft_lstadd_back(&rdrct->out, (void *)((long long)open(file->argv[1],
					O_WRONLY | O_CREAT | O_TRUNC, 00777)));
	else if (to == RDCT_R2)
		ft_lstadd_back(&rdrct->out, (void *)((long long)open(file->argv[1],
					O_WRONLY | O_CREAT | O_APPEND, 00777)));
	return (0);
}

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
